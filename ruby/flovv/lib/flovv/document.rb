module Flovv
  class Document

    attr_accessor :next_node_id

    attr_accessor :nodes
    attr_accessor :connections

    attr_accessor :callbacks

    def initialize(options = {})
      @next_node_id = 1
      @nodes = {}
      @connections = {}

      # Redundant, not persisted. We're keeping it around to have quick access
      # to info on incomming connections.
      @incomming = {}

      @callbacks = {
        did_add_connection: [],
        did_remove_connection: []
      }
    end

    def node(node_id)
      @nodes[node_id]
    end

    def add_node(type, options = {})
      @nodes[]
    end

    def each_node(parent_node_id = nil)
      # @nodes.each do |node_id, node|
        # yield node_id, node
        # node.nodes.each do 
      # end
    end

    def each_connection
      @connections.each do |source_pair, destination_pairs|
        destination_pairs.each do |destination_pair|
          yield source_pair, destination_pair
        end
      end
    end

    def connected?(source_pair, destination_pair)
      @incomming[destination_pair] == source_pair
    end

    def incomming_connection(destination_pair)
      @incomming[destination_pair]
    end

    def outgoing_connections(source_pair)
      @connections[source_pair] || []
    end

    def add_connection(source_pair, destination_pair)

      # If this connection doesn't exist...
      unless connected?(source_pair, destination_pair)

        # We can have only single incomming connection so remove anything
        # that exists now.
        remove_connection \
          incomming_connection(destination_pair),
          destination_pair

        add_incomming_connection destination_pair, source_pair
        add_outgoing_connection source_pair, destination_pair

        @callbacks[:did_add_connection].each do |callback|
          callback.call(source_pair, destination_pair)
        end
      end
    end

    def remove_connection(source_pair, destination_pair)
      if existing_source_pair = incomming_connection(destination_pair)
        if existing_source_pair == source_pair
          remove_incomming_connection destination_pair
          remove_outgoing_connection source_pair, destination_pair
          @callbacks[:did_remove_connection].each do |callback|
            callback.call(source_pair, destination_pair)
          end
        end
      end
    end

    def register_callback(name, callable)
      @callbacks[name] << callable
    end

    def unregister_callback(name, callable)
      @callbacks[name].delete callable
    end

    protected

    def add_incomming_connection(destination_pair, source_pair)
      @incomming[destination_pair] = source_pair
    end

    def remove_incomming_connection(destination_pair)
      @incomming.delete(destination_pair)
    end

    def remove_outgoing_connection(source_pair, destination_pair)
      if @connections[source_pair]
        @connections[source_pair].delete(destination_pair)
      end
    end

    def add_outgoing_connection(source_pair, destination_pair)
      (@connections[source_pair] ||= []) << destination_pair
    end
  end
end
