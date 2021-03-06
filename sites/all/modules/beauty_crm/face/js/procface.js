var isTouchSupported = 'ontouchstart' in window;
var startEvent = isTouchSupported ? 'touchstart' : 'mousedown';
var moveEvent = isTouchSupported ? 'touchmove' : 'mousemove';
var temppoint = [];

function changeFaceScale(){ //change Face Canvas to 100% of screen
  c = document.getElementById('face');
  c.width = window.cwidth * 0.8;
  c.height = window.cheight;
}

function   initializeCanvas(){
        changeFaceScale();
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
  var t_hair_position = [];
  t_hair_position['x'] = 0;
  t_hair_position['y'] = 0;
  //we first get the middle points between eyes of face.

  var face_eye_center = [];
//  console.log(face_position);
  face_eye_center['x'] = (face_position.eye_right.x + face_position.eye_left.x)/2 ;
  face_eye_center['y'] = (face_position.eye_right.y + face_position.eye_left.y)/2 ;
 ////we then get the middle points between eyes of hairstyle.

  var hair_eye_center = [];
  hair_eye_center['x']  = (hair_eye_right.x + hair_eye_left.x) /2;
  hair_eye_center['y']  = (hair_eye_right.y + hair_eye_left.y) /2;

  t_hair_position['x'] =  face_eye_center['x']  - hair_eye_center['x'] * window.hairscale ;
  t_hair_position['y'] =  face_eye_center['y']  - hair_eye_center['y'] * window.hairscale ;
//  t_hair_position['x'] = t_hair_position['x'] < 0 ? 0 : t_hair_position['x'];
//  t_hair_position['y'] = t_hair_position['y'] < 0 ? 0 : t_hair_position['y'];
//  console.log(t_hair_position);
  return t_hair_position;
}



function calculateHairScale(){

  var face_scale = face_position.eye_right.x - face_position.eye_left.x;
  var hair_scale = hair_eye_right.x-hair_eye_left.x;
// we first need to scale hair_scale according to screen;
//  initial_scale = hair_width /(window.cwidth);
  window.hairscale =  face_scale / hair_scale;

  return  ;
}


function changeScale(scale, change){

   window.hairscale = scale + change;

   var canvas = document.getElementById('face');
   var context = canvas.getContext('2d');

   context.clearRect(0, 0, canvas.width, canvas.height);
   window.hairposition['x'] =  window.hairposition['x'] - hair_width * change /2;
   window.hairposition['y'] =  window.hairposition['y'] - hair_height * change /2;
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

  var canvas = document.getElementById('face');
  var context = canvas.getContext('2d');
  var sources = { face: face_url, hair: hair_url};

  loadImages(sources, function(images) {
       context.drawImage(images.face, face_position['x'],face_position['y'],face_width,face_height);;

//       faceimgTargetData = context.getImageData(face_position['x'],face_position['y'],face_width, face_height);
       context.drawImage(images.hair, hair_position['x'],hair_position['y'],images.hair.width * hair_scale,images.hair.height * hair_scale);
//       hairimgTargetData = context.getImageData(hair_position['x'],hair_position['y'],images.hair.width * hair_scale,images.hair.height * hair_scale);
//       drawPointsOnHair(context);  //draw change points according to scale;
       context.clearRect(0, face_height, 2000, 2000);
       context.clearRect(face_width, 0, 2000, 2000);
       
       context.clearRect(0, 0, 2000, window.ctop);
       context.clearRect(0, 0, window.cleft, 2000);
   });
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

   return;
}




function touchMove(event){
    event.preventDefault();
    //alert(event.changedTouches[0].pageX);
    var touch =  isTouchSupported ? event.changedTouches[0] : event;

    startX = touch.pageX;
    startY = touch.pageY;

      changeX = startX - window.temppoint['x'];
      changeY = startY - window.temppoint['y'];
      changePosition(changeX, changeY);
      window.temppoint['x'] = startX;
      window.temppoint['y'] = startY;
    return;
}

function savePicture (){
  var canvas = document.getElementById('face');
  var share_data = canvas.toDataURL('image/jpg');
  var link = document.getElementById('share');
  link.href = share_data;
  link.download = 'hair_' + Date.now() + '.jpg';
}





(function($) {$(document).ready(
    function(){

       window.cwidth  = document.getElementsByTagName("body")[0].clientWidth  ;
       window.cheight =  document.getElementsByTagName("body")[0].clientHeight  ;
       window.ctop =  $('#face').css('top');
       window.cleft =  $('#face').css('left');
//       console.log( window.cwidth) ;
        initializeCanvas();  //change canvas to proper width and height;

        var t_face_position = [];
        var t_hair_position = [];
        t_face_position['x'] = 0;
        t_face_position['y'] = 0;

        t_hair_position['x'] = 0;
        t_hair_position['y'] = 0;
        t_hair_scale = 1;
        window.faceposition = t_face_position;
        //we need to calculate the position of hair style and scale;
        calculateHairScale();
        window.hairposition = calculateHairPosition();


        $('.bar .scaleup'). click(function (){changeScale(window.hairscale,  0.05);});
        $('.bar .scaledown'). click(function (){changeScale(window.hairscale, -0.05);});
        $('.bar .share'). click(function (){savePicture();});

        //drawcanvas();
        
        getMergedImage(face_url, hair_url, window.faceposition,window.hairposition, window.hairscale); //put hair sytle on top of face

        $("#loading").hide();
        var c = document.getElementById("face");
        c.addEventListener(startEvent, touchStart, false);
        c.addEventListener(moveEvent, touchMove, false);
//        c.addEventListener(endEvent, touchEnd, false);

        return;
 });
})(jQuery);


