/**
 *
 * The MIT License
 *
 * Copyright (c) 2012 - 2013, Mirek Rusin <mirek [at] me [dot] com>
 * http://flovv.org
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */

#include <flovv/Node.hpp>

namespace flovv
{
  
    const NodeId NodeIdNone = "";

    Node::Node (enum ExecutionMode executionMode, enum TimeMode timeMode)
    {
        setExecutionMode(executionMode);
        setTimeMode(timeMode);
    }
    
    Node::~Node ()
    {
    }
    
    void
    Node::operator() ()
    {
    }

    const enum ExecutionMode &
    Node::getExecutionMode () const
    {
        return mExecutionMode;
    }
    
    void
    Node::setExecutionMode (const enum ExecutionMode &executionMode)
    {
        if (mExecutionMode == ExecutionMode::Unknown) {
            mExecutionMode = executionMode;
        }
    }

    const enum TimeMode &
    Node::getTimeMode () const
    {
        return mTimeMode;
    }
    
    void
    Node::setTimeMode (const enum TimeMode &timeMode)
    {
        if (mTimeMode == TimeMode::Unknown) {
            mTimeMode = mTimeMode;
        }
    }
    
    const std::string &
    Node::getTypeName () const
    {
        return mTypeName;
    }

    void
    Node::setTypeName (const std::string &name)
    {
        mTypeName = name;
    }
    
    InputParam &
    Node::getInput (const std::string &name)
    {
        return mInputParams.at(name);
    }
    
    void
    Node::registerOutput (const std::string &name, const std::string &typeName, const type::Any &initialValue)
    {
        // mOutputParams.insert(name, { typeName, initialValue });
        mOutputParams[name] = { typeName, initialValue };
    }

    bool
    Node::hasInputChanged (const std::string &name) const
    {
        return mInputParams.at(name).hasChanged();
    }
    
    bool
    Node::hasOutputChanged (const std::string &name) const
    {
        return mOutputParams.at(name).hasChanged();
    }
    
    void
    Node::registerInput (const std::string &name, const std::string &typeName, const type::Any &value) {
        mInputParams[name] = { typeName, value };
    }

    // TODO: change to list
    bool
    Node::haveAnyInputChanged (const std::initializer_list<std::string> &names) const
    {
        return std::any_of(names.begin(), names.end(), [&] (const std::string &name) -> bool { return hasInputChanged(name); });
    }

}
