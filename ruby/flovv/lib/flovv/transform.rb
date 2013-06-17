require 'json'

module Flovv
  
  class Transform

    def self.shared
      @shared ||= Transform.new
    end

    def none(value)
      value
    end

    def to_json(value)
      JSON.dump(value)
    end

  end

end
