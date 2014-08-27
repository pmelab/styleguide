<?php
/**
 * @file
 * Display a page with default elements for styling.
 */

/**
 * Page callback to display common elements for testing.
 */
function styleguide_controls() {
  // Emit some messages.
  drupal_set_message('This is a status message.');
  drupal_set_message('This is another status message width a <a href="#">link</a>.');
  drupal_set_message('This is the last warning.', 'warning');
  drupal_set_message('This is a critical error.', 'error');

  $content = '';

  // Show a normal and mini pager.
  global $pager_page_array, $pager_total;
  $pager_page_array[1] = 5;
  $pager_total[1] = 200;

  $content .= theme('pager', array('element' => 1));
  $content .= theme('views_mini_pager', array('element' => 1));

  // A Simple more link.
  $content .= '<p>Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.</p>';
  $content .= theme('more_link', array(
    'title' => t('More'),
    'url' => 'styleguide',
  ));

  // The progress bar.
  $content .= theme('progress_bar', array(
    'percent' => 65,
    'message' => t('More than half way done!'),
  ));

  // Content to test if alignment is still fine.
  $content .= '<p>Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.</p>';

  return $content;
}
