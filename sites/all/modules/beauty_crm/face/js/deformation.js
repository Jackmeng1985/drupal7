Config.AffineDeformation = {};



function reinitalizePoints(){
   for(var i = 0; i< window.qbak.length;i++){
       
      window.q[i] = new Point( window.realq[i].x,  window.realq[i].y); 
      window.qbak[i] = new Point(window.realqbak[i].x, window.realqbak[i].y); 
      window.p[i] = new Point(window.realqbak[i].x, window.realqbak[i].y); 
     }  
}


function drawHairOverFace(){
  
  var canvas = document.getElementById('face');
  var context = canvas.getContext('2d');     
  context.clearRect(0,0, canvas.width,canvas.height);
  var i,j;
  i = 0;
  j = 0;

  // draw face


  var imgData = context.createImageData(canvas.width, canvas.height);
   



  return;
}


function redrawFaceCanvas(skewedImg){
//first, we need to clear Canvas  
   
  var canvas = document.getElementById('face');
  var context = canvas.getContext('2d');     
  context.clearRect(0, 0, canvas.width, canvas.height);
  //we now put face image on the canvas

 canvas = document.getElementById('face');
  var context = canvas.getContext('2d');
  source = new Image(); 
  source.src = face_url;  
  source.onload = function (){
    context.drawImage(source,0,0); 
    overPart = context.getImageData(window.hairposition['x'],window.hairposition['y'], hair_width * window.hairscale ,hair_height* window.hairscale );
   
    var destImg = context.createImageData(hair_width * window.hairscale ,hair_height* window.hairscale );
    bilinear(skewedImg, destImg, window.hairscale);
    //we now put face image on the canvas
    for (var i=0;i<overPart.data.length;i+=4)
    { 
      if(destImg.data[i]==0  && destImg.data[i+1] ==0  && destImg.data[i+2]==0 || destImg.data[i+3]<170){ 
        destImg.data[i]=overPart.data[i];
        destImg.data[i+1]=overPart.data[i+1];
        destImg.data[i+2]=overPart.data[i+2];
        destImg.data[i+3]= overPart.data[i+3];
     }
   }  
   context.putImageData(destImg,window.hairposition['x'],window.hairposition['y']);
   drawFacePoints(window.p); 
 }
}


function drawFaceandHair(scaledImg){ 
   source = new Image();
  source.src = scaledImg;
  
 

 }


function drawhairStylePoints(points){
    var c=document.getElementById("hairStyle");
    var ctx=c.getContext("2d");
    var radius = 7;
    for(var i = 0; i<points.length;i++){
      q = new Point(points[i].x,points[i].y);
      ctx.beginPath();
      ctx.arc(parseInt(q.x), parseInt(q.y), radius, 0, 2 * Math.PI, false);
      ctx.fillStyle = 'green';
      ctx.fill(); 
   } 
   ctx.stroke();
}

function drawhairChangePoints(points){

    var c=document.getElementById("hairChange");
    var ctx=c.getContext("2d");
    var radius = 7;
    for(var i = 0; i<points.length;i++){
      q = new Point(points[i].x,points[i].y);
      ctx.beginPath();
      ctx.arc(parseInt(q.x), parseInt(q.y), radius, 0, 2 * Math.PI, false);
      ctx.fillStyle = 'red';
      ctx.fill(); 
   } 
   ctx.stroke(); 
}

  
 function drawFacePoints(points){
  var c=document.getElementById("face");
    var ctx=c.getContext("2d");
    var radius = 5;
    for(var i = 0; i<points.length;i++){
      q = new Point(points[i].x,points[i].y);
      ctx.beginPath();
      ctx.arc(parseInt(q.x + window.hairposition['x']), parseInt(q.y + window.hairposition['y']), radius, 0, 2 * Math.PI, false);
      ctx.fillStyle = 'red';
      ctx.fill(); 
   } 
   ctx.stroke();  
 }



function work(qpoint) {	
    var i;
    window.q = new Array();
    for (var i = 0, len = window.qbak.length; i < len; i++) {
      window.q[i] = new Point(window.qbak[i].x,window.qbak[i].y);
    }

    window.q[window.currentPointIndex] = new Point(qpoint.x,qpoint.y);
    window.qbak[window.currentPointIndex] = new Point(qpoint.x,qpoint.y); //both q and qbak stored the changed point information
    
    real_hair_width =  hair_width * window.hairscale;
    real_hair_height = hair_height * window.hairscale;
   
    window.realp = new Array();
    window.realq = new Array();
    window.realqbak = new Array();

    
   
    for(var i = 0; i< window.qbak.length;i++){
      x = (window.q[i].x )/ real_hair_width * window.canvasw;
      y = (window.q[i].y )/ real_hair_height * window.canvash;
      window.realq[i] = new Point(window.q[i].x, window.q[i].y); 
      window.q[i] = new Point(parseInt(x), parseInt(y)); 
    
      x = (window.qbak[i].x )/ real_hair_width * window.canvasw;
      y = (window.qbak[i].y)/ real_hair_height * window.canvash;
      window.realqbak[i] = new Point(window.qbak[i].x, window.qbak[i].y); 
      window.qbak[i] = new Point(parseInt(x), parseInt(y)); 
    
      x = (window.p[i].x )/ real_hair_width * window.canvasw;
      y = (window.p[i].y )/ real_hair_height * window.canvash;
      window.realp[i] = new Point(window.p[i].x, window.p[i].y); 
      window.p[i] = new Point(parseInt(x), parseInt(y)); 
     }
   
    // at this point, we make a copy of window.p, q. and qbak a backup in realp,q, qbak
    

    //drawhairChangePoints(window.qbak);
 
    for ( i = 0; i < window.g.length; ++i ) {
        window.gTrans[i] = new Grid(//calculate grid, from original grid g to newG
	        new AffineDeformation( window.g[i].p[0] , window.p, window.q, Config.alpha),
          new AffineDeformation( window.g[i].p[1] , window.p, window.q, Config.alpha),
          new AffineDeformation( window.g[i].p[2] , window.p, window.q, Config.alpha),
          new AffineDeformation( window.g[i].p[3] , window.p, window.q, Config.alpha)
	     );
    }
     
     Config.binlinearInterpolation = new BinlinearInterpolation();
     var t1 = new Date();
     var n1 = t1.getTime(); 
     img = null;
     skewedImg = Config.binlinearInterpolation.generate(img, hair_url, window.g, window.gTrans);		
    
     reinitalizePoints();
     redrawFaceCanvas(skewedImg);
       
      var t2 = new Date();
     var n2 = t2.getTime()-n1;  


     window.g = new Array();
     for ( var i = 0; i < window.canvasw ; i += Config.gridLength ) {
       for ( var j = 0; j < window.canvash ; j += Config.gridLength ) {
         a = new Point(i,j);
         b = new Point(i + Config.gridLength, j);
         c = new Point(i + Config.gridLength, j + Config.gridLength);
         d = new Point(i, j + Config.gridLength);
         window.g[window.g.length]= new Grid(a,b,c,d);
     }
   }
        
         
}