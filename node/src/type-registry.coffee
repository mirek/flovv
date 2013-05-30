# type-registry.coffee - info on registered types and convertions between them.
#
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

Type = require './type'
Convertion = require './convertion'

class TypeRegistry

  @toKey = (from, to) ->
    if from is Type.Any && to is Type.Any
      "#{from.typeName} -> #{to.typeName}"
    else
      "#{from} -> #{to}"

  types: []
  convertions: {}

  constructor: () ->
    
    # Register all built-in types.
    for typeName, typeClass of Type
      @addType typeName, typeClass
    
    for fromTypeName, toConvertions of Convertion
      for toTypeName, f of toConvertions
        @addConvertion fromTypeName, toTypeName, f

  addType: (typeKey) ->
    if @types.indexOf(typeKey) == -1
      @types.push typeKey
      true
    else
      false

  addConvertion: (from, to, f) ->
    @convertions[@constructor.toKey(from, to)] = f

  getConvertion: (from, to) ->
    @convertions[@constructor.toKey(from, to)]

  convert: (from, to, value) ->
    if ((f = @getConvertion(from, to)))
      f(value)
    else
      undefined

  count: () ->
    @types.length

module.exports = TypeRegistry if module?

if module? && !module.parent?

  # console.log Type

  assert = require 'assert'

  r = new TypeRegistry
  n = r.count()
  assert.equal r.count() - n, 0
  r.addType 'Test'
  assert.equal r.count() - n, 1
  r.addType 'Test'
  assert.equal r.count() - n, 1

  assert.equal r.convert('UInt64', 'String', 10) is '10', true
  assert.equal r.convert('UInt64', 'String', 10) is 10, false

  console.log 'done.'
