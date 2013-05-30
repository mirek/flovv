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

#include <flovv/TypeRegistry.hpp>

namespace flovv {
    
    bool
    typeConvertionDirectAssignment (const type::Any &from, type::Any &to) {
        to = from;
        return true;
    }
    
    TypeRegistry::TypeRegistry() {
        
        // Register basic types.
        registerType<type::Null>("Null");
        registerType<type::Boolean>("Boolean");
        registerType<type::Int8>("Int8");
        registerType<type::UInt8>("UInt8");
        registerType<type::Int16>("Int16");
        registerType<type::UInt16>("UInt16");
        registerType<type::Int32>("Int32");
        registerType<type::UInt32>("UInt32");
        registerType<type::Int64>("Int64");
        registerType<type::UInt64>("UInt64");
        registerType<type::Float>("Float");
        registerType<type::Double>("Double");
        registerType<type::String>("String");
        
        // Register static casting between numeric types.
        //
        // Generated with Ruby (TODO: how to write it in metaprogramming?):
        //
        //   T = %w{Boolean Int8 UInt8 UInt16 Int32 UInt32 Int64 UInt64 Float Double}
        //   T.each { |a| T.each { |b| puts "registerTypeConvertion(\"#{a}\", \"#{b}\", typeConvertionStaticCast<type::#{a}, type::#{b}>);" unless a == b } }
        //
        registerTypeConvertion("Boolean", "Int8", typeConvertionStaticCast<type::Boolean, type::Int8>);
        registerTypeConvertion("Boolean", "UInt8", typeConvertionStaticCast<type::Boolean, type::UInt8>);
        registerTypeConvertion("Boolean", "UInt16", typeConvertionStaticCast<type::Boolean, type::UInt16>);
        registerTypeConvertion("Boolean", "Int32", typeConvertionStaticCast<type::Boolean, type::Int32>);
        registerTypeConvertion("Boolean", "UInt32", typeConvertionStaticCast<type::Boolean, type::UInt32>);
        registerTypeConvertion("Boolean", "Int64", typeConvertionStaticCast<type::Boolean, type::Int64>);
        registerTypeConvertion("Boolean", "UInt64", typeConvertionStaticCast<type::Boolean, type::UInt64>);
        registerTypeConvertion("Boolean", "Float", typeConvertionStaticCast<type::Boolean, type::Float>);
        registerTypeConvertion("Boolean", "Double", typeConvertionStaticCast<type::Boolean, type::Double>);
        registerTypeConvertion("Int8", "Boolean", typeConvertionStaticCast<type::Int8, type::Boolean>);
        registerTypeConvertion("Int8", "UInt8", typeConvertionStaticCast<type::Int8, type::UInt8>);
        registerTypeConvertion("Int8", "UInt16", typeConvertionStaticCast<type::Int8, type::UInt16>);
        registerTypeConvertion("Int8", "Int32", typeConvertionStaticCast<type::Int8, type::Int32>);
        registerTypeConvertion("Int8", "UInt32", typeConvertionStaticCast<type::Int8, type::UInt32>);
        registerTypeConvertion("Int8", "Int64", typeConvertionStaticCast<type::Int8, type::Int64>);
        registerTypeConvertion("Int8", "UInt64", typeConvertionStaticCast<type::Int8, type::UInt64>);
        registerTypeConvertion("Int8", "Float", typeConvertionStaticCast<type::Int8, type::Float>);
        registerTypeConvertion("Int8", "Double", typeConvertionStaticCast<type::Int8, type::Double>);
        registerTypeConvertion("UInt8", "Boolean", typeConvertionStaticCast<type::UInt8, type::Boolean>);
        registerTypeConvertion("UInt8", "Int8", typeConvertionStaticCast<type::UInt8, type::Int8>);
        registerTypeConvertion("UInt8", "UInt16", typeConvertionStaticCast<type::UInt8, type::UInt16>);
        registerTypeConvertion("UInt8", "Int32", typeConvertionStaticCast<type::UInt8, type::Int32>);
        registerTypeConvertion("UInt8", "UInt32", typeConvertionStaticCast<type::UInt8, type::UInt32>);
        registerTypeConvertion("UInt8", "Int64", typeConvertionStaticCast<type::UInt8, type::Int64>);
        registerTypeConvertion("UInt8", "UInt64", typeConvertionStaticCast<type::UInt8, type::UInt64>);
        registerTypeConvertion("UInt8", "Float", typeConvertionStaticCast<type::UInt8, type::Float>);
        registerTypeConvertion("UInt8", "Double", typeConvertionStaticCast<type::UInt8, type::Double>);
        registerTypeConvertion("UInt16", "Boolean", typeConvertionStaticCast<type::UInt16, type::Boolean>);
        registerTypeConvertion("UInt16", "Int8", typeConvertionStaticCast<type::UInt16, type::Int8>);
        registerTypeConvertion("UInt16", "UInt8", typeConvertionStaticCast<type::UInt16, type::UInt8>);
        registerTypeConvertion("UInt16", "Int32", typeConvertionStaticCast<type::UInt16, type::Int32>);
        registerTypeConvertion("UInt16", "UInt32", typeConvertionStaticCast<type::UInt16, type::UInt32>);
        registerTypeConvertion("UInt16", "Int64", typeConvertionStaticCast<type::UInt16, type::Int64>);
        registerTypeConvertion("UInt16", "UInt64", typeConvertionStaticCast<type::UInt16, type::UInt64>);
        registerTypeConvertion("UInt16", "Float", typeConvertionStaticCast<type::UInt16, type::Float>);
        registerTypeConvertion("UInt16", "Double", typeConvertionStaticCast<type::UInt16, type::Double>);
        registerTypeConvertion("Int32", "Boolean", typeConvertionStaticCast<type::Int32, type::Boolean>);
        registerTypeConvertion("Int32", "Int8", typeConvertionStaticCast<type::Int32, type::Int8>);
        registerTypeConvertion("Int32", "UInt8", typeConvertionStaticCast<type::Int32, type::UInt8>);
        registerTypeConvertion("Int32", "UInt16", typeConvertionStaticCast<type::Int32, type::UInt16>);
        registerTypeConvertion("Int32", "UInt32", typeConvertionStaticCast<type::Int32, type::UInt32>);
        registerTypeConvertion("Int32", "Int64", typeConvertionStaticCast<type::Int32, type::Int64>);
        registerTypeConvertion("Int32", "UInt64", typeConvertionStaticCast<type::Int32, type::UInt64>);
        registerTypeConvertion("Int32", "Float", typeConvertionStaticCast<type::Int32, type::Float>);
        registerTypeConvertion("Int32", "Double", typeConvertionStaticCast<type::Int32, type::Double>);
        registerTypeConvertion("UInt32", "Boolean", typeConvertionStaticCast<type::UInt32, type::Boolean>);
        registerTypeConvertion("UInt32", "Int8", typeConvertionStaticCast<type::UInt32, type::Int8>);
        registerTypeConvertion("UInt32", "UInt8", typeConvertionStaticCast<type::UInt32, type::UInt8>);
        registerTypeConvertion("UInt32", "UInt16", typeConvertionStaticCast<type::UInt32, type::UInt16>);
        registerTypeConvertion("UInt32", "Int32", typeConvertionStaticCast<type::UInt32, type::Int32>);
        registerTypeConvertion("UInt32", "Int64", typeConvertionStaticCast<type::UInt32, type::Int64>);
        registerTypeConvertion("UInt32", "UInt64", typeConvertionStaticCast<type::UInt32, type::UInt64>);
        registerTypeConvertion("UInt32", "Float", typeConvertionStaticCast<type::UInt32, type::Float>);
        registerTypeConvertion("UInt32", "Double", typeConvertionStaticCast<type::UInt32, type::Double>);
        registerTypeConvertion("Int64", "Boolean", typeConvertionStaticCast<type::Int64, type::Boolean>);
        registerTypeConvertion("Int64", "Int8", typeConvertionStaticCast<type::Int64, type::Int8>);
        registerTypeConvertion("Int64", "UInt8", typeConvertionStaticCast<type::Int64, type::UInt8>);
        registerTypeConvertion("Int64", "UInt16", typeConvertionStaticCast<type::Int64, type::UInt16>);
        registerTypeConvertion("Int64", "Int32", typeConvertionStaticCast<type::Int64, type::Int32>);
        registerTypeConvertion("Int64", "UInt32", typeConvertionStaticCast<type::Int64, type::UInt32>);
        registerTypeConvertion("Int64", "UInt64", typeConvertionStaticCast<type::Int64, type::UInt64>);
        registerTypeConvertion("Int64", "Float", typeConvertionStaticCast<type::Int64, type::Float>);
        registerTypeConvertion("Int64", "Double", typeConvertionStaticCast<type::Int64, type::Double>);
        registerTypeConvertion("UInt64", "Boolean", typeConvertionStaticCast<type::UInt64, type::Boolean>);
        registerTypeConvertion("UInt64", "Int8", typeConvertionStaticCast<type::UInt64, type::Int8>);
        registerTypeConvertion("UInt64", "UInt8", typeConvertionStaticCast<type::UInt64, type::UInt8>);
        registerTypeConvertion("UInt64", "UInt16", typeConvertionStaticCast<type::UInt64, type::UInt16>);
        registerTypeConvertion("UInt64", "Int32", typeConvertionStaticCast<type::UInt64, type::Int32>);
        registerTypeConvertion("UInt64", "UInt32", typeConvertionStaticCast<type::UInt64, type::UInt32>);
        registerTypeConvertion("UInt64", "Int64", typeConvertionStaticCast<type::UInt64, type::Int64>);
        registerTypeConvertion("UInt64", "Float", typeConvertionStaticCast<type::UInt64, type::Float>);
        registerTypeConvertion("UInt64", "Double", typeConvertionStaticCast<type::UInt64, type::Double>);
        registerTypeConvertion("Float", "Boolean", typeConvertionStaticCast<type::Float, type::Boolean>);
        registerTypeConvertion("Float", "Int8", typeConvertionStaticCast<type::Float, type::Int8>);
        registerTypeConvertion("Float", "UInt8", typeConvertionStaticCast<type::Float, type::UInt8>);
        registerTypeConvertion("Float", "UInt16", typeConvertionStaticCast<type::Float, type::UInt16>);
        registerTypeConvertion("Float", "Int32", typeConvertionStaticCast<type::Float, type::Int32>);
        registerTypeConvertion("Float", "UInt32", typeConvertionStaticCast<type::Float, type::UInt32>);
        registerTypeConvertion("Float", "Int64", typeConvertionStaticCast<type::Float, type::Int64>);
        registerTypeConvertion("Float", "UInt64", typeConvertionStaticCast<type::Float, type::UInt64>);
        registerTypeConvertion("Float", "Double", typeConvertionStaticCast<type::Float, type::Double>);
        registerTypeConvertion("Double", "Boolean", typeConvertionStaticCast<type::Double, type::Boolean>);
        registerTypeConvertion("Double", "Int8", typeConvertionStaticCast<type::Double, type::Int8>);
        registerTypeConvertion("Double", "UInt8", typeConvertionStaticCast<type::Double, type::UInt8>);
        registerTypeConvertion("Double", "UInt16", typeConvertionStaticCast<type::Double, type::UInt16>);
        registerTypeConvertion("Double", "Int32", typeConvertionStaticCast<type::Double, type::Int32>);
        registerTypeConvertion("Double", "UInt32", typeConvertionStaticCast<type::Double, type::UInt32>);
        registerTypeConvertion("Double", "Int64", typeConvertionStaticCast<type::Double, type::Int64>);
        registerTypeConvertion("Double", "UInt64", typeConvertionStaticCast<type::Double, type::UInt64>);
        registerTypeConvertion("Double", "Float", typeConvertionStaticCast<type::Double, type::Float>);
        
        // Register lexical casting to/from strings.
        registerTypeConvertion("Boolean", "String", typeConvertionLexicalCast<type::Boolean, type::String>);
        registerTypeConvertion("Int8",    "String", typeConvertionLexicalCast<type::Int8, type::String>);
        registerTypeConvertion("UInt8",   "String", typeConvertionLexicalCast<type::UInt8, type::String>);
        registerTypeConvertion("Int16",   "String", typeConvertionLexicalCast<type::Int16, type::String>);
        registerTypeConvertion("UInt16",  "String", typeConvertionLexicalCast<type::UInt16, type::String>);
        registerTypeConvertion("Int32",   "String", typeConvertionLexicalCast<type::Int32, type::String>);
        registerTypeConvertion("UInt32",  "String", typeConvertionLexicalCast<type::UInt32, type::String>);
        registerTypeConvertion("Int64",   "String", typeConvertionLexicalCast<type::Int64, type::String>);
        registerTypeConvertion("UInt64",  "String", typeConvertionLexicalCast<type::UInt64, type::String>);
        registerTypeConvertion("Float",   "String", typeConvertionLexicalCast<type::Float,  type::String>);
        registerTypeConvertion("Double",  "String", typeConvertionLexicalCast<type::Double, type::String>);
        
        registerTypeConvertion("String", "Boolean", typeConvertionLexicalCast<type::String, type::Boolean>);
        registerTypeConvertion("String", "Int8",    typeConvertionLexicalCast<type::String, type::Int8>);
        registerTypeConvertion("String", "UInt8",   typeConvertionLexicalCast<type::String, type::UInt8>);
        registerTypeConvertion("String", "Int16",   typeConvertionLexicalCast<type::String, type::Int16>);
        registerTypeConvertion("String", "UInt16",  typeConvertionLexicalCast<type::String, type::UInt16>);
        registerTypeConvertion("String", "Int32",   typeConvertionLexicalCast<type::String, type::Int32>);
        registerTypeConvertion("String", "UInt32",  typeConvertionLexicalCast<type::String, type::UInt32>);
        registerTypeConvertion("String", "Int64",   typeConvertionLexicalCast<type::String, type::Int64>);
        registerTypeConvertion("String", "UInt64",  typeConvertionLexicalCast<type::String, type::UInt64>);
        registerTypeConvertion("String", "Float",   typeConvertionLexicalCast<type::String, type::Float>);
        registerTypeConvertion("String", "Double",  typeConvertionLexicalCast<type::String, type::Double>);
    }
    
