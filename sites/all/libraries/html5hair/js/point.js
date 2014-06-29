/* 
 * This defines Point
 * and open the template in the editor.
 * 
 */

function Point(x,y){
    this.x  = x;
    this.y = y; 
}

Point.prototype.add = function(o){
     return new Point(this.x+ o.x,this.y+o.y );
    
};


Point.prototype.subtract = function(o) {
    return new Point( this.x - o.x, this.y - o.y );
};

Point.prototype.cross = function(o){  
   return this.x * o.y - this.y * o.x;
};

 
Point.prototype.cross3 = function(a,b,c){
     return b.subtract(a).cross(c.subtract(a));
 };
 
Point.prototype.negate = function() {
  return new Point(-1*this.x, -1*this.y);
} ;

Point.prototype.length = function() {
  return( Math.sqrt((this.x * this.x)+ (this.y * this.y)) || 0);
  
};
 
Point.prototype.ThisTransposeMultiplyOtherMultiplyThis = function(w){
    return (new Matrix22(
			this.x * this.x * w, this.x * this.y * w,
			this.y * this.x * w, this.y * this.y * w 
		)); 
};
 
Point.prototype.ThisTransposeMultiplyOther = function( o ) {
		return new Matrix22(
			this.x * o.x, this.x * o.y,
			this.y * o.x, this.y * o.y 
		);
} ;

Point.prototype.multiplyOtherTranspose = function( o ) {
	return this.x * o.x + this.y * o.y;
};

Point.prototype.multiply = function ( o ) {
		return new Point(
			this.x * o.M11 + this.y * o.M21, this.x * o.M12 + this.y * o.M22
		);
};
	
Point.prototype.multiply_d = function(o) {
		return new Point(
			this.x * o, this.y * o
		);
}  ;      

Point.prototype.average = function ( p) {
		var x = 0;
                var y = 0;
		for (  i = 0; i < p.length;  i++ ) {
			x += p[i].x;
			y += p[i].y;
		}
		x /= p.length;
		y /= p.length;
		return new Point( x, y );
	};
        
Point.prototype.average_pd = function( p,  w ) { 
   var i;   
   var sx = 0, sy = 0, sw = 0;
   
     for ( i = 0; i < p.length; i++ ) {
		sx += p[i].x * w[i];
		sy += p[i].y * w[i];
		sw += w[i];
	}
     return new Point( sx / sw, sy / sw );
};        
        
Point.prototype.TriangleContainsPoint = function ( a, b, c, o) {
    var xa,xb,xc, ya,yb,yc,d,d1,d2;
    
		 xa = a.x - o.x; ya = a.y - o.y;
		 xb = b.x - o.x; yb = b.y - o.y;
		 xc = c.x - o.x; yc = c.y - o.y;
		
		 d = xb * yc -    xc * yb;
		d1 = -xa * yc -  xc * -ya;
		d2 = xb * -ya - -xa * yb;
		
		return new Array(1, d1/d, d2/d);
		
 
	};
        
Point.prototype.InfintyNormDistanceTo = function (  o ) {
		return Math.max( Math.abs(this.x - o.x), Math.abs(this.y - o.y) );
	}
        
Point.prototype.equals = function( o ) {
		return ((this.x == o.x) && (this.y == o.y));
	};
        
Point.prototype.orthogonal = function() {
		return new Point(-this.y, this.x);
	};
        
Point.prototype.divide = function(mus) {
		return this.multiply_d( 1.0 / mus );
};
	

ZERO =  new Point(0, 0);

        
