
#include <flovv/node/FrameSignal.hpp>

namespace flovv { namespace node
{
    FrameSignal::FrameSignal () : Node(ExecutionMode::Producer, TimeMode::Linear)
    {
        registerOutput<UInt64>("Output", mOutput = 0);
    }

    void
    FrameSignal::operator() ()
    {
        storeOutput<type::UInt64>("Output", mOutput++);
    }
} }