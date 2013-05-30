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

#ifndef __FLOVV_DOCUMENT_HPP__
#define __FLOVV_DOCUMENT_HPP__ 1

#include <boost/lexical_cast.hpp>
#include <sqlite3.h>

namespace flovv
{
    
    /**
     * On-disk or in-memory composition.
     */
    class Document
    {
        
        /**
         * All nodes have unique ids in the document scope.
         */
        std::uint64_t mNextNodeId = 0;
        
        /**
         * Mapping from node identifiers to node objects.
         */
        std::map<std::string, NodePtr> mNodes;
        
    protected:
        
        /**
         * @return Node id name in format "id:name" format, ie. "1:random".
         */
        std::string
        nextNodeIdName (const std::string &name)
        {
            return boost::lexical_cast<std::string>(mNextNodeId++) + ":" + name;
        }

    public:
        
        /// Connects node output with node input.
        ///
        /// @returns True on success, false otherwise.
        ///
//        bool
//        connect (const NodeOutput &nodeOutput, const NodeInput &nodeInput) {
//            return mBackend.connect(nodeOutput.node().name(), nodeOutput.);
//        }

        /// Add node to the document.
        ///
        /// @param node
        /// @return Node identifier or NodeIdNone on failure.
        ///
        NodeId
        addNode (const NodePtr &node)
        {
            NodeId result = NodeIdNone;
            if (node) {
                if (node->getNodeId() != NodeIdNone) {
                    
                    // Get next node id...
                    result = nextNodeIdName(node->getTypeName());
                    
                    // ...insert...
                    mNodes.insert({result, node});
                    
                    // ...and update node id.
                    node->setNodeId(result);
                }
            }
            return result;
        }
        
        /**
         * Get node by node id.
         *
         * @param nodeId Node 
         * @return Node reference
         */
        Node &
        getNode (const NodeId &nodeId)
        {
            return *mNodes.at(nodeId);
        }
        
        /**
         * Get node pointer by node id.
         *
         * @param nodeId Node
         * @return Node reference
         */
        NodePtr
        getNodePtr (const NodeId &nodeId)
        {
            return mNodes.at(nodeId);
        }
    };
}

#endif
