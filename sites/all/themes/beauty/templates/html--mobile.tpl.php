<!DOCTYPE html>
<head>
  <meta charset="utf-8">
  <title><?php print $head_title; ?></title>
    <meta name="viewport" content="initial-scale=1, maximum-scale=1, user-scalable=no, minimal-ui">
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="black">
  <?php print beauty_get_css(); ?>
  <?php print beauty_get_js(); ?>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>