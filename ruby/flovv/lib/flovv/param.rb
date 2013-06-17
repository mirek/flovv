require 'flovv/transform'

module Flovv

  class Param
    attr_accessor :stores
    attr_accessor :loads
    attr_accessor :last_load_at_store
    attr_accessor :value_type
    attr_accessor :value

    def initialize(options = {})
      @transform = Transform.shared
      @stores = 1
      @loads = 0
      @last_load_at_store = 0
      @value_type = options[:type] || :Any
      @value = options[:value]
    end

    def store(value, f = @transform.method(:none))
      @stores += 1
      @value = f.call(value)
    end

    # Load value optionally using convertion function.
    def load(f = @transform.method(:none))
      @loads += 1
      @last_load_at_store = @stores
      peek(f)
    end

    def peek(f = @transform.method(:none))
      f.call(@value)
    end

    # Return true if value has been stored since last load.
    def changed?
      @last_load_at_store != @stores
    end

    def to_s()
      peek(@transform.method(:to_json))
    end
  end
end
