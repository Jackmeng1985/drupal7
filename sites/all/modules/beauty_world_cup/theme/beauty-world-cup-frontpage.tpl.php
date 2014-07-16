    <div class="content">
      <div class="banner">
          <a href="<?php print url('world_cup/news/detail/' . $banner_news->nid); ?>"><img src="<?php print file_create_url($banner_news->field_news_pic['und'][0]['uri'])?>" alt=""></a>
        <div class="banner-title">
          <span class="pull-left"><?php print $banner_news->title;?></span>
        </div>
      </div>
      <!-- end banner content -->

      <ul class="table-view">
        <li class="table-view-cell">
          <div class="">
            <div class="table-view-des">
              <?php print $banner_news->body['und'][0]['safe_summary'];?>
              <a href="<?php print url('world_cup/news/detail/' . $banner_news->nid); ?>">查看详情</a>
            </div>
            <div class="table-view-cell-footer">
               <?php print $banner_news_vote;?>
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
              <?php foreach ($frontpage_news as $news) :?>
              <li class="table-view-cell media">
                  <a href="<?php print url('world_cup/news/detail/' . $news->nid); ?>">
                    <div class="media-object pull-left">
                      <img  src="<?php print file_create_url($news->field_news_pic['und'][0]['uri'])?>">
                    </div>
                    <div class="media-body">
                      <h4><?php print $news->title;?></h4>
                      <div class="table-view-des">
                        <?php print $news->body['und'][0]['safe_summary'];?>
                      </div>
                      <div class="table-view-footer">
                        <span class="subbmit"><?php print date('Y-m-d H:i:s', $news->created);?></span>
                        <span class="tag">丽锦快评</span>
                      </div>
                    </div>
                  </a>
                </li>
                <?php endforeach;?>
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