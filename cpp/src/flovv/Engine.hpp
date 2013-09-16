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

#ifndef __FLOVV_ENGINE_HPP__
#define __FLOVV_ENGINE_HPP__ 1

#include <vector>
#include <map>
#include <set>
#include <functional>
#include <typeinfo>
#include <boost/any.hpp>

#include <ev++.h>

#include <flovv/TypeRegistry.hpp>
#include <flovv/NodeRegistry.hpp>
#include <flovv/Document.hpp>
#include <flovv/NodeInput.hpp>
#include <flovv/NodeOutput.hpp>

#include <flovv/node/Signal.hpp>

namespace flovv
{
    
    class Ev {
        
        ev::default_loop mLoop;
        ev::io mIo;
        
        std::uint64_t mNextTimerId = 0;
        std::map<std::uint64_t, ev::timer> mTimers;
        
    protected:

        type::Double
        getCurrentTimestamp ()
        {
            return (type::Double) mLoop.now();
        }

//        std::uint64_t
//        registerTimer (bool isRepeating, std::double interval, std::function<void()> callback)
//        {
//            std::uint64_t
//            mTimers[].set<Timer, &Timer::timeout_cb>(this);
//            mTimers[0].start(0.,5);
//            ev::timer()
//            mLoop.
//        }

        void
        unregisterTimer ()
        {
//            mTimer.
        }

        void
        run ()
        {
            mLoop.run(0);
        }
    };

    /**
     * State for the execution engine including type and node registry, current frame etc.
     */
    class Engine : public Ev
    {
        type::UInt64 mFrame = 0;
        type::Double mStartedAt = 0.0;

        TypeRegistry mTypeRegistry;
        NodeRegistry mNodeRegistry;
        Document mDocument;

    protected:

    public:
        
        Engine (const Document &document)
        {
            mDocument = document;
        }
        
        Engine (const std::string &documentName = ":memory:")
        {
        }

        /**
         * Create node instance based on registered factory function.
         *
         * @return NodePtr
         */
        Node *
        createNode (const std::string &name);

        /**
         * Create connection between node output and another node's input.
         *
         * @return True on success, false otherwise.
         */
        bool
        connect (const NodeOutput &source, const NodeInput &destination);

        /**
         *
         */
        Node *
        getNodePtr (const NodeId &nodeId);

        void
        update ();

        void
        update (type::UInt64 frame, type::Double at);
        
        /**
         */
        type::UInt64
        getFrame ();
        
//        type::Double
//        getCurrentDuration () {
//            return getCurrentTimestamp() - mStartedAt;
//        }
    };
}

#endif
