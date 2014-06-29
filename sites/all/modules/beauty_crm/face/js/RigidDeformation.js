

function RigidDeformation(v, p, q, alpha) {
    var w = null; 
    var pRelative = null;
    var qRelative = null;
    var A = null;		
    
    n = p.length;

    if ( null == w || w.length < n ) {w = new Array(n);w[n-1]= undefined;}
    if ( null == pRelative || pRelative.length < n ){pRelative = new Array(n); pRelative[n-1]=undefined;}
    if ( null == qRelative || qRelative.length < n ){qRelative = new Array(n); qRelative[n-1]=undefined;} 
    if ( null == A || A.length < n ){ A = new Array(n); A[n-1]= undefined;}
    		
    for (i = 0; i < n; ++i ) {
	t = p[i].subtract( v );
	w[i] = Math.pow( t.x * t.x + t.y * t.y , -alpha );
    }
    pAverage = Point.average_pd( p, w );
    qAverage = Point.average_pd( q, w );
    for ( i = 0; i < n; ++i ) {
      pRelative[i] = p[i].subtract( pAverage );
      qRelative[i] = q[i].subtract( qAverage );
    }
		
     Aright = (new Matrix22(
                 v.subtract(pAverage),
		 v.subtract(pAverage).orthogonal().negate()
		)).transpose(); 
                    
		for(i = 0; i < n; ++i ) {
		   Aleft = new Matrix22(
					pRelative[i],
					pRelative[i].orthogonal().negate()
		 );		
		    A[i] = Aleft.multiply_m(Aright).multiply( w[i] );
		}
		
		fr =  ZERO;
		for ( i = 0; i < n; ++i ) {
		  fr = fr.add( qRelative[i].multiply_m(A[i]) );
		}
		
		r = fr.multiply_d(v.subtract(pAverage).length() / fr.length() ).add( qAverage );
		
		return r;
	}
	
 
