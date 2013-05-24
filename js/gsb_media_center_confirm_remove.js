(function ($) {
  Drupal.behaviors.gsb_media_center_confirm_remove = {
    attach: function (e) {
      $('.button.remove:not(.gsb_media_center_confirm_remove_processed)').bind('click', function (e) {
        if (!confirm('Are you sure you want to remove the media?')) {
          e.stopImmediatePropagation();
        }
      }).addClass('gsb_media_center_confirm_remove_processed');
    }
  };
})(jQuery);