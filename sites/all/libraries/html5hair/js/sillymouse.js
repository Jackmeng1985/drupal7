function mousePressed(e) {
		Point []p = parent.p;
//		System.out.printf( "Silly Pressed on (%d, %d)%n", e.getX(), e.getY() );	
		
		Point q = new Point( e.getX(), e.getY() );
		for ( int i = 0; i < p.length; ++i ) {
			if ( p[i].InfintyNormDistanceTo(q) <= 20 ) {
				parent.p = new Point[ p.length - 1 ];
				for ( int j = 0, k = 0; j < p.length; ++j ) if ( i != j ) {
					parent.p[k++] = p[j];
				}
				parent.draw( parent.img, parent.p, q, true, parent.g );
				return;
			}
		}
	}
