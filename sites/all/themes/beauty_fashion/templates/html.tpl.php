<!doctype html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="apple-mobile-web-app-capable" content="yes" />
    <meta name="viewport" content="width=device-width,initial-scale=1.0,minimum-scale=1.0,maximum-scale=1.0,user-scalable=no"/>
    <meta name="format-detection" content="telephone=no,email=no"/>
    <title><?php print $head_title; ?></title>
        <!-- styleSheets -->
  <?php print beauty_get_css(); ?>
  <?php print beauty_get_js(); ?>
       </head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php print $page; ?>
    <div class="siteNav">
        <div class="left">
            <a href="#" class="go2back"></a>
        </div>
        <div class="right">
            <a href="#" class="go2home"></a>
        </div>
        <div class="center" style="display:none;">
            <a href="#" class="customBtn"></a>
        </div>
    </div>
   </body>
</html>