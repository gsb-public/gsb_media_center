(function ($) {
  Drupal.behaviors.gsb_media_center_file_title = {
    attach: function () {
      $('#media-format-form').once('file-title', function() {
        $('a.button.fake-ok').unbind('click');
        $('a.button.fake-ok').bind('click', function () {
          var formatType = $("select#edit-format option:selected").val();
          var title = $('input[name^=field_title]').val();
          if (formatType == 'wysiwyg_document' && title) {
            Drupal.settings.media.wysiwyg_document = Drupal.settings.media.wysiwyg_document.replace('-media_title-', title);
            if (Drupal.settings.media.wysiwyg_document) {
              Drupal.settings.media.formatFormFormats[formatType] = Drupal.settings.media.wysiwyg_document;
            }
          }
          Drupal.media.formatForm.submit();
        });
      });
    }
  }
})(jQuery);