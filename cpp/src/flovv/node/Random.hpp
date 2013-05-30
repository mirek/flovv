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

#ifndef __FLOVV_NODE_RANDOM_HPP__
#define __FLOVV_NODE_RANDOM_HPP__ 1

#include <random>

#include <flovv/Node.hpp>
#include <flovv/type/Numeric.hpp>

namespace flovv { namespace node {

    /**
     * Generate random number based on settings.
     */
    class Random : public Node {

        type::Int64 mMin = type::Int64(0);
        type::Int64 mMax = type::Int64(100);
        std::mt19937 mRandom;
        std::uniform_int_distribution<type::Int64> mUniformDistribution {0, 100};

    public:

        /**
         */
        Random () : Node(ExecutionMode::Producer, TimeMode::Linear) {
            registerInput("Enabled", "Boolean", type::Boolean(true));
            registerInput("Seed", "Int32", type::Int32(0));
            registerInput("Min", "Int64", type::Int64(0));
            registerInput("Max", "Int64", type::Int64(100));
            registerOutput("Output", "Int64", type::Int64(0));
        }

        virtual void operator() () {
            
            // Update distribution if something changed.
            if (haveAnyInputChanged({"Min", "Max"})) {
                mUniformDistribution = decltype(mUniformDistribution)(loadInput<type::Int64>("Min"), loadInput<type::Int64>("Max"));
            }

            // Re-seed if necessary.
            if (hasInputChanged("Seed")) {
                mRandom.seed(loadInput<type::Int32>("Seed"));
            }
            
            // Always generate random numbers.
            storeOutput<type::Int64>("Output", mUniformDistribution(mRandom));
        };
    };
    
} }

#endif
