<?php
/**
 * @file
 * Default form elements for styling purposes.
 */

/**
 * Forms callback for styling.
 */
function styleguide_form($form, &$form_state) {
  $form = array();
  $form['toggles'] = array(
    '#prefix' => '<div class="throbber-toggles">',
    '#suffix' => '</div>',
    'toggle' => array(
      '#type' => 'button',
      '#value' => t('Toggle throbbers'),
      '#attributes' => array(
        'class' => array('styleguide-throbbers'),
      ),
    ),
    'redraw' => array(
      '#type' => 'button',
      '#value' => t('Redraw throbbers'),
      '#attributes' => array(
        'class' => array('styleguide-throbbers-redraw'),
      ),
    ),
    '#attached' => array(
      'js' => array(
        drupal_get_path('module', 'styleguide') . '/assets/styleguide.js' => array(),
      ),
    ),
  );

  $form['textfield'] = array(
    '#type' => 'textfield',
    '#title' => t('Textfield'),
    '#description' => t('A simple textfield description.'),
    '#required' => TRUE,
  );

  $form['textarea'] = array(
    '#type' => 'textarea',
    '#title' => t('Textarea'),
    '#description' => t('A text area description.'),
  );

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Submit'),
    ),
    'cancel' => array(
      '#markup' => l(t('Cancel'), 'styleguide/forms'),
    ),
  );

  $form['checkboxes'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Checkboxes'),
    '#description' => t('Select any number of items.'),
    '#options' => styleguide_form_options(3),
    '#default_value' => array(2),
  );

  $form['radios'] = array(
    '#type' => 'radios',
    '#title' => t('Radio buttons'),
    '#description' => t('Select one of the options above.'),
    '#options' => styleguide_form_options(3),
    '#default_value' => 3,
  );

  $form['select_small'] = array(
    '#type' => 'select',
    '#title' => t('Small select'),
    '#options' => styleguide_form_options(3),
  );

  $form['select_large'] = array(
    '#type' => 'select',
    '#title' => t('Large select'),
    '#options' => styleguide_form_options(30),
  );

  $form['multiselect'] = array(
    '#type' => 'select',
    '#title' => t('Multiselect'),
    '#options' => styleguide_form_options(30),
    '#multiple' => TRUE,
  );

  $form['username_dummy'] = array(
    '#type' => 'hidden',
    '#attributes' => array('class' => array('username')),
  );

  $form['password'] = array(
    '#type' => 'password_confirm',
    '#title' => t('Choose a password'),
  );

  $form['managed_file'] = array(
    '#type' => 'managed_file',
    '#title' => 'File upload',
    '#upload_location' => 'public://',
    '#upload_validators' => array(),
  );

  $form['ajax_button'] = array(
    '#prefix' => '<div id="styleguide-ajax-wrapper">',
    '#suffix' => '</div>',
    '#type' => 'button',
    '#value' => t('Hit me!'),
    '#ajax' => array(
      'wrapper' => 'styleguide-ajax-wrapper',
      'callback' => 'styleguide_ajax_button',
    ),
  );

  $form['fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => 'Test fieldset',
    '#collapsible' => TRUE,
    '#description' => 'This is the description of the test fieldset.',
    'textfield' => array(
      '#type' => 'textfield',
      '#title' => 'Textfield',
      '#description' => 'This is a textfield.',
    ),
    'checkboxes' => array(
      '#type' => 'checkboxes',
      '#title' => 'Checkboxes',
      '#options' => array(
        'option 1' => 'Option 1',
        'option 2' => 'Option 2',
        'option 3' => 'Option 3',
        'option 4' => 'Option 4',
      ),
    ),
  );

  $form['vertical_tabs'] = array(
    '#type' => 'vertical_tabs',
    'one' => array(
      '#type' => 'fieldset',
      '#title' => 'First',
      'textfield' => array(
        '#type' => 'textfield',
        '#title' => 'Textfield',
        '#description' => 'This is a textfield.',
      ),
      'checkboxes' => array(
        '#type' => 'checkboxes',
        '#title' => 'Checkboxes',
        '#options' => array(
          'option 1' => 'Option 1',
          'option 2' => 'Option 2',
          'option 3' => 'Option 3',
          'option 4' => 'Option 4',
        ),
      ),
    ),
    'two' => array(
      '#type' => 'fieldset',
      '#title' => 'Second',
      'checkboxes' => array(
        '#type' => 'radios',
        '#title' => 'Radios',
        '#options' => array(
          'option 1' => 'Option 1',
          'option 2' => 'Option 2',
          'option 3' => 'Option 3',
          'option 4' => 'Option 4',
        ),
      ),
    ),
  );

  $form['autocomplete'] = array(
    '#type' => 'textfield',
    '#title' => t('Autocomplete textfield'),
    '#autocomplete_path' => 'styleguide/autocomplete',
    '#size' => 10,
  );

  return $form;
}

/**
 * Retrieve the test form and validate it with guarantee of failure.
 */
function styleguide_form_errors($form_id) {
  $form_state = array();
  $form = drupal_get_form($form_id, $form_state);
  $form_state['values'] = array();
  form_execute_handlers('validate', $form, $form_state);
  return $form;
}

/**
 * Retrieve a form with status disabled on everything.
 */
function styleguide_form_disabled($form, &$form_state) {
  $form = styleguide_form($form, $form_state);
  foreach (element_children($form) as $element) {
    $form[$element]['#disabled'] = TRUE;
  }
  return $form;
}

/**
 * Set errors everywhere.
 */
function styleguide_form_validate(&$form, &$form_state) {
  $excluded = array(
    'fieldset',
    'vertical_tab',
    'token',
    'hidden',
  );
  foreach (element_children($form) as $element) {
    if (!array_key_exists('#type', $form[$element])) {
      continue;
    }

    if (!in_array($form[$element]['#type'], $excluded)) {
      form_set_error($element, 'You are doing it wrong!');
    }
  }
}

/**
 * Generate an options array for various form elements.
 */
function styleguide_form_options($number) {
  $options = array();
  for ($i = 1; $i <= $number; $i++) {
    $options[$i] = t('Option !number', array('!number' => $i));
  }
  return $options;
}

/**
 * Ajax callback for dummy test button.
 */
function styleguide_ajax_button($form, $form_state) {
  sleep(3);
}
