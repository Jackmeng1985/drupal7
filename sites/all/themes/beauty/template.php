<?php
// $Id: template.php,v 1.21 2012/08/16 andyzhao Exp $


/**
 * Override or insert variables into the page templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
function beauty_preprocess_page(&$vars) {
    if (arg(0) == 'world_cup') {
        if (!arg(1)) {
            $suggestion_template = 'page__beauty_world_cup_front_page';
        }
        else {
            $suggestion_template = 'page__beauty_' . str_replace('/', '_', $_GET['q']);
        }
        array_splice($vars['theme_hook_suggestions'], 0, 0, $suggestion_template);
    }
}

