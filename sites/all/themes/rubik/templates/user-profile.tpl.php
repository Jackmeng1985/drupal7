<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($account_profile) to print all profile items, or print a subset
 * such as render($account_profile['user_picture']). Always call
 * render($account_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $account_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $account_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $account_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */
?>
<div class="profile"<?php print $attributes; ?>>
  <?php $user_count = beauty_crm_get_user_count(); ?>
  <h2 class="title">用户数</h2>
  <ul class="user-count">
    <li class="item">管理员数：<?php print $user_count['admin']; ?></li>
    <li class="item">美发店数：<?php print $user_count['shop']; ?></li>
    <li class="item">美发师数：<?php print $user_count['barber']; ?></li>
    <li class="item">微信粉丝数：<?php print $user_count['weixin']; ?></li>
  </ul>
</div>
