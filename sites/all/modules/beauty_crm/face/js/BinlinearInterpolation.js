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

BinlinearInterpolation.prototype.generate = function(target, source, fromGrid,  toGrid) {
      if (source == null ){return;} 
      //this.width =  window.imgWidth;
      //this.height = window.imgHeight;

      this.width = window.canvasw;
      this.height = window.canvash; 
      this.len = this.width * this.height;
     
      this.source = new Image();
      this.source.src = source; 
      var i,j; 
   
      var load = false;
      this.source.onload = function (){
         load = true;
      } ;
      var myVar = setInterval(function(){myTimer()}, 80);
    
      function myTimer() {
      }

     function myStopFunction() { 
        if (load) clearInterval(myVar);
      }
     

      var cs=document.getElementById("hairChange");
      this.csx=cs.getContext("2d");
      this.csx.drawImage(this.source,0,0);
      
      try {
          this.imgData = this.csx.getImageData( 0, 0, this.width, this.height).data; 
      }
        catch (e) {alert(e.message)}      
     //  this.imgData = window.imgData;
       var ct=document.getElementById("hairStyle");
       this.ctx=ct.getContext("2d"); 
       this.imgTargetData = this.ctx.createImageData(this.width,this.height);  
          
    for (i = 0; i < toGrid.length; ++i ) {
      fg = fromGrid[i];  
      tg = toGrid[i];  
      this.fill( tg.p[0], tg.p[1], tg.p[2], fg.p[0], fg.p[1], fg.p[2] ); //fill the triangle
      this.fill( tg.p[2], tg.p[3], tg.p[0], fg.p[2], fg.p[3], fg.p[0] ); //fill     
    }  
       
     // this.ctx.putImageData(this.imgTargetData, 0, 0);
      return this.imgTargetData;
   };

 BinlinearInterpolation.prototype.fill = function (a,  b,  c,  a0,  b0,   c0 ) {
      var x0,x1,y0,y1,i,j,t;
      var srcX, srcY;
	    x0 = Math.floor( Util.minX(a, b, c)); 
      x1 = Math.ceil( Util.maxX(a, b, c) );
	    y0 = Math.floor( Util.minY(a, b, c)); 
      y1 = Math.ceil( Util.maxY(a, b, c) ); 
      x0 = Math.max(x0, 0); x1 = Math.min(x1,  this.width - 1 );
	    y0 = Math.max(y0, 0); y1 = Math.min(y1,  this.height - 1 );
	    for ( i = x0; i <= x1; ++i ) {
	   for (j = y0; j <= y1; ++j) {  
               //double []t = Point.TriangleContainsPoint(a, b, c, new Point(i, j) );
              // z = new Point(0,0);
        t = ZERO.TriangleContainsPoint(a, b, c, new Point(i, j) ); 
        if ( t[1] >= 0 && t[2] >= 0 ) {
		      srcX = (a0.x * t[0] + b0.x * t[1] + c0.x * t[2]) / (t[0] + t[1] + t[2]);
		     srcY = (a0.y * t[0] + b0.y * t[1] + c0.y * t[2]) / (t[0] + t[1] + t[2]);
                 if ( 0 <= srcX && srcX <= this.width - 1) {
		if ( 0 <= srcY && srcY <= this.height - 1 ) {
      rgb = this.query(srcX, srcY);//************************
      if(rgb.data[0]==0  && rgb.data[1] ==0  && rgb.data[2]==0 || rgb.data[3]<155){ 
      /*
        this.imgTargetData.data[((j * this.width) + i) * 4] =  window.imgGuoData.data[((j * this.width) + i) * 4] + Math.floor(rgb.data[0]*0.1) ; 
        this.imgTargetData.data[((j * this.width) + i) * 4 + 1] = window.imgGuoData.data[((j * this.width) + i) * 4+1] + Math.floor(rgb.data[1]*0.1) ;
        this.imgTargetData.data[((j * this.width) + i) * 4 + 2] = window.imgGuoData.data[((j * this.width) + i) * 4+2] + Math.floor(rgb.data[2]*0.1);
        this.imgTargetData.data[((j * this.width) + i) * 4 + 3] = window.imgGuoData.data[((j * this.width) + i) * 4+3]  + Math.floor(rgb.data[3]*0.1) ;
      */
                        this.imgTargetData.data[((j * this.width) + i) * 4] =   rgb.data[0] ;
                        this.imgTargetData.data[((j * this.width) + i) * 4 + 1] = rgb.data[1],
                        this.imgTargetData.data[((j * this.width) + i) * 4 + 2] = rgb.data[2];
                        this.imgTargetData.data[((j * this.width) + i) * 4 + 3] = rgb.data[3];
       } else{  
		                    this.imgTargetData.data[((j * this.width) + i) * 4] =   rgb.data[0] ;
                        this.imgTargetData.data[((j * this.width) + i) * 4 + 1] = rgb.data[1],
                        this.imgTargetData.data[((j * this.width) + i) * 4 + 2] = rgb.data[2];
                        this.imgTargetData.data[((j * this.width) + i) * 4 + 3] = rgb.data[3];
                      }
         
		      }
		    }
		}
				
			}
		}
	};
	
