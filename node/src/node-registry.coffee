# node-registry.coffee - factory functions and information on available nodes.
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

# Loggable = require 'loggable'

# Each engine instance has it's own node registry. It can independently control
# node types that are available. As default, engine has available all built-in
# node types defined in node-types.coffee.
class NodeRegistry

  # log: Logger.new
  registry: {}

  constructor: () ->

  add: (key, factory, info) ->
    @registry[key] = {
      factory: factory,
      info: info
    }

  createNode: (key) ->
    new @getFactory(key)

  getFactory: (key) ->
    @registry[key].factory

  getInfo: (key) ->
    @registry[key].factory

module.exports = NodeRegistry if module?
