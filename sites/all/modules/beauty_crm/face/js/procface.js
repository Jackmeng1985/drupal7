var isTouchSupported = 'ontouchstart' in window;
var startEvent = isTouchSupported ? 'touchstart' : 'mousedown';
var moveEvent = isTouchSupported ? 'touchmove' : 'mousemove';
var endEvent = isTouchSupported ? 'touchend' : 'mouseup';
window.opmode = 0;
window.hairposition = [];
window.hairscale = 1;
window.faceposition = [];
window.temppoint = [];



function changeHairPointsByXY(x, y){
    for(var i = 0; i< window.p.length; i++){
            window.p[i].x = window.p[i].x + x;
            window.p[i].y = window.p[i].y + y;
    }
 }


function changeHairPointsByScale(scale){
    for(var i = 0; i< window.p.length; i++){
        window.p[i].x = hair_points[i].x  * scale ;
        window.p[i].y = hair_points[i].y  * scale ;
   }
}


function drawPointsOnHair(ctx){
   var radius = 7;
  for(var i = 0; i<window.p.length; i++){
    ctx.beginPath();
    ctx.arc(window.p[i].x + window.hairposition['x'], window.p[i].y + window.hairposition['y'], radius, 0, 2 * Math.PI, false);
    ctx.fillStyle = 'green';
    ctx.fill();
    ctx.stroke();
  }


}



function drawfacePoint (x,y, color){
  var c=document.getElementById("face");
  var ctx=c.getContext("2d");
  var radius = 7;
  ctx.beginPath();
  ctx.arc(x, y, radius, 0, 2 * Math.PI, false);
  ctx.fillStyle = color;
  ctx.fill();
  ctx.stroke();
}


function drawHairEyes(){
  drawfacePoint(hair_eye_left.x, hair_eye_left.y, 'red');
  drawfacePoint(hair_eye_right.x, hair_eye_right.y, 'red');

}


function changeFaceScale(){ //change Face Canvas to 100% of screen
  c = document.getElementById('face');
  c.width = window.cwidth;
  c.height = window.cheight;
}

function changeHairScale(){ //change front hair Canvas to 100% of hair;
  c = document.getElementById('hairStyle');
  c.width = hair_width;
  c.height = hair_height;
}

function changeHairChangeScale(){ // we scale the screen to 100% of hair;
  c = document.getElementById('hairChange');
  c.width =  hair_width;
  c.height = hair_height;
}


function   initializeCanvas(){
        changeFaceScale();
        changeHairScale();
        changeHairChangeScale();
}



function drawHairStyle(){ //draw hair style on Canvas
  source = new Image();
  face_url = hair_url;
  source.src = face_url;


  c=document.getElementById("face");
  csx=c.getContext("2d");

  source.onload = function () {
   // csx.drawImage(source, 0, 0,face_width,face_height);
    drawHairEyes();
  }
}



function loadImages(sources, callback) {
        var images = {};
        var loadedImages = 0;
        var numImages = 0;
        // get num of sources
        for(var src in sources) {
          numImages++;
        }
        for(var src in sources) {
          images[src] = new Image();
          images[src].onload = function() {
            if(++loadedImages >= numImages) {
              callback(images);
            }
          };
          images[src].src = sources[src];
        }
}


function calculateHairPosition(){
  t_hair_position = [];
  t_hair_position['x'] = 0;
  t_hair_position['y'] = 0;
  //we first get the middle points between eyes of face.

  face_eye_center = [];
  console.log(face_position);
  face_eye_center['x'] = (face_position.eye_right.x + face_position.eye_left.x)/2 ;
  face_eye_center['y'] = (face_position.eye_right.y + face_position.eye_left.y)/2 ;
 ////we then get the middle points between eyes of hairstyle.

  hair_eye_center = [];
  hair_eye_center['x']  = (hair_eye_right.x + hair_eye_left.x) /2;
  hair_eye_center['y']  = (hair_eye_right.y + hair_eye_left.y) /2;

  console.log(face_eye_center);
  console.log(hair_eye_center);
  t_hair_position['x'] =  face_eye_center['x']  - hair_eye_center['x'] * window.hairscale ;
  t_hair_position['y'] =  face_eye_center['y']  - hair_eye_center['y'] * window.hairscale ;
  return t_hair_position;
}



function calculateHairScale(){

  face_scale = face_position.eye_right.x - face_position.eye_left.x;
  hair_scale = hair_eye_right.x-hair_eye_left.x;
// we first need to scale hair_scale according to screen;
//  initial_scale = hair_width /(window.cwidth);
  window.hairscale =  face_scale / hair_scale;

  return  ;
}


function changeScale(scale){

   window.hairscale = scale;
   changeHairPointsByScale(scale);

   var canvas = document.getElementById('face');
   var context = canvas.getContext('2d');

   context.clearRect(0, 0, canvas.width, canvas.height);
   getMergedImage(face_url, hair_url, window.faceposition,window.hairposition, window.hairscale);


}

function changePosition(x, y){
   window.hairposition['x'] = window.hairposition['x'] + x;
   window.hairposition['y'] = window.hairposition['y'] + y;

 //  changeHairPointsByXY(x, y);

   var canvas = document.getElementById('face');
   var context = canvas.getContext('2d');
   //context.clearRect(0, 0, canvas.width, canvas.height);
   getMergedImage(face_url, hair_url, window.faceposition,window.hairposition, window.hairscale );



}



