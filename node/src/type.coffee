# Copyright (c) 2013 Mirek Rusin <mirek [at] me [dot] com>
#
# Released under the MIT License.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

# TODO: typeName should be class member, but don't know how to make getTypeName
#       polymorphic.

class Any
  typeName: 'Any'
  value: null

  constructor: (value = null) ->
    @setValue value

  getTypeName: () ->
    @typeName

  setValue: (value, f) ->
    if f?
      @value = f(value)
    else
      @value = value

  getValue: (f) ->
    if f?
      f(@value)
    else
      @value

class Boolean_ extends Any
  typeName: 'Boolean'

class Int8 extends Any
  typeName: 'Int8'

class UInt8 extends Any
  typeName: 'UInt8'

class Int16 extends Any
  typeName: 'Int16'

class UInt16 extends Any
  typeName: 'UInt16'

class Int32 extends Any
  typeName: 'Int32'

class UInt32 extends Any
  typeName: 'UInt32'

class Int64 extends Any
  typeName: 'Int64'

  setValue: (value) ->
    super parseInt(value)

class UInt64 extends Any
  typeName: 'UInt64'

  setValue: (value) ->
    super Math.abs(parseInt(value))

class Float extends Any
  typeName: 'Float'

class Double extends Any
  typeName: 'Double'

class String extends Any
  typeName: 'String'

if module?
  module.exports =

    Undefined: undefined
    Null:      null
    True:      true
    False:     false
    Infinity:  Infinity

    Any:       Any
    Boolean:   Boolean_
    Int8:      Int8
    UInt8:     UInt8
    Int16:     Int16
    UInt16:    UInt16
    Int32:     Int32
    UInt32:    UInt32
    Int64:     Int64
    UInt64:    UInt64
    Float:     Float
    Double:    Double
    String:    String

if module? && !module.parent?
  assert = require 'assert'

  uint64 = new UInt64(-1.3)
  assert.equal uint64.getValue() is 1, true
  assert.equal uint64.getTypeName(), "UInt64"