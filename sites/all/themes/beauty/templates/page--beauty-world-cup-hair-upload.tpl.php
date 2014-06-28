<?php
$base_path = base_path();
/*<?php print $base_path . $directory; ?>/*/
?>
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>发型集-上传文件</title>
    <meta name="viewport" content="initial-scale=1, maximum-scale=1, user-scalable=no, minimal-ui">
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="black">
    <link href="<?php print $base_path . $directory; ?>/css/ratchet.css" rel="stylesheet">
  </head>
  <body>
    <div class="content">
      <div class="page-upload">
        <form id="image_upload" action="getFace.php" method="post" enctype="multipart/form-data" >
          <input type="file" name="file" id="file" accept="image/*" capture="camera" >
          <input type="submit" name="submit" class="btn btn-upload" value="点击上传">
        </form>
      </div>
    </div>
    <script>
      var w = document.documentElement.clientWidth;
      var r = window.devicePixelRatio;
      w = w * r;
      var f = document.getElementById('image_upload');
      f.action += '?w=' + w;
    </script>
  </body>
</html>
