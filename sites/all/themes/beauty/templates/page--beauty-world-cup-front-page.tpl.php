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
      //tatali('news', 1473, 'bulletin-content', 'bulletin');
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
                {{each value.pic_urls as pic}}
                  <img src="{{pic.thumbnail_pic}}">
                {{/each}}
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
   <?php print($page['content']['system_main']['main']['#markup']);?>
  </body>
</html>
