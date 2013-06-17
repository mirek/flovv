require 'flovv/node/base'

module Flovv
  module Node
    class UnaryMath < Base

      OPS = {
        :Sin => lambda { |a| Math.sin(a) },
        :Cos => lambda { |a| Math.cos(b) }
      }

      attr_accessor :op

      def initialize(options = {})
        super options.merge(
          execution_mode: ExecutionMode::Processor,
          time_mode: TimeMode::None
        )
        add_param(:Operation, :String, :Sin); @op = OPS[:Sin]
        add_input :Input, :Double, 0.0
        add_output :Output, :Int64, 0.0
      end

      def call
        if input_changed?(:A)
          store_output @op.call(load_input)
        end
        true
      end
    end
  end
end
