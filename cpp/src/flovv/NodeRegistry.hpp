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

#ifndef __FLOVV_NODE_REGISTRY_HPP__
#define __FLOVV_NODE_REGISTRY_HPP__ 1

//#include <flovv/Node.hpp>
#include <flovv/type/Numeric.hpp>

#include <flovv/Node.hpp>
#include <flovv/node/Sine.hpp>
#include <flovv/node/Random.hpp>
#include <flovv/node/Printer.hpp>
#include <flovv/node/FrameSignal.hpp>
#include <flovv/node/Math.hpp>

namespace flovv {

    typedef std::function<Node *(void)> NodeFactoryFunction;

    template <typename T>
    Node *
    newNode (void) {
        return new T();
    }

    /**
     * Node registry holds information on node types, descriptions etc.
     *
     * Each registered node gives registry ability to query information on this node type,
     * instantiate object of the node.
     */
    class NodeRegistry {
        
        type::UInt64 mNextNodeId = 0;
        
        std::map<std::string, NodeFactoryFunction> mNodeFactoryFunctions;

    public:
        
        NodeRegistry () {
            registerNodeType("Random", newNode<node::Random>);
            registerNodeType("Printer", newNode<node::Printer>);
            registerNodeType("Sine", newNode<node::Sine>);
            registerNodeType("Math", newNode<node::Math>);
//            registerNodeType("FrameSignal", newNode<node::FrameSignal>);
        }
        
        void
        registerNodeType (const std::string &name, NodeFactoryFunction function) {
            mNodeFactoryFunctions[name] = function;
        }
        
        bool
        nodeTypeRegistered (const std::string &name) const {
            return mNodeFactoryFunctions.find(name) != mNodeFactoryFunctions.cend();
        }
        
        Node *
        createNode (const std::string &name) {
            return mNodeFactoryFunctions.at(name)();
        }
    };
}

#endif
