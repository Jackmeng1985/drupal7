<?php
$i = 0;
$more_number = 10;
?>
<div class="page-hair">
<h2>世界杯帅哥</h2>
<div class="tags">
  <span class="icon icon-tag"></span>
  <a href='<?php print url('world_cup/hair'); ?>' ><button class="btn btn-link <?php if (!arg(2)) {print 'btn-active';}?>">全部</button></a>
  <?php foreach ($tags as $tag) :?>
  <?php $i++; if ($i == $more_number){ print '<span id="more_tags" style="display:none;">';}?>
  <a href='<?php print url('world_cup/hair/'. $tag->tid); ?>' ><button class="btn btn-link <?php if (arg(2) == $tag->tid) {print 'btn-active';}?>"><?php print $tag->name; ?></button></a>
  <?php endforeach;?>
  <?php if ($i >= $more_number){ print '</span><button id="more_tags_button" class="btn btn-link">更多</button>';}?>
</div>
<div class="table-stars">
  <div>
    <?php foreach ($hairstyles as $hairstyle) :?>
      <a href="<?php print url('world_cup/hair/big/'. $hairstyle->hid); ?>" title="">
        <img src="<?php print image_style_url('hairstyle_world_cup', $hairstyle->field_origin_pic['und'][0]['uri']);?>" alt="">
    </a>
    <?php endforeach;?>
  </div>
</div>
</div>

<script type="text/javascript">
(function ($) {
  Drupal.behaviors.Beauty_hair = {
  attach: function (context) {
      $('.tags #more_tags_button').click(function(){
          if ($('#more_tags').css('display') == 'none') {
              $('#more_tags').show();
              $('#more_tags_button').text('收起');
          }
          else {
              $('#more_tags').hide();
              $('#more_tags_button').text('更多');              
          }
      });
  }};
})(jQuery);
</script>