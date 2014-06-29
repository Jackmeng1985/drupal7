<?php
require_once 'facepp_sdk.php';
require_once 'setparameters.php';
if ($_FILES["file"]["error"] > 0) {
  echo "Error: " . $_FILES["file"]["error"] . "<br>";
} else{
  $m = getcwd();
  $face_name = 'face_' . rand(1, 1000000) . '_' . $_FILES["file"]["name"];
  $thumb_face_name = 'thumb_' . $face_name;
  $target_path =  $m . '/faces/' . $face_name;
  $thumb_path = $m . '/faces/' . $thumb_face_name;
  move_uploaded_file($_FILES["file"]["tmp_name"], $target_path);

  $w = $_GET['w'];
  $w = $w;
  // Get new sizes
  list($width, $height) = getimagesize($target_path);
  $percent = $w/$width;

  //旋转方向
  $exif = exif_read_data($target_path);
  if(!empty($exif['Orientation']) && $exif['Orientation'] == 6) {
    $percent = $w/$height;
  }
  $newwidth = $width * $percent;
  $newheight = $height * $percent;
  // Load
  $thumb = imagecreatetruecolor($newwidth, $newheight);
  $source = imagecreatefromjpeg($target_path);

  // Resize
  imagecopyresized($thumb, $source, 0, 0, 0, 0, $newwidth, $newheight, $width, $height);

  if(!empty($exif['Orientation']) && $exif['Orientation'] == 6) {
    $thumb = imagerotate($thumb, -90, 0);
  }
  // Output
  imagejpeg($thumb, $thumb_path);
  //Destroy
  imagedestroy($thumb);

  $_SESSION['face'] = $thumb_face_name;
}

$facepp = new Facepp();

#detect local image
$params = array('img' => $thumb_path);
$params['attribute'] = 'glass,pose';
$response = $facepp->execute('/detection/detect',$params);
$body = json_decode( $response['body']);
$face_width = $body->img_width;
$face_height = $body->img_height;
$face = $body->face[0]->position;

?>

<script>
face_file = "<?php print($thumb_face_name) ;?> ";
face_position =  <?php print_r(json_encode($face)); ?>;
face_width =  "<?php print($face_width) ;?> ";
face_height =  "<?php print($face_height) ;?> ";
hair_url = "<?php print($_SESSION['hairstyle']) ;?> ";
hair_points =<?php print($_SESSION['stylepoints']) ;?> ;

hair_eye_left = <?php print($_SESSION['$style_eye_left']) ;?> ;
hair_eye_right = <?php print($_SESSION['$style_eye_right']) ;?>

hair_width = "<?php print($_SESSION['style_width']) ;?> ";
hair_height = "<?php print($_SESSION['style_height']) ;?> ";




 //console.log(hair_points);
 </script>

 <!--
To change this template, choose Tools | Templates
and open the template in the editor.
-->
<!DOCTYPE html>
<html>
  <head>
        <title></title>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
        <link rel="stylesheet" type="text/css" href="css/jquery.mobile-1.3.2.min.css" />
        <link rel="stylesheet" type="text/css" href="css/haircontrol.css" /> 
        <script type="text/javascript" src="js/jquery-1.9.1.min.js"></script>
        <script type="text/javascript" src="js/point.js"></script> 
        <script type="text/javascript" src="js/grid.js"></script> 
        <script type="text/javascript" src="js/Matrix22.js"></script>  
        <script type="text/javascript" src="js/util.js"></script>  
         <script type="text/javascript" src="js/billinearinterpolation.js"></script>  
        <script type="text/javascript" src="js/configuration.js"></script>  
        <script type="text/javascript" src="js/AffineDeformation.js"></script>
        <script type="text/javascript" src="js/BinlinearInterpolation.js"></script>  
        <script type="text/javascript" src="js/deformation.js"></script>
        <script type="text/javascript" src="js/procface.js"></script> 
        
  </head>
  <body>
       <canvas id="face" width="600" height = "600"> </canvas>
       <canvas id ="hairChange" width="448" height="733" > </canvas>   
       <canvas id="hairStyle" width="448" height="733"></canvas>


       <button id='move'> 移动</button>
       <button id='scaleup'> 增大 </button>
       <button id='scaledown'> 减小 </button>
       
  </body>
</html>




