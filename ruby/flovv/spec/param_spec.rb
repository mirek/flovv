require 'spec_helper'

module Flovv
  describe Param do

    context ':String value type' do

      let(:param) {
        Flovv::Param.new('Hello World!', type: :String)
      }

      specify {
        param.changed?.should be_true
      }

      specify {
        param.peek.should eql('Hello World!')
      }

      specify {
        param.peek
        param.changed?.should be_true
      }

      specify {
        param.load.should eql('Hello World!')
      }

      specify {
        param.load
        param.changed?.should be_false
      }

      context 'store new value' do

        before { 
          param.store 'Hello you!'
        }

        specify {
          param.changed?.should be_true
        }

        specify {
          param.load.should eql('Hello you!')
        }

        specify {
          param.load
          param.changed?.should be_false
        }
      end
    end
  end
end