function getMergedImage(face_url, hair_url, face_position, hair_position, hair_scale){//put hair sytle on top of face
  // first we need to get face image data

  canvas = document.getElementById('face');
  var context = canvas.getContext('2d');
  var sources = { face: face_url, hair: hair_url};

  loadImages(sources, function(images) {
       context.drawImage(images.face, face_position['x'],face_position['y'],face_width,face_height);;

       faceimgTargetData = context.getImageData(face_position['x'],face_position['y'],face_width, face_height);
       context.drawImage(images.hair, hair_position['x'],hair_position['y'],images.hair.width * hair_scale,images.hair.height * hair_scale);
       hairimgTargetData = context.getImageData(hair_position['x'],hair_position['y'],images.hair.width * hair_scale,images.hair.height * hair_scale);
       drawPointsOnHair(context);  //draw change points according to scale;
   });
 }


function getCurrentPointIndex(q){
  currentPoint = -1;
  x = q.x -  window.hairposition['x'];
  y = q.y -  window.hairposition['y'];
  k = new Point(x,y);
  for(var i = 0 ; i< window.p.length; i++){
        if (  window.p[i].InfintyNormDistanceTo(k) <= 20 ) {
             currentPoint = i;
             return i;
        }
  }
  return currentPoint;
}





function touchStart(event){
   event.preventDefault();
 // console.log(event);
   var touch =  isTouchSupported ? event.touches[0] : event;
    //we get the touch point data
   startX = touch.pageX;
   startY = touch.pageY;
   window.temppoint['x'] = startX; // this is used to move whole hairstyle
   window.temppoint['y'] = startY;

   q = new Point(startX, startY); //create an object for currrent point
   window.currentPointIndex = getCurrentPointIndex(q); // we get the point index
   if( window.currentPointIndex >= 0 ) { // here we do all work relative to point move
       if(window.qbak.length == 0){
         window.qbak = new Array();
         for (var i = 0, len = window.p.length; i < len; i++) {
         window.qbak[i] = new Point(window.p[i].x,window.p[i].y);
       }
     }
       return;
    } // this part is for change style
}




function touchMove(event){
    event.preventDefault();
    //alert(event.changedTouches[0].pageX);
    var touch =  isTouchSupported ? event.changedTouches[0] : event;

    startX = touch.pageX;
    startY = touch.pageY;

    if( window.currentPointIndex < 0 ){
      changeX = startX - window.temppoint['x'];
      changeY = startY - window.temppoint['y'];
      changePosition(changeX, changeY);
      window.temppoint['x'] = startX;
      window.temppoint['y'] = startY;
    } else {
       return;
    }
    return;
}

function touchEnd(event){
    event.preventDefault();
    //alert(event.changedTouches[0].pageX);
    var touch =  isTouchSupported ? event.changedTouches[0] : event;

    startX = touch.pageX;
    startY = touch.pageY;

    if( window.currentPointIndex > 0 ){
       movedPoint = new Point( parseInt((startX -  window.hairposition['x'])),parseInt((startY -  window.hairposition['y'])));
       work(movedPoint);  // we move the point
       window.currentPointIndex = -1;
    }
    return;
}

function initializeFaceData(face_url){
  canvas = document.getElementById('face');
  var context = canvas.getContext('2d');
  source = new Image();
  source.src = face_url;
  source.onload = function (){
    context.drawImage(source,0,0);
    window.faceImg = context.getImageData( 0, 0, window.cwidth , window.cheight);
//    context.clearRect(0, 0, canvas.width, canvas.height);
  }
}






(function($) {$(document).ready(
    function(){

       window.cwidth  = document.getElementsByTagName("body")[0].clientWidth  ;
       window.cheight =  document.getElementsByTagName("body")[0].clientHeight  ;
       console.log( window.cwidth) ;
        initializeCanvas();  //change canvas to proper width and height;

        face_url = '/sites/default/files/faces/'+ face_file;
        t_face_position = [];
        t_hair_position = [];
        t_face_position['x'] = 0;
        t_face_position['y'] = 0;
        //console.log(document.getElementsByTagName("body")[0].clientWidth);
       //console.log(document.getElementsByTagName("body")[0].clientHeight);

        t_hair_position['x'] = 0;
        t_hair_position['y'] = 0;
        t_hair_scale = 1;
        window.faceposition = t_face_position;
        //we need to calculate the position of hair style and scale;
        calculateHairScale();
        window.hairposition = calculateHairPosition();
        initializePoints(window.hairscale);  //put hair points into window.p, be noticed the point position is relative to upper-left of hairstyle
       // getMergedImage(face_url, hair_url, window.faceposition,window.hairposition, window.hairscale/10); //put hair sytle on top of face

//        window.hairposition['x'] = 0;
//        window.hairposition['y'] =0;
//        window.hairscale  = 1;

        $('.bar .scaleup'). click(function (){changeScale(window.hairscale + 0.01);});
        $('.bar .scaledown'). click(function (){changeScale(window.hairscale - 0.01);});
         initializeFaceData(face_url);

        //drawcanvas();
        //getMergedImage(face_url, hair_url, window.faceposition,window.hairposition, window.hairscale); //put hair sytle on top of face

        c=document.getElementById("face");
        c.addEventListener(startEvent, touchStart, false);
        c.addEventListener(moveEvent, touchMove, false);
        c.addEventListener(endEvent, touchEnd, false);

        return;
 });
})(jQuery);


