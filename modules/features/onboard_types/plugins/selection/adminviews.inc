<?php

if (module_exists('views')) {
  $plugin = array(
    'title' => t('Views; Filter by an entity reference view with a different view for administrators'),
    'class' => 'EntityReference_SelectionHandler_AdminViews',
    'weight' => -100,
  );
}
