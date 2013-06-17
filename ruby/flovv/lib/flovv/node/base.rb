require 'execution_mode'
require 'time_mode'

module Flovv
  module Node
    class Base

      attr_accessor :engine
      attr_accessor :time_mode
      attr_accessor :execution_mode
      attr_accessor :node_id
      attr_accessor :type

      attr_accessor :params
      attr_accessor :inputs
      attr_accessor :outputs

      def initialize(options = {})
        @engine = options[:engine]
        @execution_mode = options[:execution_mode] || ExecutionMode::Unknown
        @time_mode = options[:time_mode] || TimeMode::Unknown
        @params = {}
        @inputs = {}
        @outputs = {}
      end

      def add_param(key, param)
        @params[key] = param
      end

      def remove_param(key)
        @params.delete(key)
      end

      def add_input(key, input)
        @inputs[key] = input
      end

      def remove_input(key)
        @inputs.delete(key)
      end

      def add_output(key, type, value)
        @outputs[key] = Output.new(
          node: self,
          type: type,
          value: value
        )
      end

      def remove_output(key)
        @outputs.delete(key)
      end

      def input_changed?(key = :Input)
        @inputs[key].changed?
      end

    end
  end
end
