<?php
/**
 * @file
 * nodes_with_pictures.features.inc
 */

/**
 * Implements hook_node_info().
 */
function nodes_with_pictures_node_info() {
  $items = array(
    'frontpage_slideshow' => array(
      'name' => t('Frontpage slideshow'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
