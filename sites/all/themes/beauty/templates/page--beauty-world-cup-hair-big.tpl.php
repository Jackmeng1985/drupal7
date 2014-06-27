<?php 
$base_path = base_path();
/*<?php print $base_path . $directory; ?>/*/
?>
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>发型集-大图</title>
    <meta name="viewport" content="initial-scale=1, maximum-scale=1, user-scalable=no, minimal-ui">
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="black">
    <link href="<?php print $base_path . $directory; ?>/css/ratchet.css" rel="stylesheet">
    <script src="<?php print $base_path . $directory; ?>/js/sliders.js"></script>
  </head>
  <body>
    <div class="content">
      <div class="slider" id="slidershow">
        <div class="slide-group">
          <div class="slide">
            <img src="<?php print $base_path . $directory; ?>/images/slider-1.jpg">
          </div>
          <div class="slide">
            <img src="<?php print $base_path . $directory; ?>/images/slider-1.jpg">
          </div>
          <div class="slide">
            <img src="<?php print $base_path . $directory; ?>/images/slider-1.jpg">
          </div>
        </div>
        <div class="slider-num"><span class="active-num">1</span>/<span class="count-num">60</span></div>
      </div>
      <ul class="table-view">
        <li class="table-view-cell media">
          <a class="">
            <span class="media-object pull-left media-title">姓名</span>
            <div class="media-body media-text">C罗</div>
          </a>
        </li>
        <li class="table-view-cell media">
          <a class="">
            <span class="media-object pull-left media-title">球队</span>
            <div class="media-body media-text">葡萄牙国家队</div>
          </a>
        </li>
        <li class="table-view-cell media">
          <a class="">
            <span class="media-object pull-left media-title">打理要点</span>
            <div class="media-body media-text">下面就教你三步骤打造成钟汉良同样帅气发型，只需吹风机和发胶定型就可以了，很简单！</div>
          </a>
        </li>
      </ul>
      <div class="btn-wrapper"><button class="btn btn-positive btn-block">换发型</button></div>
  </body>
</html>
