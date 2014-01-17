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
 * Add JavaScript required by this theme.
 */
function _onboard_theme_add_js() {
  // I originally wanted to load this using Modernizr, but I was running into
  // problems with Modernizr.load(), similar to the issue described at
  // https://github.com/Modernizr/Modernizr/issues/729.  For now, Respond.js
  // is the only polyfill needed, and it includes a test whether it's needed,
  // so just add it directly.

  // Note that Respond.js, and other popular media query polyfills don't work
  // with @imported CSS.  So, we have to turn on CSS aggregation to test
  // this out.
  drupal_add_js(drupal_get_path('theme', 'onboard_theme') . '/js/respond.min.js', array(
    // Set these options to make sure this is one of the first scripts to be
    // loaded.
    'group' => JS_LIBRARY,
    'every_page' => TRUE,
    'weight' => -30,
  ));

  if (module_exists('date_popup') && current_path() == 'node/add/board-term') {
    drupal_add_js(drupal_get_path('theme', 'onboard_theme') . '/js/fix_datepicker_position.js');
  }
}

/**
 * Implements hook_preprocess_page().
 *
 * @see page.tpl.php
 */
function onboard_theme_preprocess_page(&$variables) {
  _onboard_theme_add_js();

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

  // Images used frequently throughout the theme.
  $variables['onboard_msa_logo'] = theme('image', array(
    'path' => drupal_get_path('theme', 'onboard_theme') . '/img/MSA_logo_white.png', 
    'alt' => t("MSA Logo"),
  ));

  $variables['onboard_cc_logo'] = theme('image', array(
    'path' => drupal_get_path('theme', 'onboard_theme') . '/img/cc-by-nc-nd.png',
    'alt' => t("Creative Commons Attribution-NonCommercial-NoDerivs 3.0 Unported License Logo"),
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

/**
 * Implements template_preprocess().
 */
function onboard_theme_preprocess(&$variables, $hook) {
  if ($hook == 'views_more') {
    $view = $variables['view'];

    if ($view->name == 'board_terms' && $view->current_display == 'block_1' && count($view->args)) {
      $node = node_load($view->args[0]);
      
      if (onboard_types_show_management_links($node, 'full')) {
        $links = onboard_types_management_links($node);
        $variables['management_links'] = theme_links(array(
          'links' => $links,
          'attributes' => array(
            'class' => 'onboard-management-links',         
          ),        
        ));
      }
    }
  }
  else if ($hook == 'views_view_unformatted') {
    $view = $variables['view'];

    if ($view->name == 'public_cities' && $view->current_display == 'block_1') {
      // Add mod 3 striping classes for front page display of cities
      //
      // By default, Drupal does even/odd striping, but we need mod 3
      // because cities are displayed in three columns on the home page.
      // We need to identify the first and last elements in a "row" in
      // order to set their padding so the blocks are left and right
      // aligned with the container above.
      $rows = $variables['rows'];
      $count = 0;
      foreach ($rows as $id => $row) {
        $count++;
        $variables['classes'][$id][] = 'views-row-mod3-' . ($count % 3);
        $variables['classes_array'][$id] = isset($variables['classes'][$id]) ? implode(' ', $variables['classes'][$id]) : '';
      }
    }
  }
}

/*
 *
 * Override views feed icon for views_data_export CSV
 */
function onboard_theme_views_data_export_feed_icon__csv($options) {
  return l("download CSV file", $options['url']);
}


/**
 * Implements hook_css_alter().
 *   
 */
function onboard_theme_css_alter(&$css) {
  $bootstrap_cdn = theme_get_setting('bootstrap_cdn');
  $cdn_js_only = theme_get_setting('onboard_theme_bootstrap_cdn_js_only');

  if ($bootstrap_cdn && $cdn_js_only) {
    // We only want to load JavaScript from the CDN, not the CSS, since we
    // custom compile it. 
    if (theme_get_setting('bootstrap_bootswatch')) {
      $cdn = '//netdna.bootstrapcdn.com/bootswatch/' . $bootstrap_cdn  . '/' . theme_get_setting('bootstrap_bootswatch') . '/bootstrap.min.css';
    }
    else {
      $cdn = '//netdna.bootstrapcdn.com/bootstrap/' . $bootstrap_cdn  . '/css/bootstrap.min.css';
    }

    unset($css[$cdn]);
  }
}
