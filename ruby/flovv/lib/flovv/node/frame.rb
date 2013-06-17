require 'flovv/node/base'

module Flovv
  module Node
    class Frame < Base
      def initialize(options = {})
        super options.merge(
          execution_mode: ExecutionMode::Producer,
          time_mode: TimeMode::None
        )
        add_output :Output, :UInt64, 0
      end
      
      def call
        store_output engine.frame
        true
      end
    end
  end
end
