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

#ifndef __FLOVV_TYPE_REGISTRY_HPP__
#define __FLOVV_TYPE_REGISTRY_HPP__ 1

#include <functional>
#include <map>
#include <boost/any.hpp>
#include <boost/lexical_cast.hpp>

#include <flovv/type/Numeric.hpp>
#include <flovv/type/String.hpp>

namespace flovv {

    typedef bool (*TypeConvertionFunction) (const type::Any &, type::Any &);
    typedef std::pair<std::string, std::string> TypeConvertionKey;

    template <typename T1, typename T2>
    bool
    typeConvertionStaticCast (const type::Any &from, type::Any &to) {
        to = static_cast<T2>(boost::any_cast<T1>(from));
        return true;
    }
    
    template <typename T1, typename T2>
    bool
    typeConvertionLexicalCast (const type::Any &from, type::Any &to) {
        try {
            to = boost::lexical_cast<T2>(boost::any_cast<T1>(from));
            return true;
        }
        catch (boost::bad_any_cast &exception) {
            return false;
        }
    }
    
    /**
     * Direct assignment convertion function
     *
     * TODO: with type check and without?
     */
    bool
    typeConvertionDirectAssignment (const type::Any &from, type::Any &to);

    /**
     * Provides information on registered types and type convertions.
     */
    class TypeRegistry {

        // Mapping from std::type_info.name() or typeid(T).name() to alias (human readable) name.
        std::map<std::string, std::string> mTypeNameAliases;

        // Maps type pair (from - to type name) to convertion function.
        std::map<TypeConvertionKey, TypeConvertionFunction> mTypeConvertions;
        
    public:
        
        TypeRegistry();
        
        /**
         * Register type info name, it's alias and direct assignment.
         */
        void
        registerType (const std::type_info &typeInfo, const std::string &name, bool registerDirectAssignment = true);
        
        template <typename T>
        void
        registerType (const std::string &name) {
            registerType(typeid(T), name);
        }
        
        void
        registerTypeConvertion (const TypeConvertionKey &convertionKey, const TypeConvertionFunction &function);
        
        void
        registerTypeConvertion (const std::string &from, const std::string &to, const TypeConvertionFunction &function);

        bool
        convert (const type::Any &from, type::Any &to);
        
        bool
        convert (const TypeConvertionKey &key, const type::Any &from, type::Any &to) const;
        
        const TypeConvertionFunction &
        typeConvertionFunction (const TypeConvertionKey &key) const;
        
    };
    
}

#endif
