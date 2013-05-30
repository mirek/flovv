# param.coffee - modification aware value container.
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

# Param holds information about value, keeps track of access count (load and 
# store counts) and provides way to load and store values using type convertion
# functions.
class Param

  stores: 1
  loads: 0
  lastLoadAtStore: 0

  valueType: null
  value: null

  constructor: (@valueType, @value) ->

  # Store value.
  store: (value, f) ->
    ++@stores
    @value = value

  # Load value optionally using convertion function.
  load: (f) ->
    ++@loads
    @lastLoadAtStore = @stores
    @peek(f)

  # Retrieve value without affecting counters optionally using convertion function.
  peek: (f) ->
    if f?
      f(@value)
    else
      @value

  # Return true if value has been stored since last load.
  hasChanged: () ->
    @lastLoadAtStore != @stores

  toString: () ->
    JSON.stringify
      type: 'Param'
      valueType: @valueType
      value: @value

module.exports = Param if module?

# Test
if !module.parent

  assert = require 'assert'

  # console.log new Param().toString()
  # 
  # p = new Param 'String', 'foo'
  # assert.equal 'foo', p.mValue
  # assert.equal 'foo', p.load()
  # assert.equal 'foo', p.peek()
  # p.store 'bar'
  # assert.equal 'bar', p.value
  # assert.equal 'bar', p.load()
  # assert.equal 'bar', p.peek()
  # assert.equal p.stores, 2
  # assert.equal p.loads, 2

  describe 'Param', () ->
    it 'should be foo', () ->
      p = new Param('String', 'foo')
      assert.equal 'foo', p.load()