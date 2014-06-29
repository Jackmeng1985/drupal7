/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


 function AffineDeformation( v,  p,  q,  alpha) {//( window.g[i].p[0] , window.p, window.q, Config.alpha)
         this.w = null;
	 this.pRelative = null;
	 this.qRelative = null;
	 this.A = null;
         var i,nx;
         if(!(p.length == q.length )) {alert('error 1'); return;}; 
	 nx= p.length;
         
         this.n = nx;  
         if ( null == this.w || this.w.length < this.n ) 
           {this.w = new Array(this.n);this.w[this.n-1]= undefined;}
	 if ( null == this.pRelative || this.pRelative.length < this.n )
           {this.pRelative = new Array(this.n); this.pRelative[this.n-1]=undefined;}
	 if ( null == this.qRelative || this.qRelative.length < this.n )
            {this.qRelative = new Array(this.n); this.qRelative[this.n-1]=undefined;} 
	 if ( null == this.A || this.A.length < this.n )
            { this.A = new Array(this.n); this.A[this.n-1]= undefined;}
      
         for (  i = 0; i < this.n; ++i ) {
		t = p[i].subtract(v );
		this.w[i] = Math.pow( t.x * t.x + t.y * t.y , -alpha );
	 }
         
           pAverage = ZERO.average_pd(p, this.w  );
	   qAverage = ZERO.average_pd(q, this.w );
	//********************	
	   for (  i = 0; i < this.n; ++i ) {
		this.pRelative[i] = p[i].subtract( pAverage );
		this.qRelative[i] = q[i].subtract( qAverage );
	   } 
            
           B = new Matrix22(0,0,0,0);
             
	   for (  i = 0; i < this.n; ++i ) {
	     B = B.add_m(this.pRelative[i].ThisTransposeMultiplyOtherMultiplyThis(this.w[i]) );
	   }
		
    
           B = B.inverse();
          
           for ( j = 0; j < this.n; ++j ) {
	      this.A[j] = v.subtract(pAverage).multiply(B).multiplyOtherTranspose(this.pRelative[j]) * this.w[j];
	    }
         
	     r = qAverage; //r is an point 
	   for (  j = 0; j < this.n; ++j ) {
	     r = r.add( this.qRelative[j].multiply_d(this.A[j]) );
	   }
	   return r;
	}
	
	
 
