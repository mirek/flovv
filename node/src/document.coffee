# document.coffee - store information on composition including node's hierarchy,
# initial state and connections between nodes.
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

Sqlite3 = require('sqlite3').verbose()

class Document

  nodes: []
  connections: []

module.exports = Document if module?

# migrate: (version)
# 
# initialize: ()

# doc = new FlovvDoc
# doc.load 'test.flovv'
# doc.eachNode (node) ->
#   console.log node

# db = new Sqlite3.Database ":memory:"
# 
# db.serialize () ->
#   db.run "CREATE TABLE lorem (info TEXT)"
#   stmt = db.prepare "INSERT INTO lorem VALUES (?)"
#   for i in [0..10]
#     stmt.run("Ipsum " + i)
#   stmt.finalize()
# 
#   db.each "SELECT rowid AS id, info FROM lorem", (err, row) ->
#     console.log row.id + ": " + row.info
# 
# db.close()

