# node.coffee - unit of work.
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

Input         = require './input'
Output        = require './output'
ExecutionMode = require './execution-mode'
TimeMode      = require './time-mode'

class Node

  engine: null
  timeMode: TimeMode.Unknown
  executionMode: ExecutionMode.Unknown

  nodeId: null
  typeName: null

  params: {}
  inputs: {}
  outputs: {}

  constructor: (@executionMode, @timeMode) ->

  # Invoked when
  willEnable: (params, inputs, outputs) ->
    

  willDisable: () ->

  call: () ->
    true

  # haveAnyInputChanged: () ->

  addParam: (key, param) ->
    @params[key] = param

  removeParam: (key) ->
    @params.remove(key)

  addInput: (key, input) ->
    @inputs[key] = input

  removeInput: (key) ->
    @inputs.remove(key)

  addOutput: (key, output) ->
    unless @outputs[key]?
      @outputs[key] = output

  hasInputChanged: (key = 'Input') ->
    @inputs[key].hasChanged()

module.exports = Node if module?

if module? && !module.parent?

  node = new Node()
  node.addInput('Enabled', new Input())
  console.log(node.inputs)

