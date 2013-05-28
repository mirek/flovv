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

#ifndef __FLOVV_NODE_HPP__
#define __FLOVV_NODE_HPP__ 1

#include <iostream>
#include <map>
#include <tuple>
#include <typeinfo>
#include <math.h>

#include <flovv/type/Any.hpp>
#include <flovv/InputParam.hpp>
#include <flovv/OutputParam.hpp>

namespace flovv
{
    
    /**
     * We want to be explicit when it comes to node identifiers.
     */
    typedef std::string NodeId;
    
    /**
     * Nil id.
     */
    extern const NodeId NodeIdNone;

    /**
     * There are three execution modes:
     *
     * 1. ExecutionMode::Producer - for nodes generating output, ie. Signal generates change after specified interval.
     * 2. ExecutionMode::Processor - for nodes tranforming input(s) into output(s), ie. Math node performs mathematical operation on inputs generating output.
     * 3. ExecutionMode::Consumer - for nodes consuming inputs, ie. Printer will print it's input to standard output.
     */
    enum class ExecutionMode
    {
        Unknown,
        Producer,
        Processor,
        Consumer
    };
    
    /**
     * 
     */
    enum class TimeMode
    {
        Unknown,
        None,
        Idle,
        Linear,
        Dynamic
    };
    
    /**
     *
     */
    class Node
    {
        
    protected:

        enum ExecutionMode mExecutionMode = ExecutionMode::Unknown;
        enum TimeMode mTimeMode = TimeMode::Unknown;
        
        std::string mTypeName;
        NodeId mNodeId;
        
        std::map<std::string, Param> mParams;
        std::map<std::string, InputParam> mInputParams;
        std::map<std::string, OutputParam> mOutputParams;
        
    public:

        /**
         *
         */
        Node (enum ExecutionMode executionMode = ExecutionMode::Unknown, enum TimeMode timeMode = TimeMode::Unknown);

        /**
         *
         */
        virtual
        ~Node();
        
        /**
         * Perform 
         */
        virtual void
        operator() ();
        
        /**
         *
         */
        void
        setExecutionMode (const enum ExecutionMode &executionMode);
        
        /**
         *
         */
        const enum ExecutionMode &
        getExecutionMode() const;
        
        /**
         * Time mode.
         *
         * @return
         */
        const enum TimeMode &
        getTimeMode() const;

        /**
         *
         */
        void
        setTimeMode (const enum TimeMode &timeMode);

        const std::string &
        getTypeName () const;

        /**
         *
         */
        void
        setTypeName (const std::string &name);

        /**
         *
         */
        const NodeId &
        getNodeId () const {
            return mNodeId;
        }

        /**
         *
         */
        void
        setNodeId (const NodeId &value) {
            mNodeId = value;
        }

        /**
         *
         */
        bool
        haveAnyInputChanged (const std::initializer_list<std::string> &names) const;

        /**
         *
         */
        bool
        hasInputChanged (const std::string &name = "Input") const;

        /**
         *
         */
        bool
        hasOutputChanged (const std::string &name = "Output") const;

        /**
         *
         */
        void
        registerInput (const std::string &name, const std::string &typeName, const type::Any &initialValue);
        
        /**
         *
         */
        template <typename T>
        void
        registerInput (const std::string &name, const std::string &typeName, const T &initialValue)
        {
            registerInput(name, typeName, (const type::Any &) initialValue);
        }

        /**
         *
         */
        void
        registerOutput (const std::string &name, const std::string &typeName, const type::Any &initialValue);

        /**
         *
         */
        template <typename T>
        void
        registerOutput (const std::string &name, const std::string &typeName, const T &initialValue)
        {
            registerOutput(name, typeName, (const type::Any &) initialValue);
        }
        
        /**
         * Get input param.
         *
         * @param name Input param name.
         * @return Reference to input param.
         */
        InputParam &
        getInput (const std::string &name = "Input");

        /**
         * Get output param by name.
         *
         * @param name Output param name.
         * @return Reference to output param.
         */
        OutputParam &
        getOutput (const std::string &name = "Output")
        {
            return mOutputParams.at(name);
        }
        
        /**
         *
         */
        template <typename T>
        bool
        loadInputIfHasChanged (const std::string &name, T &value, const TypeConvertionFunction &function = typeConvertionDirectAssignment)
        {
            bool result = false;
            InputParam &inputParam = mInputParams.at(name);
            if (inputParam.hasChanged()) {
                result = inputParam.load<T>(function);
            }
            return result;
        }

        /**
         *
         */
        template <typename T>
        T
        loadInput (const std::string &name = "Input", const TypeConvertionFunction &function = typeConvertionDirectAssignment) {
            return mInputParams.at(name).load<T>(function);
        }

        /**
         *
         */
        template <typename T>
        T
        loadOutput (const std::string &name = "Output", const TypeConvertionFunction &function = typeConvertionDirectAssignment)
        {
            return mOutputParams.at(name).load<T>(function);
        }

        /**
         *
         */
        template <typename T>
        void
        storeInput (const std::string &name, const T &value, const TypeConvertionFunction &function = typeConvertionDirectAssignment)
        {
            mInputParams.at(name).store<T>(value, function);
        }

        /**
         * 
         */
        template <typename T>
        void
        storeOutput (const std::string &name, const T &value, const TypeConvertionFunction &function = typeConvertionDirectAssignment)
        {
            mOutputParams.at(name).store<T>(value, function);
        }
    };
}

#endif
