<?php
$base_path = base_path();
/*<?php print $base_path . $directory; ?>/*/
?>
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>发型师</title>
    <meta name="viewport" content="initial-scale=1, maximum-scale=1, user-scalable=no, minimal-ui">
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="black">
    <link href="<?php print $base_path . $directory; ?>/css/ratchet.css" rel="stylesheet">
    <script src="<?php print $base_path . $directory; ?>/js/segmented-controllers.js"></script>
  </head>
  <body>
    <?php print($page['content']['system_main']['main']['#markup']);?>
  </body>
</html>
