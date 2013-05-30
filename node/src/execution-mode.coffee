# execution-mode.coffee - define producting, transforming and data consuming
# node behaviour.
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

# Determine node's execution mode. There are 3 groups of nodes:
#
# 1. Producers - nodes with output parameters only that generate data, ie.
#    Mouse, FPS, Frame.
# 2. Processors - nodes that transform data, those are nodes with input and
#    output parameters. Example processor nodes include Deg2Rad, Math.
# 3. Consumers - nodes that perform some action outside of flovv engine, ie.
#    OpenGL Circle.
#
# Execution mode should be set on class level. If it's not possible, as in
# JavaScript node type for example, class level should be left as
# ExecutionMode.Unknown and proper value should be set when node becomes
# enabled.
ExecutionMode =
  Unknown:   0
  Producer:  1
  Processor: 2
  Consumer:  3

module.exports = ExecutionMode if module?