BinlinearInterpolation.prototype.query= function( x,  y) {
  var x1,x2,y1,y2;
   x1 = parseInt(Math.floor(x)); x2 = parseInt(Math.ceil(x));
   y1 = parseInt(Math.floor(y)); y2 = parseInt(Math.ceil(y));
   
 
 //((mouseY * canvas.width) + mouseX) * 4;
 
   r11 = this.imgData[ (( y1*this.width)+x1) *4]; 
   r12 = this.imgData[ (( y2*this.width)+x1) *4 ];
   r21 = this.imgData[ (( y1*this.width)+x2) *4 ];
   r22 = this.imgData[ (( y2*this.width)+x2) *4  ];
   g11 = this.imgData[ (( y1*this.width)+x1) *4 +1 ]; 
   g12 = this.imgData[ (( y2*this.width)+x1) *4 + 1 ];
   g21 = this.imgData[ (( y1*this.width)+x2) *4  + 1];
   g22 = this.imgData[ (( y2*this.width)+x2) *4  + 1];
   b11 = this.imgData[ (( y1*this.width)+x1) *4 + 2 ]; 
   b12 = this.imgData[ (( y2*this.width)+x1) *4 + 2 ];
   b21 = this.imgData[ (( y1*this.width)+x2) *4  + 2 ];
   b22 = this.imgData[ (( y2*this.width)+x2) *4  + 2 ];
   a11 = this.imgData[ (( y1*this.width)+x1) *4 + 3]; 
   a12 = this.imgData[ (( y2*this.width)+x1) *4 + 3 ];
   a21 = this.imgData[ (( y1*this.width)+x2) *4  + 3 ];
   a22 = this.imgData[ (( y2*this.width)+x2) *4  + 3 ];
 
    
   
   r = r11 * (x2 - x) * (y2 - y) + r21 * (x - x1) * (y2 - y) + r12 * (x2 - x) * (y - y1) + r22 * (x - x1) * (y - y1)/(( x2 - x1 ) * (y2 - y1));;
   g = g11 * (x2 - x) * (y2 - y) + g21 * (x - x1) * (y2 - y) + g12 * (x2 - x) * (y - y1) + g22 * (x - x1) * (y - y1)/(( x2 - x1 ) * (y2 - y1));
   b = b11 * (x2 - x) * (y2 - y) + b21 * (x - x1) * (y2 - y) + b12 * (x2 - x) * (y - y1) + b22 * (x - x1) * (y - y1)/(( x2 - x1 ) * (y2 - y1));
   a = a11 * (x2 - x) * (y2 - y) + a21 * (x - x1) * (y2 - y) + a12 * (x2 - x) * (y - y1) + a22 * (x - x1) * (y - y1)/(( x2 - x1 ) * (y2 - y1));

   
  
   var c = new Object();
   c.data = new Array(parseInt(r), parseInt(g), parseInt(b), parseInt(a));	//get new RGB
   return c;
};

