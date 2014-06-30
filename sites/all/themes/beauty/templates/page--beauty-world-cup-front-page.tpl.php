<?php
$base_path = base_path();
/*<?php print $base_path . $directory; ?>/*/
?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>发型的优势</title>
    <meta name="viewport" content="initial-scale=1, maximum-scale=1, user-scalable=no, minimal-ui">
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="black">
    <link href="<?php print $base_path . $directory; ?>/css/ratchet.css" rel="stylesheet">
    <script src="<?php print $base_path . $directory; ?>/js/segmented-controllers.js"></script>
    <script src="http://code.jquery.com/jquery-1.11.0.min.js"></script>
    <script src="<?php print $base_path . $directory; ?>/js/mid2url.js"></script>
    <script src="<?php print $base_path . $directory; ?>/js/template.js"></script>
    <script src="<?php print $base_path . $directory; ?>/js/tatali.js"></script>
    <script>
      tatali('weibo', 1457, 'weibo-content', 'comment');
      tatali('youku', 1462, 'video-content', 'video');
      tatali('news', 1473, 'bulletin-content', 'bulletin');
    </script>
    <script id='weibo-content' type="text/html">
      <ul class="table-view">
        {{each list as value index}}
          <li class="table-view-cell media">
            <a href="{{value.url}}" target="_blank">
              <div class="media-object pull-left">
                <img  src="{{value.author_image}}">
              </div>
              <div class="media-body">
                <h4>@{{value.author_name}}  ：</h4>
                <div class="table-view-des">{{value.weibo_content}}</div>
                <div class="table-view-footer">{{value.created}}</div>
              </div>
            </a>
          </li>
        {{/each}}
      </ul>
    </script>
    <script id='video-content' type="text/html">
      <ul class="table-view">
        {{each list as value index}}
          <li class="table-view-cell media">
            <a href="{{value.link}}">
              <div class="media-object pull-right">
                <img  src="{{value.thumbnail}}">
              </div>
              <div class="media-body">
                <h4>{{value.title}}</h4>
                <div class="table-view-footer">
                  <span class="subbmit pull-left">{{value.duration}}</span>
                  <div class="video-source pull-right">
                    <span class="icon icon-video"></span>优酷
                  </div>
                </div>
              </div>
            </a>
          </li>
        {{/each}}
      </ul>
    </script>
    <script id='bulletin-content' type="text/html">
      <ul class="table-view">
        {{each list as value index}}
          <li class="table-view-cell media">
              <a href="{{value.url}}">
                <div class="media-object pull-left">
                  <img  src="{{value.img}}">
                </div>
                <div class="media-body">
                  <h4>{{value.title}}</h4>
                  <div class="table-view-des">{{value.content}}</div>
                  <div class="table-view-footer">
                    <span class="subbmit">{{value.time}}</span>
                    <span class="tag">搜狐体育</span>
                  </div>
                </div>
              </a>
            </li>
        {{/each}}
      </ul>
    </script>
  </head>
  <body>
    <div class="content">
      <div class="banner">
        <img src="<?php print $base_path . $directory; ?>/images/banner.jpg" alt="">
        <div class="banner-title">
          <span class="pull-left">比利时VS阿尔及利亚： 发型的优势</span>
          <span class="pull-right">
            <span class="icon icon-comment-orange"></span>135
          </span>
        </div>
      </div>
      <!-- end banner content -->

      <ul class="table-view">
        <li class="table-view-cell">
          <div class="">
            <h3>比利时2-1阿尔及利亚反败为胜</h3>
            <div class="table-view-des">阿尔扎两度助攻，费莱尼、梅尔滕斯先后替补出场破门梅尔滕斯先后替补</div>
            <div class="table-view-cell-footer">
              <span class="icon icon-comment"></span><span>135</span>
            </div>
          </div>
        </li>
      </ul>
      <!-- list content -->

      <div class="segmented-control">
        <a class="control-item active" href="#bulletin">快报</a>
        <a class="control-item" href="#video">视频</a>
        <a class="control-item" href="#comment">神评论</a>
      </div>
      <div class="card">
        <span id="bulletin" class="control-content active">
          <!-- 快报 -->
        </span>
        <span id="video" class="control-content">
          <!-- 视频 -->
        </span>
        <span id="comment" class="control-content">
          <!-- 神评论　-->
        </span>
      </div>

    </div>
  </body>
</html>
