<?php

function internet_reception_admin_form($form, &$form_state) {
  $form['intro'] = array(
      '#markup' => t('Use this form to change mail to:'),
  );  
	$form['change_to'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail'),
    '#element_validate' => array('internet_reception_validate_change_to'),
    '#required' => TRUE,
    '#default_value' => variable_get('new_to', 'hadrosbk@bk.ru'),    
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

function internet_reception_validate_change_to($element, &$form_state) {
  $value = $element['#value'];
  if (!valid_email_address($value)) {
    form_error($element, t('%name appears to be invalid.', array('%name' => $element['#title'])));
  }
}

function internet_reception_admin_form_submit($form, &$form_state) {
  variable_set('new_to', $form_state['values']['change_to']);
  drupal_set_message(t('Your configuration has been saved.'));
}
