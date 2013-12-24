<?php

/**
 * @file
 * template.php
 */

// Number of columns in the grid system
define('ONBOARD_THEME_GRID_COLUMNS', 16);
define('ONBOARD_THEME_SIDEBAR_COLUMNS', 4);
define('ONBOARD_THEME_GRID_CLASS_PREFIX', "col-md-");

/**
 * Implements hook_preprocess_page().
 *
 * @see page.tpl.php
 */
function onboard_theme_preprocess_page(&$variables) {
  // Add information about the number of sidebars.
  if ((!empty($variables['page']['sidebar_first']) || !empty($variables['page']['logo'])) && !empty($variables['page']['sidebar_second'])) {
    $content_column_grid_columns = ONBOARD_THEME_GRID_COLUMNS - (ONBOARD_THEME_SIDEBAR_COLUMNS * 2);
  }
  elseif (!empty($variables['page']['logo']) || !empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
    $content_column_grid_columns = ONBOARD_THEME_GRID_COLUMNS - ONBOARD_THEME_SIDEBAR_COLUMNS;
  }
  else {
    $content_column_grid_columns = ONBOARD_THEME_GRID_COLUMNS;
  }
  $variables['content_column_class'] = sprintf(' class="%s%d"', ONBOARD_THEME_GRID_CLASS_PREFIX, $content_column_grid_columns);
  $variables['sidebar_first_class'] = sprintf(' class="%s%d"', ONBOARD_THEME_GRID_CLASS_PREFIX, ONBOARD_THEME_SIDEBAR_COLUMNS); 
  $variables['sidebar_second_class'] = sprintf(' class="%s%d"', ONBOARD_THEME_GRID_CLASS_PREFIX, ONBOARD_THEME_SIDEBAR_COLUMNS); 

  $variables['navbar_classes_array'] = array('navbar');

  if (theme_get_setting('bootstrap_navbar_inverse')) {
    $variables['navbar_classes_array'][] = 'navbar-inverse';
  }
  else {
    $variables['navbar_classes_array'][] = 'navbar-default';
  }
}

