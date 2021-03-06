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

#ifndef __FLOVV_NODE_OUTPUT_HPP__
#define __FLOVV_NODE_OUTPUT_HPP__ 1

#include <flovv/NodeParamNamePair.hpp>

namespace flovv
{
    
    /**
     * Represents Node and Output pair. We're using this pair because Param
     *
     * Together with NodeInput can represent a binding.
     */
    class NodeOutput : public NodeParamNamePair
    {

    public:

        /// @param node
        /// @param outputName
        ///
        NodeOutput (Node &node, const std::string &outputName = "Output");

        /// @return Node reference for this node/output name pair.
        ///
        Node &
        getNode () const;

        const std::string &
        getOutputName () const;
        
        /**
         *
         */
        OutputParam &
        getOutput () const;
        
        /**
         *
         */
        const std::string &
        getTypeName () const;

        friend std::ostream &
        operator<< (std::ostream &o, const NodeOutput &self)
        {
            return o << self.getNode().getNodeId();
//            "typeName=\"" << self.mTypeName << "\" " <<
//            "stores=" << self.mStores << "\", " <<
//            "loads=" << self.mLoads << "\", " <<
//            "lastLoadAtStore=" << self.mLastLoadAtStore << "\" />";
        }
    };
}

#endif
