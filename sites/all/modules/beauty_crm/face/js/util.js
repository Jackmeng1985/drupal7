/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


function Util() {
};

Util.prototype.min = function ( x, y, z ) {
	return Math.min( Math.min(x, y), z);
};
Util.prototype.max = function(x,y, z ) {
		return Math.max( Math.max(x, y), z);
};
Util.prototype.minX = function(  a,  b,   c ) {
		return this.min( a.x, b.x, c.x );
};
Util.prototype.maxX = function(  a,   b,   c ) {
		return this.max( a.x, b.x, c.x );
};
Util.prototype.minY = function(  a,  b,   c ) {
		return this.min( a.y, b.y, c.y );
	};
Util.prototype.maxY = function( a,  b,   c ) {
		return this.max( a.y, b.y, c.y );
};

