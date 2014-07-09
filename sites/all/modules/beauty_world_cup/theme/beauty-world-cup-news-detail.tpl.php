    <div class="content">
      <div class="banner">
        <img src="<?php print file_create_url($news->field_news_pic['und'][0]['uri'])?>" alt="">
        <div class="banner-title"><?php print $news->title;?></div>
      </div>
      <!-- end banner content -->
      <div class="page-content">
        <div class="page-content-header">
          <div class="pull-left">
            <span class="submit"><?php print date('Y-m-d H:i:s', $news->created);?></span>
            <a href="#" title="">@丽锦快评 </a>
          </div>
          <div class="pull-right">
            <span class="icon icon-comment"></span>
          </div>
        </div>
        <div class="page-content-body">
          <?php print $news->body['und'][0]['safe_value'];?>
        </div>
      </div>
    </div>