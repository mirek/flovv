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

ClampInt  = (min, max, a) -> Math.min(Math.max(min, a), max)
Stringify = (a) -> JSON.stringify(a)
Noop      = (a) -> a

Convertion =

  Boolean:
    Int8:   (a) -> if a then 1 else 0
    UInt8:  (a) -> if a then 1 else 0
    Int16:  (a) -> if a then 1 else 0
    UInt16: (a) -> if a then 1 else 0
    Int32:  (a) -> if a then 1 else 0
    UInt32: (a) -> if a then 1 else 0
    Int64:  (a) -> if a then 1 else 0
    UInt64: (a) -> if a then 1 else 0
    Float:  (a) -> if a then 1 else 0
    Double: (a) -> if a then 1 else 0
    String: (a) -> if a then 'true' else 'false'

  Int8:
    UInt8:  Math.abs
    Int16:  Noop
    UInt16: Math.abs
    Int32:  Noop
    UInt32: Math.abs
    Int64:  Noop
    UInt64: Math.abs
    Float:  Noop
    Double: Noop
    String: Stringify

  UInt8:
    String: Stringify

  Int16:
    String: Stringify

  UInt16:
    String: Stringify

  Int32:
    String: Stringify

  UInt32:
    String: Stringify

  Int64:
    String: Stringify

  UInt64:
    String: Stringify

  Float:
    String: Stringify
  
  Double:
    String: Stringify

  String:
    Boolean: (a) ->
      # if isNaN(r = parseFloat(a))
      # else
      #   r ? true : false

module.exports = Convertion if module?
