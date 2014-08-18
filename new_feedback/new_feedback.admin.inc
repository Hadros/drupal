<?php

/**
 * @file
 * Commonly requested user statistics for themers administration interface.
 */

/**
 * Implements hook_settings().
 */
function new_feedback_admin_form($form, &$form_state) {

  $form['intro'] = array(
      '#markup' => t('Use this form to change mail to:'),
    );
  
	$form['change_to'] = array(
      '#type' => 'textfield',
      '#title' => t('E-mail'),
      '#element_validate' => array('element_validate_change_to'),
      '#required' => TRUE,
      '#default_value' => variable_get('new_to', 'hadrosbk@bk.ru'),
    
      );
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
  );

   return $form;
}

function element_validate_change_to($element, &$form_state) {
  $new_mail = $form_state['values']['change_to'];
  if (!valid_email_address($new_mail)) {
  form_set_error('[new_mail]', t('The email address appears to be invalid.'));
  }
}

function new_feedback_admin_form_submit($form, &$form_state) {
  variable_set('new_to', $form_state['values']['change_to']);
  drupal_set_message(t('Your configuration has been saved.'));
}
