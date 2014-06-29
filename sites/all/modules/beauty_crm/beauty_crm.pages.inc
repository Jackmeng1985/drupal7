<?php

function beauty_crm_hair_picture_adjustment(Entity $beauty_hairstyle) {
    include_once dirname(__FILE__) . '/face/facepp_sdk.php';
        
    return '';
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
        $_SESSION['face'] = $thumb_face_file_name;
        
        drupal_goto('/world_cup/hair/adjustment/' . $hid);
    }
    return '';
}
