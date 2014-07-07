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
    <div class="content">
      <div class="banner">
        <a href="/world_cup/detail"><img src="<?php print $base_path . $directory; ?>/images/banner1.jpg" alt=""></a>
        <div class="banner-title">
          <span class="pull-left">【丽锦嗨时尚独家】桑巴军团悲情对决 杀马特天王重伤泪飙</span>
        </div>
      </div>
      <!-- end banner content -->

      <ul class="table-view">
        <li class="table-view-cell">
          <div class="">
            <div class="table-view-des">
              全场都是香蕉黄，这是一场精彩的南美黄衣军团对决，看的人心惊胆战，也赏心悦目。桑巴帅哥们与各式亮瞎眼的发型对熬夜看比赛的伪球迷妹纸来说绝对是球场上的最大靓点！
              <a href="/world_cup/detail">查看详情</a>
            </div>
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
          <ul class="table-view">
              <li class="table-view-cell media">
                  <a href="/world_cup/detail/1">
                    <div class="media-object pull-left">
                      <img  src="<?php print $base_path . $directory; ?>/images/banner1.jpg">
                    </div>
                    <div class="media-body">
                      <h4>【丽锦嗨时尚独家】桑巴军团悲情对决 杀马特天王重伤泪飙</h4>
                      <div class="table-view-des">
                        全场都是香蕉黄，这是一场精彩的南美黄衣军团对决，看的人心惊胆战，也赏心悦目。桑巴帅哥们与各式亮瞎眼的发型对熬夜看比赛的伪球迷妹纸来说绝对是球场上的最大靓点！
                      </div>
                      <div class="table-view-footer">
                        <span class="subbmit">2017-07-05 08:30:05</span>
                        <span class="tag">丽锦快评</span>
                      </div>
                    </div>
                  </a>
                </li>
          </ul>
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
