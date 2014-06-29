function BinlinearInterpolation (){
        
	this.width = 0;
	this.height = 0;
	this.target = null, this.source = null;
	this.csx = null;
        this.ctx = null;
        this.imgGuoData = null;
        this.imgData = null;
        this.imgTargetData = new Array();
        this.len = null;
        
};	

 BinlinearInterpolation.prototype.generate = function(target, source, originalLattice, currentLattice) {
		if ( null == source ) return;
		this.source = source;		
		this.width = window.imgWidth();
		this.height = window.imgHeight();
                var ct=document.getElementById("hairStyle");
                this.ctx=ct.getContext("2d"); 
                this.imgTargetData = this.ctx.createImageData(this.width,this.height); 
                
		for ( var i = 0; i < this.width; ++i ) {
			for ( var j = 0; j < this.height; ++j ) {
				this.imgTargetData.setRGB(i, j, 0);
			}
		}
		
		xCount = originalLattice.getXCount();
		yCount = originalLattice.getYCount();
		
		
		for ( var i = 1; i < xCount; ++i ) {
			for ( var j = 1; j < yCount; ++j ) {
				this.fillGrid( currentLattice.getRect(i, j), originalLattice.getRect(i, j) );
			}
		}
		
		
		return this.target;
	}
	
BinlinearInterpolation.prototype.fillGrid = function (  p, p0 ) {
		if ( p.length != 4 )  return;
		if ( p0.length != 4 ) return;
		 x0 = parseInt(Math.floor( Util.minX(p) ));x1 = parseInt(Math.ceil( Util.maxX(p)) );
		 y0 = parseInt(Math.floor( Util.minY(p)) ); y1 = parseInt(Math.ceil( Util.maxY(p)) );
		x0 = Math.max(x0, 0); x1 = Math.min(x1,  this.width - 1 );
		y0 = Math.max(y0, 0); y1 = Math.min(y1,  this.height - 1 );		
		for ( var i = x0; i <= x1; ++i ) {
			for ( var j = y0; j <= y1; ++j ) {
			   cur = new Point(i, j);
			   srcX = 'undefined', srcY = 'undefined';
			     for ( var k = 0; k < 4; ++k ) {
					if ( p[k].equals(i, j) ) {
						srcX = p0[k].x;
						srcY = p0[k].y;
						break;
					}
				}
				if ( srcX == 'undefined' ) {
					t = Point.TriangleContainsPoint(p[0], p[1], p[2], cur);
					if ( t[1] >= 0 && t[2] >= 0 ) {
						srcX = (p0[0].x * t[0] + p0[1].x * t[1] + p0[2].x * t[2]) / (t[0] + t[1] + t[2]);
						srcY = (p0[0].y * t[0] + p0[1].y * t[1] + p0[2].y * t[2]) / (t[0] + t[1] + t[2]);
						
					} else {
						t = Point.TriangleContainsPoint(p[2], p[3], p[0], cur);
						if ( t[1] >= 0 && t[2] >= 0 ) {
							srcX = (p0[2].x * t[0] + p0[3].x * t[1] + p0[0].x * t[2]) / (t[0] + t[1] + t[2]);
							srcY = (p0[2].y * t[0] + p0[3].y * t[1] + p0[0].y * t[2]) / (t[0] + t[1] + t[2]);							
						} else {
							;
						}
					}					
				}
				if ( 0 <= srcX && srcX <= width - 1) {
					if ( 0 <= srcY && srcY <= height - 1 ) {
						 rgb = this.query(srcX, srcY);
						 this.target.setRGB(i, j, rgb);
					}
				}
			}
		}
	}

BinlinearInterpolation.prototype.fill = function(  a,  b,  c, a0,   b0,   c0 ) {
		 x0 = parseInt(Math.floor( Util.minX(a, b, c) ));x1 = parseInt(Math.ceil( Util.maxX(a, b, c) ));
		 y0 = parseInt(Math.floor( Util.minY(a, b, c) )); y1 = parseInt(Math.ceil( Util.maxY(a, b, c) ));
		x0 = Math.max(x0, 0); x1 = Math.min(x1,  width - 1 );
		y0 = Math.max(y0, 0); y1 = Math.min(y1,  height - 1 );
		for ( var i = x0; i <= x1; ++i ) {
		  for ( var j = y0; j <= y1; ++j ) {
	            t = Point.TriangleContainsPoint(a, b, c, new Point(i, j) );
		  if ( t[1] >= 0 && t[2] >= 0 ) {
		    srcX = (a0.x * t[0] + b0.x * t[1] + c0.x * t[2]) / (t[0] + t[1] + t[2]);
		     srcY = (a0.y * t[0] + b0.y * t[1] + c0.y * t[2]) / (t[0] + t[1] + t[2]);
			if ( 0 <= srcX && srcX <= this.width - 1) {
						if ( 0 <= srcY && srcY <= this.height - 1 ) {
							rgb = this.query(srcX, srcY);
							this.target.setRGB(i, j, rgb);
						}
					}
				}
				
			}
		}
	};
	
BinlinearInterpolation.prototype.query = function ( x,   y) {
		
		 x1 = parseInt(Math.floor(x)); x2 = parseInt(Math.ceil(x));
		 y1 = parseInt(Math.floor(y));y2 = parseInt(Math.ceil(y));
		
		return source.getRGB(x1, y1);
};
