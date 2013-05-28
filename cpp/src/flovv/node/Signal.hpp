//
// The MIT License
//
// Copyright (c) 2012 - 2013, Mirek Rusin <mirek [at] me [dot] com>
// http://flovv.org
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//

#ifndef __FLOVV_NODE_SIGNAL_HPP__
#define __FLOVV_NODE_SIGNAL_HPP__ 1

#include <flovv/Node.hpp>
#include <flovv/type/Numeric.hpp>
#include <flovv/Param.hpp>
#include <flovv/Engine.hpp>

namespace flovv { namespace node {
    
//    class Engine;
//    class Param;
//
//    class SignalTimer {
//    public:
//        
//    };
//    
//    /**
//     * Signal generates change (increments output) Increment it's output
//     */
//    class Signal : public Node {
//        
////        enum class SignalType : UInt8 {
////            SignalTypeFrame,
////            SignalTypeSecond
////        };
//        
////        type::UInt8 mType;
//        
//        std::weak_ptr<Engine> mEngine;
//        
//        // Every time signal is generated, we'll increment this param.
//        //
//        // Every time param has been changed it's transfered to the output
//        // during this node execution.
//        Param<type::UInt64> mSignal;
//        
//        type::Double mEvery;
//        type::UInt64 mOutput;
//        
//    public:
//        
//        Signal () : Node(ExecutionMode::Producer, TimeMode::Linear) {
////            registerParam<type::Double>("SignalType", "UInt8", mType = SignalTypeFrame);
//            registerInput<type::Double>("Every", "Double", mEvery = 2.0);
//            registerOutput<type::UInt64>("Output", "UInt64", mOutput = 0);
//        }
//        
//        void
//        setEngine (const std::weak_ptr<Engine> &value) {
//            mEngine = value;
//        }
//        
//        virtual void
//        start ()
//        {
////            engine->registerTimer();
//        }
//        
//        virtual void
//        stop () {
////            engine->unregisterTimer();
//        }
//        
//        virtual void
//        operator ()() {
//            if (mSignal.hasChanged()) {
//                storeOutput<type::UInt64>("Output", mSignal.load<type::UInt64>());
//            }
//        };
//    };
    
} }

#endif
