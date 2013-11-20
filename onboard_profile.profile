<?php

/**
 * Implements hook_form_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function onboard_profile_form_install_configure_form_alter(&$form, $form_state) {
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
  $form['site_information']['site_mail']['#default_value'] = 'ben@theworkdept.com';

  $form['admin_account']['account']['name']['#default_value'] = 'test';
  $form['admin_account']['account']['mail']['#default_value'] = 'contact@theworkdept.com';

  $form['server_settings']['site_default_country']['#default_value'] = 'US';
  $form['server_settings']['date_default_timezone']['#default_value'] = 'America/Detroit';

  $form['update_notifications']['update_status_module']['#default_value'][0] = 0;
  $form['update_notifications']['update_status_module']['#default_value'][1] = 0;
}
