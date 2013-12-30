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
  // Make the Bootstrap class prefix available as a variable
  $variables['grid_class_prefix'] = ONBOARD_THEME_GRID_CLASS_PREFIX;

  // Add information about the number of sidebars.
  if ((!empty($variables['page']['sidebar_first']) || !empty($variables['logo'])) && !empty($variables['page']['sidebar_second'])) {
    $content_column_grid_columns = ONBOARD_THEME_GRID_COLUMNS - (ONBOARD_THEME_SIDEBAR_COLUMNS * 2);
  }
  elseif (!empty($variables['logo']) || !empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
    $content_column_grid_columns = ONBOARD_THEME_GRID_COLUMNS - ONBOARD_THEME_SIDEBAR_COLUMNS;
  }
  else {
    $content_column_grid_columns = ONBOARD_THEME_GRID_COLUMNS;
  }
  $variables['content_column_class'] = sprintf(' class="%s%d"', ONBOARD_THEME_GRID_CLASS_PREFIX, $content_column_grid_columns);
  $variables['sidebar_first_class'] = sprintf(' class="sidebar-first-container %s%d"', ONBOARD_THEME_GRID_CLASS_PREFIX, ONBOARD_THEME_SIDEBAR_COLUMNS); 
  $variables['sidebar_second_class'] = sprintf(' class="%s%d"', ONBOARD_THEME_GRID_CLASS_PREFIX, ONBOARD_THEME_SIDEBAR_COLUMNS); 

  $variables['navbar_classes_array'] = array('navbar');

  if (theme_get_setting('bootstrap_navbar_inverse')) {
    $variables['navbar_classes_array'][] = 'navbar-inverse';
  }
  else {
    $variables['navbar_classes_array'][] = 'navbar-default';
  }

  //$variables['onboard_msa_logo'] = drupal_get_path('theme', 'onboard_theme') . '/img/MSA_logo_white.png'; 
  $variables['onboard_msa_logo'] = theme('image', array(
    'path' => drupal_get_path('theme', 'onboard_theme') . '/img/MSA_logo_white.png', 
    'alt' => t("MSA Logo"),
  ));

}

/**
 * Implements theme_field().
 *
 * Render the application URL as a button, with the text taken from the
 * field_application_action_title field.
 */
// @bookmark
// @todo: Decide if this is the best way to render this field.
function onboard_theme_field__field_application_url($variables) {
  $link_text_items = field_get_items('node', $variables['element']['#object'], 'field_application_action_title');
   $output = '';

  foreach ($variables['items'] as $delta => $item) {
    $link_text = $link_text_items[$delta]['safe_value'];
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<a class="' . $classes . '"' . $variables['item_attributes'][$delta] . ' href="' . drupal_render($item) . '">' . $link_text .  '</a>';
  }

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output; 
} 
