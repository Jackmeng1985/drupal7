<?php
session_start(); 

$_SESSION['hairstyle'] = 'hairstyles/hair1.png';
$style_points = array();
$style_points[0]['x'] = 70;
$style_points[0]['y'] = 70;

$style_points[1]['x'] = 120;
$style_points[1]['y'] = 70;

$style_points[2]['x'] = 90;
$style_points[2]['y'] = 100;

$style_points[3]['x'] = 160;
$style_points[3]['y'] = 100;

$style_points[4]['x'] = 190;
$style_points[4]['y'] = 70;

$style_points[5]['x'] = 190;
$style_points[5]['y'] = 100;



$style_width = 200;
$style_height = 327;

$style_eye_left['x'] =120;
$style_eye_left['y'] =140;

$style_eye_right['x'] =160;
$style_eye_right['y'] =140;




$_SESSION['stylepoints'] = json_encode($style_points); 
 

$_SESSION['style_width'] = $style_width;
$_SESSION['style_height'] = $style_height;

$_SESSION['$style_eye_left'] = json_encode($style_eye_left);
$_SESSION['$style_eye_right'] = json_encode($style_eye_right);



?>