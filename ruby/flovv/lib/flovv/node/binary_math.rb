require 'flovv/node/base'

module Flovv
  module Node
    class BinaryMath < Base

      OPS = {
        :+   => lambda { |a, b| a + b },
        :-   => lambda { |a, b| a - b },
        :*   => lambda { |a, b| a * b },
        :/   => lambda { |a, b| a / b },
        :%   => lambda { |a, b| a % b },
        :Pow => lambda { |a, b| a ** b },
        :Min => lambda { |a, b| [a, b].min },
        :Max => lambda { |a, b| [a, b].max }
      }

      attr_accessor :op

      def initialize(options = {})
        super options.merge(
          execution_mode: ExecutionMode::Processor,
          time_mode: TimeMode::None
        )
        add_param(:Operation, :String, :+); @op = OPS[:+]
        add_input :A, :Int64, 0
        add_input :B, :Int64, 0
        add_output :Output, :Int64, 0
      end
      
      def call
        if any_input_changed?(:A, :B)
          store_output @op.call(load_input(:A), load_input(:B))
        end
        true
      end
    end
  end
end
