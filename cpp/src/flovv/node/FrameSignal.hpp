//
// Released under the MIT License.
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

#ifndef __FLOVV_NODE_FRAME_SIGNAL_HPP__
#define __FLOVV_NODE_FRAME_SIGNAL_HPP__ 1

#include <flovv/Node.hpp>
#include <flovv/type/Numeric.hpp>
#include <flovv/Engine.hpp>

namespace flovv { namespace node {
    
    // TODO: version
    namespace v0_0_1 {
        
    }
    
    class Engine;
    
    class EngineAccessible {
    protected:
        
        std::weak_ptr<Engine> mEngine;
        
    public:
        
        std::weak_ptr<Engine>
        getEngine() const
        {
            return mEngine;
        }
        
        void
        setEngine (const std::weak_ptr<Engine> &value)
        {
            mEngine = value;
        }
    };
    
    class FrameSignal : public Node, public EngineAccessible
    {
        type::UInt64 mOutput;
        std::weak_ptr<Engine> mEngine;

    public:
        
//        static struct NodeFactory
//        factory () {
//            return {
//                .name = "FrameSignal",
//                .version = {
//                    .major = 0,
//                    .minor = 1
//                }
//                .factory = nodeSharedPtrFactory<FrameSignal>
//            }
//        }
        
        FrameSignal ();

        virtual void
        operator() ();
    };
    
} }

#endif
