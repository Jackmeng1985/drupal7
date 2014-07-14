<div class="content">
  <div class="banner">
    <a href="<?php print url('world_cup/video/'. $banner_video->nid);?>" title="<?php print $banner_video->title;?>">
      <img src="<?php $image = field_get_items('node', $banner_video, 'field_video_thumb'); print image_style_url('video_thumb', $image[0]['uri']); ?>" alt="<?php print $banner_video->title;?>">
      <div class="banner-title"><?php print $banner_video->title;?></div>
    </a>
  </div>

  <div class="page-hair-advantage">
    <div class="table-stars">
      <?php foreach ($advantage_videos as $video): ?>
        <a href="<?php print url('world_cup/video/'. $video->nid);?>" title="<?php print $video->title;?>">
          <img src="<?php $image = field_get_items('node', $video, 'field_video_thumb'); print image_style_url('video_thumb', $image[0]['uri']); ?>" alt="<?php print $video->title;?>">
          <div class="hair-title"><?php print $video->title;?></div>
        </a>
      <?php endforeach; ?>
    </div>
  </div>
</div>
