# engine.coffee - coordinates document hierarchy, types, node types and
# execution.
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

WebGL = require 'node-webgl'
Document = require './document'

class FlovvEngine

  document: null
  nodeTypes: []

  # Just a shortcut to document.requestAnimationFrame, so we can loop a bit faster.
  documentRAF: null
  canvas: null

  mouseX: null
  mouseY: null
  gl: null
  frame: 0

  constructor: (@document, @nodeTypes) ->
    @document.setTitle 'flovv engine'
    @document.setIcon "#{__dirname}/flovv.png"
    @documentRAF = @document.requestAnimationFrame
    # clearInterval(timer)
    @canvas = @document.createElement 'canvas'
    if ((@gl = @canvas.getContext "experimental-webgl"))
      @gl.viewportWidth = @width = @canvas.width
      @gl.viewportHeight = @height = @canvas.height

      console.log "#{@width}/#{@height}"

      @document.on "mousemove", (e) =>
        @mouseX = e.x / @width
        @mouseY = 1 - e.y / @height

    else
      alert "Your browser does not support WebGL"

    @running = true
    @fps = 30
    @fpsDelay = 1000 / @fps
    # @frame = 0
    
    # @initBuffers()

  # createNode: (type, ) ->
  #   result = null
  #   if @nodeTypes.find()?
  #     
  #   result

  getFrame: () ->
    @frame

  didMouseMove: (e) ->
    console.log(@mouse)

  update: () ->
    # console.log "advance"

  initBuffers: () ->
    @triangleVertexPositionBuffer = @gl.createBuffer();
    @gl.bindBuffer(@gl.ARRAY_BUFFER, @triangleVertexPositionBuffer);
    @vertices = [
         0.0,  1.0,  0.0,
        -1.0, -1.0,  0.0,
         1.0, -1.0,  0.0
    ];
    @gl.bufferData(@gl.ARRAY_BUFFER, new Float32Array(@vertices), @gl.STATIC_DRAW);
    @triangleVertexPositionBuffer.itemSize = 3;
    @triangleVertexPositionBuffer.numItems = 3;

    @triangleVertexColorBuffer = @gl.createBuffer();
    @gl.bindBuffer(@gl.ARRAY_BUFFER, @triangleVertexColorBuffer);
    @colors = [
        1.0, 0.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 1.0,
        0.0, 0.0, 1.0, 1.0,
    ];
    @gl.bufferData(@gl.ARRAY_BUFFER, new Float32Array(@colors), @gl.STATIC_DRAW);
    @triangleVertexColorBuffer.itemSize = 4;
    @triangleVertexColorBuffer.numItems = 3;

  composite: () ->
    @gl.viewport(0, 0, @gl.viewportWidth, @gl.viewportHeight)
    @gl.clear(@gl.COLOR_BUFFER_BIT | @gl.DEPTH_BUFFER_BIT)
    
    # @gl.drawArrays(@gl.TRIANGLES, 0, @triangleVertexPositionBuffer.numItems);

  getFrame() ->
    @frame

  tick: () =>
    ++@frame
    # console.log @gl
    # console.log ++@frame
    # console.log "gl: #{@gl}"
    @gl.clearColor(0.4, 0.4, (1 + Math.sin(@frame / 60)) / 2, 1)
    @gl.clear(@gl.COLOR_BUFFER_BIT | @gl.DEPTH_BUFFER_BIT)
    if @running
      @advance()
    @composite()
    @documentRAF(@anim, @delay)
  
  start: () ->

engine = new FlovvEngine(WebGL.document())
engine.start()
