/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
// define global variable
var isTouchSupported = 'ontouchstart' in window;
var startEvent = isTouchSupported ? 'touchstart' : 'mousedown';
var moveEvent = isTouchSupported ? 'touchmove' : 'mousemove';
var endEvent = isTouchSupported ? 'touchend' : 'mouseup';

 
(function($) {$(document).ready(
    function(){  
        window.currentPointIndex = 1;
        //set up points for change; 
        source = new Image();
        source.src = window.oriImg; //the selected hair style
        var c=document.getElementById("hairChange");
        csx=c.getContext("2d");
        csx.drawImage(source,0,0); 
       try {
          window.imgData =  csx.getImageData( 0, 0, window.imgWidth, window.imgHeight).data;
          //now window.imgData contains the hairstyle data
        }catch (e) {alert(e.message);}    
          // c.addEventListener(startEvent, touchStart, false);
          // c.addEventListener(endEvent, touchEnd, false);
       var c=document.getElementById("hairStyle"); // the unchanged hair style canvas
           csx=c.getContext("2d"); 
           csx.drawImage(source,0,0);
           c.addEventListener(startEvent, touchStart, false); //add listener to see the point change
           c.addEventListener(endEvent, touchEnd, false);  //add listener to get the final point and start change
  //    drawFace();
 
  });
})(jQuery);
   


function drawFace(){ 
       var s = new Image();
           s.src = window.face;
      var c=document.getElementById("guo");
           csx=c.getContext("2d");
           csx.drawImage(s,facex,facey);  //finally we draw the face. 
      try {
          window.imgGuoData =  csx.getImageData( 0, 0,  window.imgWidth, window.imgHeight) ;
        }
        catch (e) {alert(e.message);}  ; 

}






function touchEnd(event){
    event.preventDefault();
    var touch =  isTouchSupported ? event.touches[0] : event;
    startX = touch.pageX;
    startY = touch.pageY;
     if($('input[name=radio-mini]:checked').val()=='getpoint' || $('input[name=radio-mini]:checked').val()=='setpoint') {
      return; 
    } 
    
    movedPoint = new Point(startX,startY);
    drawFace();
    work(movedPoint);

    return;
}


function touchStart(event) {
    event.preventDefault();
    var touch =  isTouchSupported ? event.touches[0] : event;
    //we get the touch point data
    startX = touch.pageX; 
    startY = touch.pageY;
  //  alert(startY);alert(startX);
    q = new Point(startX, startY); //create an object for currrent point
   
    if($('input[name=radio-mini]:checked').val()=='changestyle') {
       if(window.qbak.length == 0){
         window.qbak = new Array();
         for (var i = 0, len = window.p.length; i < len; i++) {
         window.qbak[i] = new Point(window.p[i].x,window.p[i].y);
       }
     }  
      window.currentPointIndex = getCurrentPointIndex(q); //this is the index of points to be moved 
      if(window.currentPointIndex >=0)
       {changeRed(window.qbak[currentPointIndex]);}
      return;
    } // this part is for change style
 
 /*   
    if($('input[name=radio-mini]:checked').val()=='setpoint'){  
        return;
    }
   */ 
    
    for(i = 0 ; i< window.p.length; i++){
        if (  window.p[i].InfintyNormDistanceTo(q) <= 20 ) {
             return;
      	}
    }    
     window.p[window.p.length] = q; // add the point to the array of preset points.

     var c=document.getElementById("hairStyle");
     var ctx=c.getContext("2d");
     var radius = 10; 
     ctx.beginPath();
     ctx.arc(parseInt(q.x), parseInt(q.y), radius, 0, 2 * Math.PI, false);
     ctx.fillStyle = 'green';
     ctx.fill(); 
     ctx.stroke(); //display the setting points.  
}

function initPoint(img,c,ctx){
     
    ctx.drawImage(img,0,0); 
    ctx.fillStyle="#FF0000";
    for(i=0;i<p.length;i++){
        q = p[i];
        ctx.fillRect(q.x,q.y,10, 10);
    }
    
} 


function drawPositions(ctx){
    var i;
    ctx.fillStyle="#FF0000";
    for(i=0;i<window.q.length;i++){
        point = window.q[i];
        ctx.fillRect(point.x,point.y,10, 10);
    }
    
} 



//public void draw(BufferedImage img, Point p[], Point q, boolean qOK, Grid []grid) {
function drawGrid(grid){
   var i;   
   var x=document.getElementById("hairStyle");
   var cxx=x.getContext("2d");  
  
   for(i=0; i<grid.length;i++){
	cxx.beginPath();
        cxx.moveTo(grid[i].p[0].x ,grid[i].p[0].y);
        cxx.lineTo(grid[i].p[1].x ,grid[i].p[1].y);
        cxx.lineTo(grid[i].p[2].x ,grid[i].p[2].y);
        cxx.lineTo(grid[i].p[3].x ,grid[i].p[3].y);
        cxx.lineTo(grid[i].p[0].x ,grid[i].p[0].y);
         cxx.closePath();
         cxx.stroke(); 
        } 	
}

function getCurrentPointIndex(q){
 currentPoint = -1;   

    for(var i = 0 ; i< window.qbak.length; i++){
        if (  window.qbak[i].InfintyNormDistanceTo(q) <= 20 ) {
             currentPoint = i;return i;
 	}
      }
  return currentPoint;    
}

function changeRed(q){
    var c=document.getElementById("hairStyle");
    var ctx=c.getContext("2d");
    var radius = 10; 
    ctx.beginPath();
    ctx.arc(parseInt(q.x), parseInt(q.y), radius, 0, 2 * Math.PI, false);
    ctx.fillStyle = 'red';
    ctx.fill(); 
    ctx.stroke();   
}

function drawPoints(points){
    var c=document.getElementById("hairStyle");
    var ctx=c.getContext("2d");
    var radius = 10;
    for(var i = 0; i<points.length;i++){
      q = new Point(points[i].x,points[i].y);
      ctx.beginPath();
      ctx.arc(parseInt(q.x), parseInt(q.y), radius, 0, 2 * Math.PI, false);
      ctx.fillStyle = 'green';
      ctx.fill(); 
   } 
   ctx.stroke();
}
function drawonePoint (q){
    window.p[window.p.length] = q;
     var c=document.getElementById("hairStyle");
     var ctx=c.getContext("2d");
     var radius = 10; 
      ctx.beginPath();
      ctx.arc(parseInt(q.x), parseInt(q.y), radius, 0, 2 * Math.PI, false);
      ctx.fillStyle = 'green';
      ctx.fill(); 
      ctx.stroke();   
}

function setP(){
    
    
    return;
}