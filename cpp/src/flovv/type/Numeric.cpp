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

#include <flovv/type/Numeric.hpp>

namespace flovv { namespace type {

    Numeric::Op<Numeric::Add> Numeric::addOp;
    Numeric::Op<Numeric::Sub> Numeric::subOp;
    Numeric::Op<Numeric::Mul> Numeric::mulOp;
    Numeric::Op<Numeric::Div> Numeric::divOp;
    Numeric::Op<Numeric::Mod> Numeric::modOp;
    Numeric::Op<Numeric::Pow> Numeric::powOp;
    Numeric::Op<Numeric::Min> Numeric::minOp;
    Numeric::Op<Numeric::Max> Numeric::maxOp;

    std::string
    typeName (const Numeric &value) {
             if (value.type() == typeid(Boolean)) return "Numeric.Boolean";
        else if (value.type() == typeid(Int8))    return "Numeric.Int8";
        else if (value.type() == typeid(UInt8))   return "Numeric.UInt8";
        else if (value.type() == typeid(Int16))   return "Numeric.Int16";
        else if (value.type() == typeid(UInt16))  return "Numeric.UInt16";
        else                                      return "Numeric.Null";
    }

    template <> std::string typeName<Boolean> () { return "Boolean"; }
    template <> std::string typeName<Int8>    () { return "Int8"; }
    template <> std::string typeName<UInt8>   () { return "UInt8"; }
    template <> std::string typeName<Int16>   () { return "Int16"; }
    template <> std::string typeName<UInt16>  () { return "UInt16"; }
    template <> std::string typeName<Int32>   () { return "Int32"; }
    template <> std::string typeName<UInt32>  () { return "UInt32"; }
    template <> std::string typeName<Int64>   () { return "Int64"; }
    template <> std::string typeName<UInt64>  () { return "UInt64"; }
    template <> std::string typeName<Float>   () { return "Float"; }
    template <> std::string typeName<Double>  () { return "Double"; }

    Numeric
    Numeric::operator+ (const Numeric &value) const {
        return std::move(Numeric::addOp(*this, value));
    }

    Numeric
    Numeric::operator- (const Numeric &value) const {
        return std::move(Numeric::subOp(*this, value));
    }

    Numeric
    Numeric::operator* (const Numeric &value) const {
        return std::move(Numeric::mulOp(*this, value));
    }

    Numeric
    Numeric::operator/ (const Numeric &value) const {
        return std::move(Numeric::divOp(*this, value));
    }

    Numeric
    Numeric::operator% (const Numeric &value) const {
        return std::move(Numeric::modOp(*this, value));
    }

    Numeric
    Numeric::pow (const Numeric &value) const {
        return std::move(Numeric::powOp(*this, value));
    }

    Numeric
    Numeric::min (const Numeric &value) const {
        return std::move(Numeric::minOp(*this, value));
    }

    Numeric
    Numeric::max (const Numeric &value) const {
        return std::move(Numeric::maxOp(*this, value));
    }



//    enum NumericType
//    Numeric::numericType () const {
//        enum NumericType result = NumericType::Null;
//        if (mValue.type() == typeid(Boolean)) {
//            result = NumericType::Boolean;
//        } else if (mValue.type() == typeid(Int8)) {
//            result = NumericType::Int8;
//        } else if (mValue.type() == typeid(UInt8)) {
//            result = NumericType::UInt8;
//        } else if (mValue.type() == typeid(Int16)) {
//            result = NumericType::Int16;
//        } else if (mValue.type() == typeid(UInt16)) {
//            result = NumericType::UInt16;
//        } else if (mValue.type() == typeid(Int32)) {
//            result = NumericType::Int32;
//        } else if (mValue.type() == typeid(UInt32)) {
//            result = NumericType::UInt32;
//        } else if (mValue.type() == typeid(Int64)) {
//            result = NumericType::Int64;
//        } else if (mValue.type() == typeid(UInt64)) {
//            result = NumericType::UInt64;
//        } else if (mValue.type() == typeid(Float)) {
//            result = NumericType::Float;
//        } else if (mValue.type() == typeid(Double)) {
//            result = NumericType::Double;
//        }
//        return result;
//    }

//    int
//    Numeric::numericTypeIndex () const {
//        if      (mValue.type() == typeid(Boolean)) return 1;
//        else if (mValue.type() == typeid(Int8))    return 2;
//        else if (mValue.type() == typeid(UInt8))   return 3;
//        else if (mValue.type() == typeid(Int16))   return 4;
//        else if (mValue.type() == typeid(UInt16))  return 5;
//        else if (mValue.type() == typeid(Int32))   return 6;
//        else if (mValue.type() == typeid(UInt32))  return 7;
//        else if (mValue.type() == typeid(Int64))   return 8;
//        else if (mValue.type() == typeid(UInt64))  return 9;
//        else if (mValue.type() == typeid(Float))   return 10;
//        else if (mValue.type() == typeid(Double))  return 11;
//        else return 0;
//    }

} }