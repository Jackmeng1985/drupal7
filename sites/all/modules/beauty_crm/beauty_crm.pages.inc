<?php

function beauty_crm_hair_picture_adjustment(Entity $beauty_hairstyle) {
    include_once dirname(__FILE__) . '/face/facepp_sdk.php';
        
    beauty_add_css(drupal_get_path('module', 'beauty_crm'). '/face/css/haircontrol.css');
    beauty_add_css(drupal_get_path('module', 'beauty_crm'). '/face/css/jquery.mobile-1.3.2.min.css');
    
    
    beauty_add_js(drupal_get_path('module', 'beauty_crm'). '/face/js/jquery-1.9.1.min.js');
    beauty_add_js(drupal_get_path('module', 'beauty_crm'). '/face/js//point.js');
    beauty_add_js(drupal_get_path('module', 'beauty_crm'). '/face/js/grid.js');
    beauty_add_js(drupal_get_path('module', 'beauty_crm'). '/face/js/Matrix22.js');
    beauty_add_js(drupal_get_path('module', 'beauty_crm'). '/face/js//util.js');
    beauty_add_js(drupal_get_path('module', 'beauty_crm'). '/face/js/billinearinterpolation.js');
    beauty_add_js(drupal_get_path('module', 'beauty_crm'). '/face/js/configuration.js');
    beauty_add_js(drupal_get_path('module', 'beauty_crm'). '/face/js/AffineDeformation.js');
    beauty_add_js(drupal_get_path('module', 'beauty_crm'). '/face/js/BinlinearInterpolation.js');
    beauty_add_js(drupal_get_path('module', 'beauty_crm'). '/face/js/deformation.js');
    beauty_add_js(drupal_get_path('module', 'beauty_crm'). '/face/js/procface.js');
    
    $facepp = new Facepp();

    #detect local image
    $params = array('img' => $_SESSION['thumb_face_file_path']);
    $params['attribute'] = 'glass,pose';
    $response = $facepp->execute('/detection/detect',$params);
    $body = json_decode( $response['body']);
    $face_width = $body->img_width;
    $face_height = $body->img_height;
    $face = $body->face[0]->position;    
    
    
//        $variables['pic_origin_path'] = file_create_url($beauty_hairstyle->field_origin_pic['und'][0]['uri']);
    $hair_url = file_create_url($beauty_hairstyle->field_naked_pic['und'][0]['uri']);
    $hair_points = $beauty_hairstyle->data['rawHairContour'];
    $face_points = drupal_json_decode($beauty_hairstyle->data['rawFacePoints']);

    
    $style_width = 200;
    $style_height = 327;
    
    
    $content = '<script type="text/javascript">
face_file = "'. $_SESSION['thumb_face_file_name']. '";
face_position =  '.json_encode($face).';
face_width =  '.$face_width .';
face_height =  '.$face_height.';
hair_url = '.$hair_url.';
hair_points ='.$hair_points.';

hair_eye_left = '.drupal_json_encode($face_points['EyeLeft']).';
hair_eye_right = '.drupal_json_encode($face_points['EyeRight']).';

hair_width = '.$style_width.';
hair_height = '.$style_height.';
            </script>';
    return  $content;
}

function beauty_crm_hair_picture_upload($hid) {
    if ($_FILES["file"] && $_FILES["file"]["error"] == 0) {
        $destination_path = conf_path() . '/files' . '/faces/';
        file_prepare_directory($destination_path, FILE_CREATE_DIRECTORY);          
        $face_file_name = date('Y-m-d-H-i-s') . rand(1, 10000). '_' . $_FILES["file"]["name"];
        $thumb_face_file_name = 'thumb_' . $face_file_name;
        
        $face_file_path = realpath($destination_path) .'/'. $face_file_name;
        $thumb_face_file_path = realpath($destination_path) .'/'. $thumb_face_file_name;
        move_uploaded_file($_FILES["file"]["tmp_name"], $face_file_path);
        
        $w = $_GET['w'];
        // Get new sizes
        list($width, $height) = getimagesize($face_file_path);
        $percent = $w / $width;

        //旋转方向
        $exif = exif_read_data($face_file_path);
        if (!empty($exif['Orientation']) && $exif['Orientation'] == 6) {
            $percent = $w / $height;
        }
        $newwidth = $width * $percent;
        $newheight = $height * $percent;
        // Load
        $thumb = imagecreatetruecolor($newwidth, $newheight);
        $source = imagecreatefromjpeg($face_file_path);

        // Resize
        imagecopyresized($thumb, $source, 0, 0, 0, 0, $newwidth, $newheight, $width, $height);

        if (!empty($exif['Orientation']) && $exif['Orientation'] == 6) {
            $thumb = imagerotate($thumb, -90, 0);
        }
        // Output
        imagejpeg($thumb, $thumb_face_file_path);
        //Destroy
        imagedestroy($thumb);
        
        $_SESSION['thumb_face_file_name'] = $thumb_face_file_name;
        $_SESSION['thumb_face_file_path'] = $thumb_face_file_path;
        
        drupal_goto('world_cup/hair/adjustment/' . $hid);
    }
    return '';
}
