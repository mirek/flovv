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

#ifndef __FLOVV_PARAM_BINDER_HPP__
#define __FLOVV_PARAM_BINDER_HPP__ 1

#include <vector>

#include "param.hpp"

namespace Flovv {
    
    class Param;
    
    /// TODO: Obsolete, remove?
    ///
    class ParamBinder {
        
    public:
        
        std::vector<std::reference_wrapper<Param>> mDestinations;
        
        Connection (const Param &source, Param &destinations...) : mSource(source) {
        }

        /**
         * @param destination Destination parameter
         */
        void addDestination(const Param &destination) {
            mDestinations.push_back(destination);
        }
        
        /**
         *
         */
        void removeDestination(const Param &destination) {
            mDestinations.remove(destination);
        }

    };
    
}

#endif