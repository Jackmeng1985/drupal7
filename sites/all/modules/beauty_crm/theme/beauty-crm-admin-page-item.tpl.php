<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

?>

<div class="<?php print $item_key; ?>">
    <div class="header"><span class="title"><?php print $item['header_title']; ?></span><span class="count"><?php print $item['header_info']; ?></span></div>
    <?php if (isset($item['body'])):?><div class="body"><?php print $item['body']; ?></div><?php endif;?>
    <?php if (isset($item['footer'])):?><div class="footer"><?php print $item['footer']; ?></div><?php endif;?>
</div>