<?php 
$base_path = base_path();
/*<?php print $base_path . $directory; ?>/*/
?>
<style type="text/css">
#file {
  position: absolute;
  top: 0;
  right: 0;
  margin: 0;
  padding: 0;
  font-size: 20px;
  height: 100px;
  width: 100%;
  cursor: pointer;
  opacity: 0;
  filter: alpha(opacity=0);
}
#photo {
  width: 100px;
  height: 100px;
  padding: 0;
  margin: 20px auto;
  border-radius: 50%;
  display: block;
  font-size: 18px;
  color: #fff;
}
</style>
<div class="content">
  <div class="page-upload">
    <form id="image_upload" action="" method="post" enctype="multipart/form-data" >
      <input id="photo" class="btn btn-upload" value="拍照" disabled="disabled" />
      <input type="file" name="file" id="file" accept="image/*" capture="camera" >
      <input id="submit" type="submit" name="submit" class="btn btn-upload" value="点击上传" style="display: none;">
      <img  id="loading" src="<?php print $base_path . $directory; ?>/images/GIF0112.gif" alt="" style="display: none;">
    </form>
  </div>
</div>
<script src="http://code.jquery.com/jquery-1.11.0.min.js"></script>
<script type="text/javascript">
  $(document).ready(function() {
    $('#file').change(function() {
      if(this.value != '') {
        $('#submit').show();
      }
    });
    $('#image_upload').submit(function() {
         $('#submit').hide();
         $('#loading').show();
    })
    var w = document.documentElement.clientWidth;
    var r = window.devicePixelRatio;
  //  w = w * r;
    var f = document.getElementById('image_upload');
    f.action += '?w=' + w;
  });
</script>
<style>
  #file {
    display: block;
    margin: 20px 0;
  }
</style>

