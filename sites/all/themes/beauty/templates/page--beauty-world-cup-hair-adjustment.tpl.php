<?php
$base_path = base_path();
/*<?php print $base_path . $directory; ?>/*/
?>
<nav class="bar bar-tab">
  <a class="tab-item scaleup" href="#">放大</a>
  <a class="tab-item scaledown" href="#">缩小</a>
  <a class="tab-item" href="<?php print url('world_cup/hair'); ?>">更多发型</a>
  <a id="share" class="tab-item share" href="#">分享</a>
</nav>
<div class="content">
  <div class="page-hair-adjustment">
       <canvas id="face" width="600" height = "600"> </canvas>
       <canvas id ="hairChange" width="448" height="733" > </canvas>
       <canvas id="hairStyle" width="448" height="733"></canvas>
  </div>
</div>
<?php print($page['content']['system_main']['main']['#markup']);?>
