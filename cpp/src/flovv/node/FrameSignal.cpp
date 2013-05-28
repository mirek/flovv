
#include <flovv/node/FrameSignal.hpp>

namespace flovv { namespace node
{
    FrameSignal::FrameSignal () : Node(ExecutionMode::Producer, TimeMode::Linear)
    {
        registerOutput<type::UInt64>("Output", "UInt64", mOutput = 0);
    }

    void
    FrameSignal::operator() ()
    {
        storeOutput<type::UInt64>("Output", mOutput++);
    }
} }