/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
 
function Matrix22( N11,  N12,  N21,   N22) {
		this.M11 = N11; this.M12 = N12;
		this.M21 = N21; this.M22 = N22;

    
}

Matrix22.prototype.Matrix_p = function (a,b){ 
    return new Matrix22(a.x,a.y,b.x,b.y);
};


Matrix22.prototype.adjugate = function(){
	return new Matrix22(
			this.M22, -1*this.M12,
			-1*this.M21, this.M11);
};	
	
Matrix22.prototype.determinant = function() {
	return this.M11 * this.M22 - this.M12 * this.M21;
};        

Matrix22.prototype.divide = function(d) {   
   return this.multiply(1.0 / d);
};

Matrix22.prototype.multiply = function(m){
     return new Matrix22(
			this.M11 * m, this.M12 * m,
			this.M21 * m, this.M22 * m
		);
};

Matrix22.prototype.multiply_m = function ( o ) {
		return new Matrix22(
				this.M11 * o.M11 + this.M12 * o.M21, this.M11 * o.M12 + this.M12 * o.M22,
				this.M21 * o.M11 + this.M22 * o.M21, this.M21 * o.M12 + this.M22 * o.M22 
		);
};

Matrix22.prototype.transpose = function() {
		return new Matrix22(
				this.M11, this.M21,
				this.M12, this.M22
		);
};

Matrix22.prototype.add_m = function (o) {
  return new Matrix22(
			this.M11 + o.M11, this.M12 + o.M12,
			this.M21 + o.M21, this.M22 + o.M22
		);
};

Matrix22.prototype.inverse = function() {
     var dm = this.determinant();
     adj = this.adjugate();
	return adj.divide( dm );
};

Matrix22.prototype.equals = function(o ) {
  return Math.abs( this.M11 - o.M11 ) < Config.eps
	 && Math.abs( this.M12 - o.M12 ) < Config.eps
	 && Math.abs( this.M21 - o.M21 ) < Config.eps
	 && Math.abs( this.M22 - o.M22 ) < Config.eps;
};

 var ZERO_M = new Matrix22(0, 0, 0, 0);
 var E = new Matrix22(1, 0, 0, 1);