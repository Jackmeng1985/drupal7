  function mainprog(){
     var serialVersionUID = 5773907634885296879;
     var fDrawGrid = false; //if draw grid;
     var gMouseAdapter ;
     var sillyMouseAdapter;
     var convertKeyListener;
     var img;  // 
     var oriImg; //original image
     var displayImg; //displayed image
     var width, height;
     var label; //canvas
     var status = 0;  //edit or drag status
     var p = array(); //original points
     q = array(); //new positions
     var g, gTrans, lastGrid = null; //g: original grids, new grid transitions, 
  }	
  
  mainprog.prototype.main = function() {
      //String osName = System.getProperty("os.name");
      //System.out.println( "You are running on " + osName );
	this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	this.setTitle("AffineDeformation");
       
        var img=new Image();
        img.src="images/hair.png";       
        
        var c=document.getElementById("hairStyle");
         
        screenSize.width = $(window).width();
        screenSize.height = $(window).height();
       	imgWidth = screenSize.width;
        imgHeight = ScreenSize.height;
        
        graph = c.getContext("2d"); //get context
	graph.drawImage(img,0,0);
		
	label = new Image();
        label.src = "images/hair.png";	
        vg = new array();
	
        for ( i = 0; i < imgWidth; i += Config.gridLength ) {
	  for ( j = 0; j < imgHeight; j += Config.gridLength ) {
            vg[vg.length]=new Grid(new Point(i, j), 
			new Point(i + Config.gridLength, j),
			new Point(i + Config.gridLength, j + Config.gridLength), 
			new Point(i, j + Config.gridLength)
		)
          }
        }
	
      g = vg;
      this.draw( this.img, this.g );// initialize grid p[];
 //***     label.addMouseListener( sillyMouseAdapter );
 //***     label.addMouseMotionListener( sillyMouseAdapter );
  //***    this.addKeyListener( convertKeyListener );
}
	
mainprog.prototype.draw = function( img,  grid) {
	draw( img, this.p, null, false, grid ); //p is the cross x point array, grid is the grid
}

//public void draw(BufferedImage img, Point p[], Point q, boolean qOK, Grid []grid)	
mainprog.prototype.drawhair = function( img,  p ,  q,   qOK,  grid) {
    this.img = img;
    if ( displayImg == null || 
         displayImg.getWidth() != img.getWidth() 
          || displayImg.getHeight() != img.getHeight() ) {
	displayImg = BufferedImageHelper.newBufferdImage(width, height);
    } else {
	for ( i = 0; i < this.width; ++i ) {
	  for (  j = 0; j < this.height; ++j ) {
		this.displayImg.setRGB(i, j, 0);
	  }
	}
    }
	img = displayImg;		

	Graphics2D graph = (Graphics2D) img.getGraphics();
		
	graph.drawImage( this.img,  0, 0, null );
	graph.setStroke( new BasicStroke((2.0f) ));
	graph.setColor( Color.RED );

	for ( int i = 0; i < p.length; ++i ) {
			graph.drawLine( (int)(p[i].x - 10), (int)(p[i].y - 10), 
							(int)(p[i].x + 10), (int)(p[i].y + 10));
			graph.drawLine( (int)(p[i].x + 10), (int)(p[i].y - 10), 
							(int)(p[i].x - 10), (int)(p[i].y + 10));
		}
		if ( q != null ) {
			if ( !qOK ) graph.setColor( Color.BLUE );
			graph.drawLine( (int)(q.x - 10), (int)(q.y - 10), 
					(int)(q.x + 10), (int)(q.y + 10));
			graph.drawLine( (int)(q.x + 10), (int)(q.y - 10), 
					(int)(q.x - 10), (int)(q.y + 10));
			
		}
		do {
			graph.setColor( Color.BLACK );
			graph.drawLine(0, 0, 0, img.getHeight() );			
			graph.drawLine(0, img.getHeight(), img.getWidth(), img.getHeight() );			
			graph.drawLine(img.getWidth(), img.getHeight(), img.getWidth(), 0 );			
			graph.drawLine(img.getWidth(), 0, 0, 0 );			
		} while (false);
		
		lastGrid = grid;
		if ( grid != null && fDrawGrid ) {
			graph.setStroke( new BasicStroke((1.0f) ));
			graph.setColor( Color.GRAY );
			for ( Grid g : grid ) {
				graph.drawLine(  (int)g.p[0].x , (int)g.p[0].y, (int)g.p[1].x, (int)g.p[1].y);
				graph.drawLine(  (int)g.p[1].x , (int)g.p[1].y, (int)g.p[2].x, (int)g.p[2].y);
				graph.drawLine(  (int)g.p[2].x , (int)g.p[2].y, (int)g.p[3].x, (int)g.p[3].y);
				graph.drawLine(  (int)g.p[3].x , (int)g.p[3].y, (int)g.p[0].x, (int)g.p[0].y);
			}
		}
		
		graph.dispose();
		
		this.label.setIcon( new ImageIcon(img) );		
		
	} 

}