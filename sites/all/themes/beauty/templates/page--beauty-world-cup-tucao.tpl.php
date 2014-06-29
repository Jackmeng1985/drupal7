<?php
$base_path = base_path();
/*<?php print $base_path . $directory; ?>/*/
?>
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>神吐槽</title>
    <meta name="viewport" content="initial-scale=1, maximum-scale=1, user-scalable=no, minimal-ui">
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="black">
    <link href="<?php print $base_path . $directory; ?>/css/ratchet.css" rel="stylesheet">
    <script src="http://code.jquery.com/jquery-1.11.0.min.js"></script>
    <script src="<?php print $base_path . $directory; ?>/js/mid2url.js"></script>
    <script src="<?php print $base_path . $directory; ?>/js/template.js"></script>
    <script src="<?php print $base_path . $directory; ?>/js/tatali.js"></script>
    <script>
      tatali('weibo', 1452, 'weibo-content', 'comment');
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
                <div class="table-view-footer"><span class="submit">{{value.created}}</span><span class="source">新浪微博</span></div>
              </div>
            </a>
          </li>
        {{/each}}
      </ul>
    </script>
  </head>
  <body>
    <div class="content">
      <div class="page-tucao" id="comment">
      </div>
    </div>
  </body>
</html>
