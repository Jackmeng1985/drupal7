/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function SimilarityDeformation (v,p,q,alpha) {
        var w = null;
	var pRelative = null;
	var qRelative = null;
	var A = null;
     
        //assert( p.length == q.length );
	if(!(p.length == q.length )) {alert('error 1'); return;}; 	
	n = p.length;
        
        
         if ( null == w || w.length < n ) {w = new Array(n);w[n-1]= undefined;}
	 if ( null == pRelative || pRelative.length < n ){pRelative = new Array(n); pRelative[n-1]=undefined;}
	 if ( null == qRelative || qRelative.length < n ){qRelative = new Array(n); qRelative[n-1]=undefined;} 
	 if ( null == A || A.length < n ){ A = new Array(n); A[n-1]= undefined;}
         
         for ( i = 0; i < n; ++i ) {
		tx = p[i].x - v.x;
		ty = p[i].y - v.y;
		w[i] = Math.pow( tx * tx + ty * ty , -alpha ); //a power(a,b)
	 }
	  pAverage = Point.average( p, w );
	  qAverage = Point.average( q, w );

         for ( i = 0; i < n; ++i ) {
	  pRelative[i] = p[i].subtract( pAverage );
	  qRelative[i] = q[i].subtract( qAverage );
	 }
		
	 mus = 0;
	 for (i = 0; i < n; ++i ) {
	   mus += w[i] * (pRelative[i].x * pRelative[i].x + pRelative[i].y * pRelative[i].y);
	 }
		
        Aright = (new Matrix22(
	  v.subtract(pAverage),
	  v.subtract(pAverage).orthogonal().negate()
	)).transpose();
		
	for ( i = 0; i < n; ++i ) {
	   Aleft = new Matrix22(
	     pRelative[i],
	     pRelative[i].orthogonal().negate()
	   );		
	  A[i] = Aleft.multiply_m( Aright ).multiply( w[i] );
	}
	
        r = qAverage;
	for (i = 0; i < n; ++i ) {
	  r = r.add( qRelative[i].multiply_m( A[i] ).divide(mus) );
        }
	 return r;
	}



