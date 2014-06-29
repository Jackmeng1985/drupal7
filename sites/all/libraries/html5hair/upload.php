<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>上传照片</title>
    <meta name="viewport" content="initial-scale=1, maximum-scale=1, user-scalable=no, minimal-ui">
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="black">
    <link href="css/ratchet.css" rel="stylesheet">
    <script src="js/ratchet.js"></script>
  </head>
  <body>
    <div class="content">
      <form id="image_upload" action="getFace.php" method="post" enctype="multipart/form-data" >
        <input type="file" name="file" id="file" accept="image/*" capture="camera" >
        <input type="submit" name="submit" class="btn btn-positive btn-block" value="点击上传">
      </form>
    </div>
    <script>
      var w = document.getElementsByTagName("body")[0].clientWidth;
      var r = window.devicePixelRatio;
      w = w ;
      var f = document.getElementById('image_upload');
      f.action += '?w=' + w;
    </script>
  </body>
</html>
