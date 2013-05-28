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

#include <flovv/Engine.hpp>

namespace flovv
{
    NodePtr
    Engine::createNode (const std::string &name)
    {
        NodePtr result = nullptr;
        if (mNodeRegistry.nodeTypeRegistered(name)) {
            result = mNodeRegistry.createNode(name);
            if (result) {
                mDocument.addNode(result);
            }
        } else {
            throw "node type name not registered " + name;
        }
        return result;
    }
    
    bool
    Engine::connect (const NodeOutput &source, const NodeInput &destination)
    {
        bool result = false;
        
        // Get convertion function between connected points (or direct
        // assignment for the same types).
        auto typeConvertionFunction = mTypeRegistry.typeConvertionFunction({source.typeName(), destination.typeName()});
        if (typeConvertionFunction) {
            
            result = source.output().registerDestination(destination.input(), typeConvertionFunction);
        } else {
            
            // TODO: Log/throw convertion function not available.
        }
        
        return result;
    }
    
    type::UInt64
    Engine::getFrame () {
        return mFrame;
    }

    NodePtr
    Engine::getNodePtr (const NodeId &nodeId)
    {
        return mDocument.getNodePtr(nodeId);
    }

    void
    Engine::update ()
    {
        update(++mFrame, getCurrentTimestamp());
    }
    
    void
    Engine::update (type::UInt64 frame, type::Double at)
    {
//        mFrame = frame;
//        mAt = at;
        //        mVisitor.visit();
    }
}
