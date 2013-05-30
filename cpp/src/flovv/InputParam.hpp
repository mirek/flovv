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

#ifndef __FLOVV_INPUT_PARAM_HPP__
#define __FLOVV_INPUT_PARAM_HPP__ 1

#include <boost/any.hpp>

#include <flovv/Param.hpp>
#include <flovv/type/Any.hpp>

namespace flovv {

    /// Represents input parameter of a node. @see NodeInput.
    ///
    class InputParam : public Param {
    public:
        
        /// Create new input parameter with specified type and initial value.
        ///
        /// @param typeName
        /// @param initialValue
        ///
        InputParam (const std::string &typeName = std::string(), const type::Any &initialValue = type::Any()) : Param(typeName, initialValue)
        {
        }
    };
    
}

#endif
