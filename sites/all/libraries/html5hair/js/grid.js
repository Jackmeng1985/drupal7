/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function Grid(p0,p1,p2,p3) {
 	this.p = new Array();
        this.p[0] = p0; this.p[1] = p1; this.p[2] = p2; this.p[3] = p3;
};
	
Grid.prototype.contains = function(i, j) {
    this.q = new Point(i, j);
	x1 = Point.cross3(this.p[0], this.p[1], this.q);
	x2 = Point.cross3(this.p[1], this.p[2], this.q);
	x3 = Point.cross3(this.p[2], this.p[3], this.q);
	x4 = Point.cross3(this.p[3], this.p[0], this.q);
	if ( x1 * x2 < 0 ) return false;
	if ( x1 * x3 < 0 ) return false;
	if ( x1 * x4 < 0 ) return false;
	return true;
};



