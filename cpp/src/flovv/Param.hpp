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

#ifndef __FLOVV_PARAM_HPP__
#define __FLOVV_PARAM_HPP__ 1

#include <string>
#include <boost/any.hpp>
#include <boost/format.hpp>

#include <flovv/type/Any.hpp>
#include <flovv/type/Numeric.hpp>
#include <flovv/TypeRegistry.hpp>
#include <flovv/error/TypeMismatch.hpp>

namespace flovv
{

    /**
     */
    class Param
    {
        
    protected:
        
        type::UInt64 mStores = 1;
        type::UInt64 mLoads = 0;
        type::UInt64 mLastLoadAtStore = 0;
        type::String mTypeName;
        type::Any mValue = type::Any();
        
    public:
        
        Param (const std::string &typeName = std::string(), const type::Any &value = type::Any()) : mTypeName(typeName), mValue(value)
        {
        }
        
        ///
        ///
        const std::string &
        getTypeName () const
        {
            return mTypeName;
        }
        
        /// Helper template for:
        ///
        ///    engine.node(random).input("Min").store<type::Int64>(5)
        ///
        /// Otherwise ...store(int64_t(5)) needs to be used to guarantee
        /// proper value type.
        ///
        template <typename T>
        bool
        store (const T &v, const TypeConvertionFunction &function = typeConvertionDirectAssignment)
        {
            return store(static_cast<const type::Any &>(v), function);
        }
        
        /// Please note this method is virtual in order to allow override from
        /// output class specialization - which propagates assignment to all
        /// destinations.
        ///
        /// If this method fails, param's value is set to null.
        ///
        /// @return True on success, false otherwise (usually type convertion failure).
        ///
        virtual bool
        store (const type::Any &value, const TypeConvertionFunction &function = typeConvertionDirectAssignment)
        {
            bool result = function(value, mValue);
            if (result) {
                ++mStores;
            } else {
                
                // There was a problem, leave it as nil.
                mValue = type::Any();
            }
            return result;
        }

        template <typename T>
        T
        load (const TypeConvertionFunction &function = typeConvertionDirectAssignment, T onError = T())
        {
            type::Any any;
            load();
            if (function(mValue, any)) {
                return boost::any_cast<T>(any);
            } else {
                return onError;
            }
        }

        /// Unlike store method, load is optimised, non-virtual.
        ///
        /// @return
        ///
        const type::Any &
        load ()
        {
            ++mLoads;
            mLastLoadAtStore = mStores;
            return mValue;
        }
        
        /**
         * Peek at the value without updating load counters.
         *
         * @return Currently held value reference.
         */
        const type::Any &
        peek () const
        {
            return mValue;
        }
        
        /// @return True if the value has been stored after last load, false otherwise.
        ///
        bool
        hasChanged () const
        {
            return mLastLoadAtStore != mStores;
        }
        
        friend std::ostream &
        operator<< (std::ostream &o, const Param &self)
        {
            return o << "<flovv::Param " <<
                "typeName=\"" << self.mTypeName << "\" " <<
                "stores=" << self.mStores << "\", " <<
                "loads=" << self.mLoads << "\", " <<
                "lastLoadAtStore=" << self.mLastLoadAtStore << "\" />";
        }
    };
}

#endif
