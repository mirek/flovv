module Flovv
  class Output < Param
    attr_accessor :destinations
    
    def initialize(options = {})
      super
    end

    def store(value, f = transform.method(:none))
      super
      @destinations.each do |destination|
        destination.store(value, f)
      end
    end

    def add_destination(destination)
      @destinations << destination
    end

  end
end
