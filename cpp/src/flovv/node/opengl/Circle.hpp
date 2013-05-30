//
// http://www.floVv.org - floVv engine
//
// Released under the MIT License.
//
// Copyright (c) 2012-2013, Mirek Rusin <mirek [at] me [dot] com>
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

#ifndef __FLOVV_NODE_OPENGL_CIRCLE_HPP__
#define __FLOVV_NODE_OPENGL_CIRCLE_HPP__ 1

#include <flovv/Node.hpp>

#include <cinder/cinder.hpp>
#include <gl.h>

namespace flovv { namespace node namespace { opengl {
    
    /// Draw circle.
    ///
    class Circle : public Node, public OpenGLNode {

    public:

        Circle () : Node(ExecutionMode::Consumer) {
            registerInput ("Enabled",  "Boolean", type::Boolean(true));
            registerInput ("Center",   "Point3D", type::Point3D(0.0, 0.0, 0.0));
            registerInput ("Radius",   "Double",  type::Double(0.1));
            registerInput ("Segments", "UInt16",  type::UInt16(0));
        }
        
//        virtual bool
//        enable () {
//        }
//        
//        virtual bool
//        disable () {
//        }

        virtual void
        operator ()()
        {
            glBegin();
            glEnd();
        };
    };
    
} }

#endif
