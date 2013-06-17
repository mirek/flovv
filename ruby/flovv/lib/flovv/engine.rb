require 'flovv/document'

module Flovv

  class Engine

    attr_accessor :document
    attr_accessor :node_types

    attr_accessor :at
    attr_accessor :frame

    attr_accessor :state
    attr_accessor :fps

    attr_accessor :started_at

    attr_accessor :stop_after_frame
    attr_accessor :stop_after

    def initialize(options = {})
      @node_types = options[:node_types]
      @fps = 30
      @state = :running

      @stop_after = nil
      @stop_after_frame = nil

      @document = nil
      document_set options[:document] || Document.new
    end

    def add_node(*args)

      # Engine#document_did_add_node callback will be called on success.
      @document.add_node(*args)
    end

    # Ie. #connect_with_pairs([:frame_1, :Output], [:stdout_1, :Input])
    def connect(source_pair, destination_pair)

      # On successful addition #document_did_add_connection will be called.
      @document.connect(source_pair, destination_pair)
    end

    def frame_timespan
      1000.0 / @fps
    end

    def advance
    end

    def start
      @started_at = Time.now.to_f
      loop do

        # Update frame and stop if necessary.
        if (@frame += 1) > @stop_after_frame
          @state = :stop
        end

        # Update running timestamp and stop if necessary.
        if (@at > Time.now.to_f - @started_at)
          @state = :stop
        end

        case @state
        when :running
          advance
          
        when :stop
          break
        end
      end
    end

    protected

    def document_unset
      if @document
        document_unregister_callbacks
      end
      @document = nil
    end

    def document_set(document)
      document_unset
      @document = document

      # TODO FIXME
      @document.each_node do |node|
        @nodes[node.node_id, node]
      end

      @document.each_connection do |source_pair, destination_pair|
        document_did_add_connection source_pair, destination_pair
      end

      document_register_callbacks
    end

    def document_register_callbacks
      @document.register_callback \
        :did_add_connection, method(:document_did_add_connection)
      @document.register_callback \
        :did_remove_connection, method(:document_did_remove_connection)
    end

    def document_unregister_callbacks
      @document.unregister_callback \
        :did_add_connection, method(:document_did_add_connection)
      @document.unregister_callback \
        :did_remove_connection, method(:document_did_remove_connection)
    end

    # Called by document when connection has been successfully added.
    def document_did_add_connection(source_pair, destination_pair)
      source = node(source_pair.first).output(source_pair.last)
      destination = node(destination_pair.first).input(destination_pair.last)

      # Bind them so changes are cascaded there.
      source.add_destination(destination)
    end

    # Called by document when connection has been successfully removed.
    def document_did_remove_connection(source_pair, destination_pair)
      source = node(source_pair.first).output(source_pair.last)
      destination = node(destination_pair.first).input(destination_pair.last)

      # Unbind existing connection.
      source.remove_destination(destination)
    end

  end

end
