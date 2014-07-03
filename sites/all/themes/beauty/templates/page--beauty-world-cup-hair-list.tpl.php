<?php 
$base_path = base_path();
/*<?php print $base_path . $directory; ?>/*/
?>
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>洗剪吹造型秀</title>
    <meta name="viewport" content="initial-scale=1, maximum-scale=1, user-scalable=no, minimal-ui">
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="black">
    <link href="<?php print $base_path . $directory; ?>/css/ratchet.css" rel="stylesheet">
    <script src="<?php print $base_path . $directory; ?>/js/segmented-controllers.js"></script>
  </head>
  <body>
    <div class="content">
      <div class="page-hair-list">
        <div class="segmented-control" id="hair-list-segmented-control">
          <a class="control-item active" href="#hair-new">
            <span>最新</span>
          </a>
          <a class="control-item" href="#hair-hot">
            <span>最热</span>
          </a>
        </div>
        <div class="card">
          <span id="hair-new" class="control-content active">
            <!--  最新 -->
            <div class="table-stars">
              <div>
                <a href="##" title="">
                  <img src="<?php print $base_path . $directory; ?>/images/stars.jpg" alt="">
                  <div class="hair-title">
                    <span class="pull-left">@贝嫂</span>
                    <span class="pull-right">
                      <span class="icon icon-comment"></span>135
                    </span>
                  </div>
                </a>
                <a href="##" title="">
                  <img src="<?php print $base_path . $directory; ?>/images/stars.jpg" alt="">
                  <div class="hair-title">
                    <span class="pull-left">@贝嫂</span>
                    <span class="pull-right">
                      <span class="icon icon-comment"></span>135
                    </span>
                  </div>
                </a>
                <a href="##" title="">
                  <img src="<?php print $base_path . $directory; ?>/images/stars.jpg" alt="">
                  <div class="hair-title">
                    <span class="pull-left">@贝嫂</span>
                    <span class="pull-right">
                      <span class="icon icon-comment"></span>135
                    </span>
                  </div>
                </a>
                <a href="##" title="">
                  <img src="<?php print $base_path . $directory; ?>/images/stars.jpg" alt="">
                  <div class="hair-title">
                    <span class="pull-left">@贝嫂</span>
                    <span class="pull-right">
                      <span class="icon icon-comment"></span>135
                    </span>
                  </div>
                </a>
              </div>
            </div>
          </span>
          <span id="hair-hot" class="control-content">
            <!-- 最热 -->
            <div class="table-stars">
              <div>
                <a href="##" title="">
                  <img src="<?php print $base_path . $directory; ?>/images/stars.jpg" alt="">
                  <div class="hair-title">
                    <span class="pull-left">@贝嫂</span>
                    <span class="pull-right">
                      <span class="icon icon-comment"></span>135
                    </span>
                  </div>
                </a>
                <a href="##" title="">
                  <img src="images/stars.jpg" alt="">
                  <div class="hair-title">
                    <span class="pull-left">@贝嫂</span>
                    <span class="pull-right">
                      <span class="icon icon-comment"></span>135
                    </span>
                  </div>
                </a>
                <a href="##" title="">
                  <img src="<?php print $base_path . $directory; ?>/images/stars.jpg" alt="">
                  <div class="hair-title">
                    <span class="pull-left">@贝嫂</span>
                    <span class="pull-right">
                      <span class="icon icon-comment"></span>135
                    </span>
                  </div>
                </a>
                <a href="##" title="">
                  <img src="<?php print $base_path . $directory; ?>/images/stars.jpg" alt="">
                  <div class="hair-title">
                    <span class="pull-left">@贝嫂</span>
                    <span class="pull-right">
                      <span class="icon icon-comment"></span>135
                    </span>
                  </div>
                </a>
              </div>
          </span>
        </div>
      </div>

    </div>
  </body>
</html>