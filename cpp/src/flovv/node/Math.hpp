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

#ifndef __FLOVV_NODE_MATH_HPP__
#define __FLOVV_NODE_MATH_HPP__ 1

#include <functional>
#include <boost/any.hpp>

#include <flovv/Node.hpp>
#include <flovv/type/String.hpp>
//#include <flovv/type/Boolean.hpp>
#include <flovv/type/Numeric.hpp>
//#include <flovv/type/Enum.hpp>

namespace flovv { namespace node {
    
    class Math : public Node {
        
    public:

//    	static const type::String InputEnabled = "Enabled";


        enum OperationType {
            OperationTypeAddition,
            OperationTypeSubstraction,
            OperationTypeMultiplication,
            OperationTypeDivision,
            OperationTypePower,
            OperationTypeModulo,
            OperationTypeMinimum,
            OperationTypeMaximum
        };

        Math() : Node(ExecutionMode::Processor, TimeMode::None) {
            registerInput  ("Enabled",   "Boolean",  type::Boolean(true));
            registerInput  ("Operation", "UInt8",    type::UInt8(OperationTypeAddition));
//            registerInput  ("Operand1",  "Numeric",  type::Numeric(0));
//            registerInput  ("Operand2",  "Numeric",  type::Numeric(0));
//            registerOutput ("Output",    "Numeric",  type::Numeric(0));
        }
        
        virtual void operator()() {
//            if (anyInputChanged("Operand1", "Operand2")) {
//                type::Numeric a = loadInput<type::Numeric>("a");
//                type::Numeric b = loadInput<type::Numeric>("b");
//                type::Numeric output = NumericTypeNull;
//                switch (loadInput<UInt8>("Operation")) {
//                    case OperationTypeAddition:       output = a + b; break;
//                    case OperationTypeSubstraction:   output = a - b; break;
//                    case OperationTypeMultiplication: output = a * b; break;
//                    case OperationTypeDivision:       output = a / b; break;
//                    case OperationTypePower:          output = Numeric::pow(a, b); break;
//                    case OperationTypeModulo:         output = a % b; break;
//                    case OperationTypeMinimum:        output = Numeric::min(a, b); break;
//                    case OperationTypeMaximum:        output = Numeric::max(a, b); break;
//                }
//                storeOutput<type::Numeric>(output);
//            }
        };
    };
    
} }


#endif /* defined(__FLOVV_MATH_HPP__) */
