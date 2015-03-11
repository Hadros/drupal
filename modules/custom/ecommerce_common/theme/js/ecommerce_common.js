(function ($) {
 
  $(document).ready(function() { 
    
    $('.dropdown-container').ready(function() {
      var ul = $('.dropdown-container ul');
      $('.dropdown-container ul').addClass('dropdown-menu-categories');
      $('ul', ul).removeClass('dropdown-menu-categories');
    });

    $('.custom-show-menu').once(function(){
      $(this).bind('click', function(){
        $('#block-system-main-menu').toggleClass('active'); 
        $('#block-system-main-menu').slideToggle('slow');
      });
    });

    $('.webform-component--name input').attr('placeholder', Drupal.t('Name'));
    
    $('.webform-component-email input').attr('placeholder', Drupal.t('Email'));

    $('.webform-component--subject input').attr('placeholder', Drupal.t('Subject'));

    $('.webform-component--message textarea').attr('placeholder', Drupal.t('Your comment here'));

    $('.simplenews-subscribe .form-item-mail input').attr('placeholder', Drupal.t('your@address.com'));
    
    $('#user-login-form #edit-name').attr('placeholder', Drupal.t('Login'));
    
    $('#user-login-form #edit-pass').attr('placeholder', Drupal.t('Password'));
    
    $('#search-block-form input').attr('placeholder', Drupal.t('Search'));
    
    $('.cart-contents .line-item-quantity').once(function() {
      var cart_quantity_html = $(this).html();
      var cart_quantity_html = "You have <span class = 'cart-quantity'>" + cart_quantity_html + '</span> in your shopping cart';
      $(this).html(cart_quantity_html);
    });
    
    $('#block-views-categories-block .navigation-category-item').each(function() {
      var category = $(this);
      $('h3', this).click(function(){
        category.toggleClass('active');
        $('.item-list', category).slideToggle('slow');
      });
    });
    
    $('.mobile-menu-button a').click(function() {
        return false;
    });
    
    $('.mobile-menu-button').once(function() {
      $(this).bind('click', function() {
        $('#block-system-main-menu').toggleClass('active');	
        $('#block-system-main-menu .menu clearfix').slideToggle('fast');
      });
    });
    
  });
})(jQuery);
