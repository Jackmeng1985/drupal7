<?php $s = $_SERVER['HTTP_USER_AGENT'];?>
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="initial-scale=1, maximum-scale=1, user-scalable=no, minimal-ui">
  <meta name="apple-mobile-web-app-capable" content="yes">
  <meta name="apple-mobile-web-app-status-bar-style" content="black">
  <title>测试</title>
</head>
<body>
  请测试一下下列每种情况的表现，并记录是否能拍照和上传图片
  <div class="case">
    <p>case1</p>
    <input type="file" accept="image/*" capture>
  </div>
  <div class="case">
    <p>case2</p>
    <input type="file" accept="image/*" capture="camera">
  </div>
  <div class="case">
    <p>case3</p>
    <input type="file"capture="camera">
  </div>
  <div class="case">
    <p>case4</p>
    <input type="file" capture>
  </div>
  <div class="case">
    <p>case5</p>
    <input type="file" accept="image/*">
  </div>
    <div class="case">
    <p>case6</p>
    <input type="file" accept="image/*;capture=camera"> 
  </div>
    <div class="case">
    <p>user agemnt</p>
    <?php print $s;?>
  </div>
</body>
</html>
