<?php
/**
 * @file
 * Adaptivetheme implementation to provide an HTML container for comments.
 *
 * Adaptivetheme variables:
 * - $is_mobile: Mixed, requires the Mobile Detect or Browscap module to return
 *   TRUE for mobile.  Note that tablets are also considered mobile devices.  
 *   Returns NULL if the feature could not be detected.
 * - $is_tablet: Mixed, requires the Mobile Detect to return TRUE for tablets.
 *   Returns NULL if the feature could not be detected.
 *
 * Available variables:
 * - $content: The array of content-related elements for the node. Use
 *   render($content) to print them all, or
 *   print a subset such as render($content['comment_form']).
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default value has the following:
 *   - comment-wrapper: The current template type, i.e., "theming hook".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * The following variables are provided for contextual information.
 * - $node: Node object the comments are attached to.
 * The constants below the variables show the possible values and should be
 * used for comparison.
 * - $display_mode
 *   - COMMENT_MODE_FLAT
 *   - COMMENT_MODE_THREADED
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_comment_wrapper()
 * @see theme_comment_wrapper()
 */
?>
<section id="comments" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php if ($content['comments'] && $node->type != 'forum'): ?>
    <?php print render($title_prefix); ?>
    <h2 class="comment-title title"><?php print t('Comments'); ?></h2>
    <?php print render($title_suffix); ?>
  <?php endif; ?>
    <?php if ($node->comment_count != 0) : ?>
      <?php if (isset($content['comments'][1]['links']['comment']['#links']['comment_forbidden']['title'])) :?>
        <?php $own_link = $content['comments'][1]['links']['comment']['#links']['comment_forbidden']['title'];?>
      <?php endif; ?>
      <?php if (isset($own_link)) :?>
        <div class="login-links"><?php print $own_link;?></div>
      <?php endif; ?>
    <?php endif; ?>
    <?php $content['comments'] = remove_middle_links($content['comments'], 'links', 'links', $node->comment_count);?>
  <?php print render($content['comments']); ?>
    <?php if (isset($own_link)) :?>
    <div class="login-links"><?php print $own_link;?></div>
    <?php endif; ?>

  <?php global $user; if ($user->uid != 0 && $content['comment_form']): ?>
    <h2 class="comment-title title comment-form"><?php print t('Leave a comment'); ?></h2>
    <?php print render($content['comment_form']); ?>
  <?php endif; ?>

</section>