    void
    TypeRegistry::registerType (const std::type_info &typeInfo, const std::string &name, bool registerDirectAssignment) {
        
        // Register type name to alias (human readable) mapping.
        mTypeNameAliases.insert({typeInfo.name(), name});
        
        // Register direct assignment between same type if requested.
        if (registerDirectAssignment) {
            registerTypeConvertion(name, name, typeConvertionDirectAssignment);
        }
    }

    void
    TypeRegistry::registerTypeConvertion (const TypeConvertionKey &convertionKey, const TypeConvertionFunction &function) {
        mTypeConvertions[convertionKey] = function;
    }
    
    void
    TypeRegistry::registerTypeConvertion (const std::string &from, const std::string &to, const TypeConvertionFunction &function) {
        registerTypeConvertion(TypeConvertionKey(from, to), function);
    }
    
    bool
    TypeRegistry::convert (const type::Any &from, type::Any &to) {
        return convert(TypeConvertionKey(mTypeNameAliases[from.type().name()], mTypeNameAliases[to.type().name()]), from, to);
    }
    
    bool
    TypeRegistry::convert (const TypeConvertionKey &key, const type::Any &from, type::Any &to) const {
        return mTypeConvertions.at(key)(from, to);
    }
    
    const TypeConvertionFunction &
    TypeRegistry::typeConvertionFunction (const TypeConvertionKey &key) const {
        return mTypeConvertions.at(key);
    }
    
}
