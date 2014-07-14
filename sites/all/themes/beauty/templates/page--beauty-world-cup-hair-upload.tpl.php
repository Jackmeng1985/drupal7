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
  <?php if(isset($_SESSION['thumb_face_file_path'])): ?>
    <div class="image-history" style="margin: 20px;">
      <img src="<?php print image_style_url('thumbnail', str_replace(DRUPAL_ROOT . '/sites/default/files/', 'public://', $_SESSION['thumb_face_file_path'])); ?>">
      <div><a href="<?php print url('world_cup/hair/adjustment/' . arg(3)); ?>" class="btn btn-positive" style="width: 100px;">使用历史照片</a></div>
    </div>
  <?php endif; ?>
  <div class="page-upload">
    <form id="image_upload" action="" method="post" enctype="multipart/form-data" >
      <input id="photo" class="btn btn-upload" value="拍照" disabled="disabled" />
      <input type="file" name="file" id="file" accept="image/*" capture="camera"  >
      <input id="submit" type="submit" name="submit" class="btn btn-upload" value="开始脸型识别" style="display: none;">
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
    var i = 0;
    $('#image_upload').submit(function() {
         $('#submit').val('脸型识别中...');
         setInterval(function(){
             i++
             if (i > 4) i = 1;
             switch (i) {
                 case 1:
                     $('#submit').val('脸型识别中.');
                     break;
                 case 2:
                     $('#submit').val('脸型识别中..');
                     break;
                 case 3:
                     $('#submit').val('脸型识别中...');
                     break;                     
             }
         }, 1000);
    })
    var w = document.documentElement.clientWidth;
    var r = window.devicePixelRatio;
    w = w * 0.8;
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

