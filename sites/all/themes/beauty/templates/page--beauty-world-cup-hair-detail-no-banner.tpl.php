<?php 
$base_path = base_path();
/*<?php print $base_path . $directory; ?>/*/
?>
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>剪发详细</title>
    <meta name="viewport" content="initial-scale=1, maximum-scale=1, user-scalable=no, minimal-ui">
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="black">
    <link href="<?php print $base_path . $directory; ?>/css/ratchet.css" rel="stylesheet">
    <script src="<?php print $base_path . $directory; ?>/js/segmented-controllers.js"></script>
  </head>
  <body>
    <div class="content">
      <div class="segmented-control" id="hair-segmented-control">
        <a class="control-item active" href="#stylist">
          <div class="tag-box">
            <img src="<?php print $base_path . $directory; ?>/images/stars.jpg" alt="">
          </div>
          <span class="control-title">发型师</span>
        </a>
        <a class="control-item" href="#friends">
          <div class="tag-box">
            <span class="icon icon-friends"></span>
          </div>
          <span class="control-title">网友秀</span>
        </a>
        <a class="control-item" href="#tucao">
          <div class="tag-box">
            <span class="icon icon-tucao"></span>
          </div>
          <span class="control-title">来吐槽</span>
        </a>
      </div>
      <div class="card">
        <span id="stylist" class="control-content active">
          <!-- 发型师 -->
          <ul class="table-view">
            <li class="table-view-cell media">
              <a class="">
                <span class="media-object pull-left icon icon-user"></span>
                <div class="media-body">
                  <h4>李炜（技术总监）</h4>
                </div>
              </a>
            </li>
            <li class="table-view-cell media has-nav-right">
              <a class="navigate-right">
                <span class="media-object pull-left icon icon-address"></span>
                <div class="media-body">
                  <h4>爱美丽美发国贸分店</h4>
                  <div class="table-view-des">朝阳区朝阳北路107号珠江罗马嘉园7号楼103号(近朝阳大悦城)</div>
                </div>
              </a>
            </li>
          </ul>
          <div class="btn-table">
            <div class="btn-table-cell">
              <button class="btn btn-positive btn-block"><span class="icon icon-price"></span>价格</button>
            </div>
            <div class="btn-table-cell">
              <button class="btn btn-primary btn-block">预约<span class="icon icon-phone"></span></button>
            </div>
          </div>
        </span>
        <span id="friends" class="control-content">
          <!-- 网友秀 -->
          <div class="table-stars">
            <div>
              <a href="##" title="">
                <img src="<?php print $base_path . $directory; ?>/images/stars.jpg" alt="">
                <div class="hair-title">贝嫂</div>
              </a>
              <a href="##" title="">
                <img src="<?php print $base_path . $directory; ?>/images/stars.jpg" alt="">
                <div class="hair-title">贝嫂</div>
              </a>
              <a href="##" title="">
                <img src="<?php print $base_path . $directory; ?>/images/stars.jpg" alt="">
                <div class="hair-title">贝嫂</div>
              </a>
              <a href="##" title="">
                <img src="<?php print $base_path . $directory; ?>/images/stars.jpg" alt="">
                <div class="hair-title">贝嫂</div>
              </a>
              <a href="##" title="">
                <img src="<?php print $base_path . $directory; ?>/images/stars.jpg" alt="">
                <div class="hair-title">贝嫂</div>
              </a>
              <a href="##" title="">
                <img src="<?php print $base_path . $directory; ?>/images/stars.jpg" alt="">
                <div class="hair-title">贝嫂</div>
              </a>
            </div>
          </div>
        </span>
        <span id="tucao" class="control-content">
          <!-- 吐槽　-->
          <div class="page-tucao" id="comment">
            <ul class="table-view">
              <li class="table-view-cell media">
                <a class="">
                  <div class="media-object pull-left">
                    <img  src="<?php print $base_path . $directory; ?>/images/stars.jpg">
                  </div>
                  <div class="media-body">
                    <h4>@迷迷虎  ：</h4>
                    <div class="table-view-des">费莱尼利这发型真的很有的优势么！！！</div>
                    <div class="table-view-footer"><span class="submit">6-16 16:26</span></div>
                  </div>
                </a>
              </li>
              <li class="table-view-cell media">
                <a class="">
                  <div class="media-object pull-left">
                    <img  src="<?php print $base_path . $directory; ?>/images/stars.jpg">
                  </div>
                  <div class="media-body">
                    <h4>@迷迷虎  ：</h4>
                    <div class="table-view-des">世界杯史上共产生8支冠军球队，也只有巴西队曾战胜过中国队。</div>
                    <div class="table-view-footer"><span class="submit">6-16 16:26</span></div>
                  </div>
                </a>
              </li>
              <li class="table-view-cell media">
                <a class="">
                  <div class="media-object pull-left">
                    <img  src="<?php print $base_path . $directory; ?>/images/stars.jpg">
                  </div>
                  <div class="media-body">
                    <h4>@迷迷虎  ：</h4>
                    <div class="table-view-des">世界杯史上共产生8支冠军球队，也只有巴西队曾战胜过中国队。</div>
                    <div class="table-view-footer"><span class="submit">6-16 16:26</span></div>
                  </div>
                </a>
              </li>
            </ul>
          </div>
        </span>
      </div>

    </div>
  </body>
</html>
