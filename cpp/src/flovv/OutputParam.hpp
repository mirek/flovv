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

#ifndef __FLOVV_OUTPUT_HPP__
#define __FLOVV_OUTPUT_HPP__

#include <iostream>
#include <vector>
#include <boost/any.hpp>
#include <boost/lexical_cast.hpp>

#include <flovv/TypeRegistry.hpp>
#include <flovv/Param.hpp>

namespace flovv
{

    /// Output parameter, in addition to InputParam, holds a list
    /// of destinations which are assigned when value is changed.
    ///
    class OutputParam : public Param
    {
        typedef std::pair<Param &, TypeConvertionFunction> Destination;
        
        std::vector<Destination> mDestinations;
        
    public:
        
        ///
        OutputParam (const std::string &typeName = std::string(), const boost::any &value = boost::any()) : Param(typeName, value)
        {
        }
        
        ///
        ///
        template <typename T>
        bool
        store (const T &v, const TypeConvertionFunction &function = typeConvertionDirectAssignment) {
            return store(static_cast<const boost::any &>(v), function);
        }
        
        /// Store value in this output parameter using specified convertion function.
        ///
        /// @return True on success, false otherwise.
        ///
        virtual bool
        store (const boost::any &value, const TypeConvertionFunction &function) {

            // First store the value...
            bool result = Param::store(value, function);
            
            // ...and propagate to all registered destinations.
            for (auto &destination : mDestinations) {
                result = destination.first.store(mValue, destination.second) ? result : false;
            }
            
            return result;
        }
        
        /// @return True if destination has been already registered, false otherwise.
        ///
        bool
        destinationRegistered (const Param &destination) const {
            bool result = false;
            for (const auto &registeredDestination : mDestinations) {
                if (&registeredDestination.first == &destination) {
                    result = true;
                    break;
                }
            }
            return result;
        }

        /// @param destination Please note can't be const as we're propagating value to all destinations when changed.
        /// @return True on success, false otherwise.
        ///
        bool
        registerDestination (Param &destination, const TypeConvertionFunction &function, bool performStore = true) {
            bool result = false;
            if (!destinationRegistered(destination)) {
                mDestinations.push_back({destination, function});
                
                // Update destinations' value if requested (yes as default).
                if (performStore) {
                    result = destination.store(mValue, function);
                } else {
                    result = true;
                }
            }
            return result;
        }
    };
}

#endif
