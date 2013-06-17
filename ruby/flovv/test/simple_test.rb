require 'test_helper'

Flovv::Engine.new.tap do |engine|
  # [engine << :Frame, engine << :StdOut].tap do |frame, stdout|
  #   engine << [frame, stdout]
  # end
  frame_node = engine.add_node :Frame
  stdout_node = engine.add_node :StdOut
  engine.connect [frame_node.node_id, :Output], [stdout_node.node_id, :Input]
  engine.stop_after_frame 10
  engine.start
end
