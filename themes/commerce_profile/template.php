<?php

/**
 * @file
 * Process theme data.
 *
 * Use this file to run your theme specific implimentations of theme functions,
 * such preprocess, process, alters, and theme function overrides.
 *
 * Preprocess and process functions are used to modify or create variables for
 * templates and theme functions. They are a common theming tool in Drupal, often
 * used as an alternative to directly editing or adding code to templates. Its
 * worth spending some time to learn more about these functions - they are a
 * powerful way to easily modify the output of any template variable.
 *
 * Preprocess and Process Functions SEE: http://drupal.org/node/254940#variables-processor
 * 1. Rename each function and instance of "adaptivetheme_subtheme" to match
 *    your subthemes name, e.g. if your theme name is "footheme" then the function
 *    name will be "footheme_preprocess_hook". Tip - you can search/replace
 *    on "adaptivetheme_subtheme".
 * 2. Uncomment the required function to use.
 */


/**
 * Preprocess variables for the html template.
 */
/* -- Delete this line to enable.
function adaptivetheme_subtheme_preprocess_html(&$vars) {
  global $theme_key;

  // Two examples of adding custom classes to the body.

  // Add a body class for the active theme name.
  // $vars['classes_array'][] = drupal_html_class($theme_key);

  // Browser/platform sniff - adds body classes such as ipad, webkit, chrome etc.
  // $vars['classes_array'][] = css_browser_selector();

}
// */


/**
 * Process variables for the html template.
 */
/* -- Delete this line if you want to use this function
function adaptivetheme_subtheme_process_html(&$vars) {
}
// */


/**
 * Override or insert variables for the page templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_preprocess_page(&$vars) {
}
function adaptivetheme_subtheme_process_page(&$vars) {
}
// */


/**
 * Override or insert variables into the node templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_preprocess_node(&$vars) {
}
function adaptivetheme_subtheme_process_node(&$vars) {
}
// */


/**
 * Override or insert variables into the comment templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_preprocess_comment(&$vars) {
}
function adaptivetheme_subtheme_process_comment(&$vars) {
}
// */


/**
 * Override or insert variables into the block templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_preprocess_block(&$vars) {
}
function adaptivetheme_subtheme_process_block(&$vars) {
}
// */

/**
 * Override or insert variables into the node template.
 */

/**
 * Create a jCarousel on product page, turn on teaser's templates, change post information on a blog pages.
 * @global type $base_path
 * @param type $vars
 */
function commerce_profile_preprocess_node(&$vars) {
  $detect = mobile_detect_get_object();
  if (isset($vars['field_product'][0]['product_id'])) {
    $product = entity_metadata_wrapper('commerce_product', $vars['field_product'][0]['product_id']);
    $i = 0;
    global $base_path;
    try {
      foreach ($product->field_view->value() as $picture) {
        $array[$i] = '<div class="slideshow-preview ' . $i . '"><img src="' . file_create_url($picture['uri']) . '"></div>';
        $i = $i + 1;
      }
    } 
    catch(Exception $ex) {
      // Do nothing.
    }
    if ($detect->isMobile() && !$detect->isTablet()) {
      $options = array(
        'scroll' => 1,
        'vertical' => FALSE,
        'skin' => 'tango',
        'visible' => 1,
      );
    }
    elseif (!$detect->isMobile() && $detect->isTablet()) {
      $options = array(
        'scroll' => 1,
        'vertical' => FALSE,
        'skin' => 'tango',
        'visible' => 4,
      );
    } 
    else {
      $options = array(
        'scroll' => 1,
        'vertical' => TRUE,
        'skin' => 'tango',
        'visible' => 3,
      );
    }
 
    $gallery = theme('jcarousel', array('items' => $array, 'options' => $options));
    $vars['gallery'] = $gallery;
  }
  if ($vars['view_mode'] == 'full' && node_is_page($vars['node'])) {
    $vars['classes_array'][] = 'node-full';
  }
  $node_type_suggestion_key = array_search('node__' . $vars['type'], $vars['theme_hook_suggestions']);
  if ($node_type_suggestion_key !== FALSE) {
    array_splice($vars['theme_hook_suggestions'], $node_type_suggestion_key + 1, 0, array('node__' . $vars['type'] . '__' . $vars['view_mode']));
  }
  if ($vars['type'] == 'blog') {
    $vars['submitted'] = commerce_profile_own_submitting($vars['name'], $vars['datetime'], $vars['created']);
  }
}

/**
 * Change output post information.
 * @param type $name
 * @param type $datetime
 * @param type $created
 * @param type $short
 * @return type
 */
function commerce_profile_own_submitting($name, $datetime, $created, $short = TRUE) {
  if ($short) {
    $datetime = '<time datetime="' . $datetime . '" pubdate="pubdate">' . date('d/m/Y', $created) . '</time>';
  }
  else {
    $datetime = '<time datetime="' . $datetime . '" pubdate="pubdate">' . date('d/m/Y - G:i', $created) . '</time>';
  }
  // Build the submitted variable used by default in node templates
  $return_text = t('Submitted !datetime by !username',
    array(
      '!username' => $name,
      '!datetime' => $datetime,
    )
  );
  return $return_text;
}

/**
 * Change output post information on a blog page.
 * @param type $vars
 */
function commerce_profile_preprocess_comment(&$vars) {
  if ($vars['elements']['#node']->type == 'blog') {
    $vars['submitted'] = commerce_profile_own_submitting($vars['author'], $vars['rdf_template_variable_attributes_array']['created']['content'], $vars['elements']['#comment']->created, FALSE);
  }
}

/**
 * Disable default message 'No front page content has been created yet.' on empty front page.
 * @param type $vars
 */
function commerce_profile_preprocess_page(&$vars) {
  if (drupal_is_front_page()) {
    unset($vars['page']['content']['system_main']['default_message']);
    drupal_set_title('');
  }
}

/**
 * Disable field 'Username' title on a front page.
 * @param type $variables
 * @return type
 */
function commerce_profile_lt_username_title($variables) {
  switch ($variables['form_id']) {
    case 'user_login':
      // Label text for the username field on the /user/login page.
      return t('Username or e-mail address');
    case 'user_login_block':
      // Label text for the username field when shown in a block.
      return t('');
  }
}

/**
 * Disable field 'Password' title on a front page.
 * @param type $variables
 * @return type
 */
function commerce_profile_lt_password_title($variables) {
  // Label text for the password field.
  switch ($variables['form_id']) {
    case 'user_login':
      return t('Password');
    case 'user_login_block':
      // Label text for the password field when shown in a block.
      return t('');
  }
}

/**
 * Remove links 'Login on register for post comments' after every comment except last comment.
 * @param type $array
 * @param type $condition
 * @param type $link
 * @param type $finish
 * @return type
 */
function remove_middle_links($array, $condition, $link, $finish) {
  $i = 0;
  foreach ($array as $delta => $object) {
    if ($i == $finish) {
      break;
    }
    if (isset($object[$condition])) {
      unset($array[$delta][$link]);
      $i = $i + 1;
    }
  }
  return $array;
}