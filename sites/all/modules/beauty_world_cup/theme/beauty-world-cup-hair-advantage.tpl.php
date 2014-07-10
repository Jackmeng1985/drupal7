<div class="content">
  <div class="banner">
    <a href="<?php $url = field_get_items('node', $banner_video, 'field_video_url'); print $url[0]['url']; ?>" title="丽锦发型-C罗">
      <img src="<?php $image = field_get_items('node', $banner_video, 'field_video_thumb'); print image_style_url('video_thumb', $image[0]['uri']); ?>" alt="<?php print $banner_video->title;?>">
      <div class="banner-title"><?php print $banner_video->title;?></div>
    </a>
  </div>

  <div class="page-hair-advantage">
    <div class="table-stars">
      <?php foreach ($advantage_videos as $video): ?>
        <a href="<?php $url = field_get_items('node', $video, 'field_video_url'); print $url[0]['url']; ?>" title="<?php print $video->title;?>">
          <img src="<?php $image = field_get_items('node', $video, 'field_video_thumb'); print image_style_url('video_thumb', $image[0]['uri']); ?>" alt="<?php print $video->title;?>">
          <div class="hair-title"><?php print $video->title;?></div>
        </a>
      <?php endforeach; ?>
    </div>
  </div>
</div>
