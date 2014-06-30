<div class="content">
  <div class="page-upload">
    <form id="image_upload" action="" method="post" enctype="multipart/form-data" >
      <input type="file" name="file" id="file" accept="image/*" capture="camera" >
      <input type="submit" name="submit" class="btn btn-upload" value="点击上传">
    </form>
  </div>
</div>
<script type="text/javascript">
  var w = document.documentElement.clientWidth;
  var r = window.devicePixelRatio;
//  w = w * r;
  var f = document.getElementById('image_upload');
  f.action += '?w=' + w;
</script>
<style>
  #file {
    display: block;
    margin: 20px 0;
  }
</style>

