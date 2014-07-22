<div class="page-stars">
     <?php foreach ($works as $work) :?>
    <div class="page">
      <div class="page-top">
      <a href="<?php print url('world_cup/works/detail/'. $work->wid); ?>" title="">
        <img src="<?php print image_style_url('hairstyle_world_cup', $work->field_work_image['und'][0]['uri']);?>" alt="">
    </a>
      </div>
    <div class="page-below">
    <p><?php print $work->name;?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <?php print $banner_news_vote[$work->wid];?></p>
     </div>
    </div>
    <?php endforeach;?>
    
  </div>