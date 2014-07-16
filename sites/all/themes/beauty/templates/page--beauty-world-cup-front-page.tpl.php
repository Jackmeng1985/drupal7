   <script>
      tatali('weibo', 1742, 'weibo-content', 'comment');
      tatali('youku', 1462, 'video-content', 'video');
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
   <?php print($page['content']['system_main']['main']['#markup']);?>
