(function ($) {
  Drupal.behaviors.gsb_media_center = {
    attach: function () {
      if ($('.media-widget .fid').val() != 0) {
        $('.media-widget .button.launcher').hide();
      }
      $('.media-widget .fid').bind('change', function() {
        var fidField = $(this).val();
        var launcherButton = $('.media-widget .button.launcher');
        if (fidField != 0) {
          if (launcherButton.length) {
            launcherButton.hide();
          }
        }
        else {
          launcherButton.show();
        }
      });
    }
  };
})(jQuery);