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

Node          = require '../node'
Input         = require '../input'
Output        = require '../output'
ExecutionMode = require '../execution-mode'
TimeMode      = require '../time-mode'

Operations =
  '+': (a, b) -> a + b
  '-': (a, b) -> a - b
  '*': (a, b) -> a * b
  '/': (a, b) -> a / b
  '%': (a, b) -> a % b
  'Min': (a, b) -> Math.min(a, b)
  'Max': (a, b) -> Math.max(a, b)

class Math extends Node

  op: Operations['+']

  constructor: () ->
    super ExecutionMode.Processor, TimeMode.None

    # TODO
    # @addParam 'Type', ''
    @addParam 'Operation', 'String', '+'

    @addInput 'A', 'Int64', 0
    @addInput 'B', 'Int64', 0

    @addOutput 'Output', 'Int64', 0

  call: () ->
    if @anyInputChanged('A', 'B')
      @storeOutput @op(@loadInput('A'), @loadInput('B'))
    true

module.exports = Math if module?

if module? && !module.parent?
  
  m = new Math
  