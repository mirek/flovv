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

#ifndef __FLOVV_NUMERIC_HPP__
#define __FLOVV_NUMERIC_HPP__ 1

#include <boost/functional.hpp>
#include <ostream>
#include <cmath>

#include <flovv/type/Any.hpp>
#include <string>

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

    template <typename T>
    std::string
    typeName () {
        return "Any";
    }

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

    class Numeric : public Any {

        template <typename T1, typename T2>
        struct Add {
            Numeric
            operator() (const Numeric &a, const Numeric &b) {
                return std::move(boost::any_cast<T1>(a) + boost::any_cast<T2>(b));
            }
        };

        template <typename T1, typename T2>
        struct Sub {
            Numeric
            operator() (const Numeric &a, const Numeric &b) {
                return std::move(boost::any_cast<T1>(a) - boost::any_cast<T2>(b));
            }
        };

        template <typename T1, typename T2>
        struct Mul {
            Numeric
            operator() (const Numeric &a, const Numeric &b) {
                return std::move(boost::any_cast<T1>(a) * boost::any_cast<T2>(b));
            }
        };

        template <typename T1, typename T2>
        struct Div {
            Numeric
            operator() (const Numeric &a, const Numeric &b) {
                return std::move(boost::any_cast<T1>(a) / boost::any_cast<T2>(b));
            }
        };

        template <typename T1, typename T2>
        class Mod {

            Numeric
            _ (const boost::any &a, const Numeric &b, std::true_type IsIntegralT1, std::true_type IsIntegralT2) const {
                return std::move(boost::any_cast<T1>(a) % boost::any_cast<T2>(b));
            }

            template <typename IsIntegralT1, typename IsIntegralT2>
            Numeric
            _ (const Numeric &a, const Numeric &b, IsIntegralT1, IsIntegralT2) const {
                return std::move(std::fmod(boost::any_cast<T1>(a), boost::any_cast<T2>(b)));
            }

        public:

            Numeric
            operator() (const Numeric &a, const Numeric &b) {
                return std::move(_(a, b, std::is_integral<T1>(), std::is_integral<T2>()));
            }
        };

        template <typename T1, typename T2>
        struct Pow {
            Numeric
            operator() (const Numeric &a, const Numeric &b) {
                return std::move(boost::any_cast<T1>(a) / boost::any_cast<T2>(b));
            }
        };

        template <typename T1, typename T2>
        struct Min {
            Numeric
            operator() (const Numeric &a, const Numeric &b) {
                return std::move(boost::any_cast<T1>(a) / boost::any_cast<T2>(b));
            }
        };

        template <typename T1, typename T2>
        struct Max {
            Numeric
            operator() (const Numeric &a, const Numeric &b) {
                return std::move(boost::any_cast<T1>(a) / boost::any_cast<T2>(b));
            }
        };

        template < template<typename, typename> class OP, typename T>
        struct OpsL {
            Numeric
            operator() (const Numeric &a, const Numeric &b) {
                     if (b.type() == typeid(Boolean)) return OP<T, Boolean>()(a, b);
                else if (b.type() == typeid(Int8))    return OP<T, Int8>()(a, b);
                else if (b.type() == typeid(UInt8))   return OP<T, UInt8>()(a, b);
                else if (b.type() == typeid(Int16))   return OP<T, Int16>()(a, b);
                else if (b.type() == typeid(UInt16))  return OP<T, UInt16>()(a, b);
                else if (b.type() == typeid(Int32))   return OP<T, Int32>()(a, b);
                else if (b.type() == typeid(UInt32))  return OP<T, UInt32>()(a, b);
                else if (b.type() == typeid(Int64))   return OP<T, Int64>()(a, b);
                else if (b.type() == typeid(UInt64))  return OP<T, UInt64>()(a, b);
                else if (b.type() == typeid(Float))   return OP<T, Float>()(a, b);
                else if (b.type() == typeid(Double))  return OP<T, Double>()(a, b);
                else                                  return Numeric();
            }
        };

        template < template<typename, typename> class OP>
        struct Op {
            Numeric
            virtual operator() (const Numeric &a, const Numeric &b) {
                     if (a.type() == typeid(Boolean)) return OpsL<OP, Boolean>()(a, b);
                else if (a.type() == typeid(Int8))    return OpsL<OP, Int8>()(a, b);
                else if (a.type() == typeid(UInt8))   return OpsL<OP, UInt8>()(a, b);
                else if (a.type() == typeid(Int16))   return OpsL<OP, Int16>()(a, b);
                else if (a.type() == typeid(UInt16))  return OpsL<OP, UInt16>()(a, b);
                else if (a.type() == typeid(Int32))   return OpsL<OP, Int32>()(a, b);
                else if (a.type() == typeid(UInt32))  return OpsL<OP, UInt32>()(a, b);
                else if (a.type() == typeid(Int64))   return OpsL<OP, Int64>()(a, b);
                else if (a.type() == typeid(UInt64))  return OpsL<OP, UInt64>()(a, b);
                else if (a.type() == typeid(Float))   return OpsL<OP, Float>()(a, b);
                else if (a.type() == typeid(Double))  return OpsL<OP, Double>()(a, b);
                else                                  return Numeric();
            }
        };

        static Op<Add> addOp;
        static Op<Sub> subOp;
        static Op<Mul> mulOp;
        static Op<Div> divOp;
        static Op<Mod> modOp;
        static Op<Pow> powOp;
        static Op<Min> minOp;
        static Op<Max> maxOp;

    public:

        Numeric () {};
        Numeric (Null) : Any() {}
        Numeric (const Boolean &value) : Any(value) {}
        Numeric (const Int8 &value) : Any(value) {}
        Numeric (const UInt8 &value) : Any(value) {}
        Numeric (const Int16 &value) : Any(value) {}
        Numeric (const UInt16 &value) : Any(value) {}
        Numeric (const Int32 &value) : Any(value) {}
        Numeric (const UInt32 &value) : Any(value) {}
        Numeric (const Int64 &value) : Any(value) {}
        Numeric (const UInt64 &value) : Any(value) {}
        Numeric (const Float &value) : Any(value) {}
        Numeric (const Double &value) : Any(value) {}

        enum NumericType
        numericType () const;

        int
        numericTypeIndex () const;

        Numeric
        operator+ (const Numeric &value) const;

        Numeric
        operator- (const Numeric &value) const;

        Numeric
        operator* (const Numeric &value) const;

        Numeric
        operator/ (const Numeric &value) const;

        Numeric
        operator% (const Numeric &value) const;

        Numeric
        pow (const Numeric &value) const;

        Numeric
        min (const Numeric &value) const;

        Numeric
        max (const Numeric &value) const;

        template <typename T>
        T
        cast () const {
            return boost::any_cast<T>(* (boost::any *) this);
        }

//        virtual const std::type_info & type() const
//        {
//        return typeid(ValueType);
//        }

        friend std::ostream &
        operator<< (std::ostream &stream, const Numeric &value) {
                 if (value.type() == typeid(Boolean)) stream << value.cast<Boolean>();
            else if (value.type() == typeid(Int8))    stream << value.cast<Int8>();
            else if (value.type() == typeid(UInt8))   stream << value.cast<UInt8>();
            else if (value.type() == typeid(Int16))   stream << value.cast<Int16>();
            else if (value.type() == typeid(UInt16))  stream << value.cast<UInt16>();
            else if (value.type() == typeid(Int32))   stream << value.cast<Int32>();
            else if (value.type() == typeid(UInt32))  stream << value.cast<UInt32>();
            else if (value.type() == typeid(Int64))   stream << value.cast<Int64>();
            else if (value.type() == typeid(UInt64))  stream << value.cast<UInt64>();
            else if (value.type() == typeid(Float))   stream << value.cast<Float>();
            else if (value.type() == typeid(Double))  stream << value.cast<Double>();
            return stream;
        }
    };

    std::string
    typeName (const Numeric &value);

} }

#endif
