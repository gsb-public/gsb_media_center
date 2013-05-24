(function ($) {
  Drupal.behaviors.gsb_media_center = {
    attach: function () {
      $('.media-widget').each(function () {
        if ($('.fid', this).val() != 0) {
          $('.button.launcher', this).hide();
        }
        var launcherButton = $('.button.launcher', this);
        $('.fid', this).bind('change', function() {
          var fidField = $(this).val();
          if (fidField != 0) {
            if (launcherButton.length) {
              launcherButton.hide();
            }
          }
          else {
            launcherButton.show();
          }
        });
      });  
    }
  };
})(jQuery);