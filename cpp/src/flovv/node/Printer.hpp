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

#ifndef __FLOVV_NODE_PRINTER_HPP__
#define __FLOVV_NODE_PRINTER_HPP__ 1

#include <iostream>
#include <boost/any.hpp>

namespace flovv { namespace node {
    
    class Printer : public Node {
        
    public:
        
        Printer() : Node(ExecutionMode::Consumer, TimeMode::None) {
            setExecutionMode(ExecutionMode::Consumer);
            registerInput("Enabled", "Boolean", type::Boolean(true));
            registerInput("Input", "String", type::String("Hello World!"));
        }
        
        virtual void operator()() {
            if (hasInputChanged()) {
                std::cout << loadInput<type::String>() << std::endl;
            }
        };
        
    };

} }

#endif
