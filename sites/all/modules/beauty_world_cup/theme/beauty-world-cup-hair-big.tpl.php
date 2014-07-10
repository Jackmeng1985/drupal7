<?php

?>
<div class="content">
  <div class="slider" id="slidershow">
    <div class="slide-group">
      <div class="slide">
          <img src="<?php print file_create_url($hairstyle->field_origin_pic['und'][0]['uri']);?>">
      </div>
    </div>
    <!--<div class="slider-num"><span class="active-num">1</span>/<span class="count-num">60</span></div>-->
  </div>
    <ul class="table-view" style="border-top:0px;border-bottom: 0px;">
    <li class="table-view-cell media" style="border-bottom:0px;">
      <a class="">
        <span class="media-object pull-left media-title">姓名</span>
        <div class="media-body media-text"><?php print $hairstyle->name;?></div>
      </a>
    </li>
    <li class="table-view-cell media" style="border-bottom:0px;">
      <a class="">
        <span class="media-object pull-left media-title">打理要点</span>
        <div class="media-body media-text"><?php print $hairstyle->description;?></div>
      </a>
    </li>
  </ul>
    <div class="btn-wrapper"><a href="<?php print url('world_cup/hair/upload/' .$hairstyle->hid)?>"><button class="btn btn-positive btn-block" style="margin-left: auto;margin-right: auto;">换发型</button></a></div>
