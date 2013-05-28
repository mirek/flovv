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

#ifndef __FLOVV_NUMERIC_HPP__
#define __FLOVV_NUMERIC_HPP__ 1

#include <boost/any.hpp>

namespace flovv { namespace type {

    typedef std::nullptr_t Null;
    typedef bool Boolean;
    typedef std::int8_t Int8;
    typedef std::uint8_t UInt8;
    typedef std::int16_t Int16;
    typedef std::uint16_t UInt16;
    typedef std::int32_t Int32;
    typedef std::uint32_t UInt32;
    typedef std::int64_t Int64;
    typedef std::uint64_t UInt64;
    typedef float Float;
    typedef double Double;
    typedef boost::any Any;

	enum class NumericType {
		Null,
		Boolean,
		Int8,
		UInt8,
		Int16,
		UInt16,
		Int32,
		UInt32,
		Int64,
		UInt64,
		Float,
		Double
	};

    class Numeric {

    public:

        Any mValue = Any();

        Numeric() {
        }
        
        const Numeric &operator=(const Boolean &value) {
        	mValue = value;
        	return *this;
        }

//        const Numeric &operator=(const Boolean &value) {
//        	mValue = value;
//        	return *this;
//        }

        enum NumericType numericType() {
        	enum NumericType result = NumericType::Null;
        	if (mValue.type() == typeid(Boolean)) {
        		result = NumericType::Boolean;
        	} else if (mValue.type() == typeid(Int8)) {
        		result = NumericType::Int8;
        	} else if (mValue.type() == typeid(UInt8)) {
        		result = NumericType::UInt8;
        	} else if (mValue.type() == typeid(Int16)) {
        		result = NumericType::Int16;
        	} else if (mValue.type() == typeid(UInt16)) {
        		result = NumericType::UInt16;
        	} else if (mValue.type() == typeid(Int32)) {
        		result = NumericType::Int32;
        	} else if (mValue.type() == typeid(UInt32)) {
        		result = NumericType::UInt32;
        	} else if (mValue.type() == typeid(Int64)) {
        		result = NumericType::Int64;
        	} else if (mValue.type() == typeid(UInt64)) {
        		result = NumericType::UInt64;
        	} else if (mValue.type() == typeid(Float)) {
        		result = NumericType::Float;
        	} else if (mValue.type() == typeid(Double)) {
        		result = NumericType::Double;
        	}
            return result;
        }
        
        static Numeric add(const Numeric &a, const Numeric &b);
        static Numeric sub(const Numeric &a, const Numeric &b);
        static Numeric mul(const Numeric &a, const Numeric &b);
        static Numeric div(const Numeric &a, const Numeric &b);
        static Numeric pow(const Numeric &a, const Numeric &b);
        static Numeric mod(const Numeric &a, const Numeric &b);
        static Numeric min(const Numeric &a, const Numeric &b);
        static Numeric max(const Numeric &a, const Numeric &b);
    };

} }

#endif
