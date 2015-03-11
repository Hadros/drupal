(function ($) {
 
  Drupal.behaviors.ecommerce_common = {
    attach:function (context, settings) {
      window.onload = function() {
        if (document.body.clientWidth >= 1170) {
          var big_slideshow_image_width = 668;
          var big_slideshow_image_height = 598;
          var gallery_image_width = 168;
          var gallery_image_height = 178;
        }
        if (document.body.clientWidth < 1170 && document.body.clientWidth >= 960) {
          var big_slideshow_image_width = 538;
          var big_slideshow_image_height = 498;
          var gallery_image_width = 138;
          var gallery_image_height = 148;
        }
        if (document.body.clientWidth < 960 && document.body.clientWidth >= 724) {
          var big_slideshow_image_width = 536;
          var big_slideshow_image_height = 496;
          var gallery_image_width = 138;
          var gallery_image_height = 148;
        }
        if (document.body.clientWidth < 724) {
          var big_slideshow_image_width = 298;
          var big_slideshow_image_height = 276;
          var gallery_image_width = 138;
          var gallery_image_height = 148;
        }
        var img_width;
        var img_height;
        var k_width;
        var k_height;

        $('.jcarousel-item img').each(function() {
          $(this).once(function() {
            img_width = $(this).width();
            img_height = $(this).height();
            k_width = img_width / gallery_image_width;
            k_height = img_height / gallery_image_height;
            if (k_width > k_height) {
              $(this).width(img_width / k_width);
              $(this).height(img_height / k_width);
            }
            if (k_width < k_height) {
              $(this).width(img_width / k_height);
              $(this).height(img_height / k_height);
            }
            if (k_width == k_height) {
              $(this).width(img_width / k_height);
              $(this).height(img_height / k_height);
            }
          });
        });

        $('.slideshow-preview').once(function() {
          $(this).click(function() {
            $('.big-product-image').html($(this).html());
            $('.big-product-image img').removeAttr('style');
            img_width = $('.big-product-image img').width();
            img_height = $('.big-product-image img').height();
            k_width = img_width / big_slideshow_image_width;
            k_height = img_height / big_slideshow_image_height;
            if (k_width > k_height) {
              $('.big-product-image img').width(img_width / k_width);
              $('.big-product-image img').height(img_height / k_width);
            }
            if (k_width < k_height) {
              $('.big-product-image img').width(img_width / k_height);
              $('.big-product-image img').height(img_height / k_height);
            }
            if (k_width == k_height) {
              $('.big-product-image img').width(img_width / k_height);
              $('.big-product-image img').height(img_height / k_height);
            }
          });
          $('.slideshow-preview.0').once(function() {
            $(this).click();
          });
        });
      }
    }
  };
})(jQuery);