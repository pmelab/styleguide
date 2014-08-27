<?php
/**
 * @file
 * Drupdown test page.
 */

/**
 * Fetch and parse a markdown file for style testing.
 */
function styleguide_formatted() {
  return file_get_contents(drupal_get_path('module', 'styleguide') . '/assets/formatted.html');
}
