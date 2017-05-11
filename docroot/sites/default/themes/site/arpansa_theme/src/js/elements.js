/**
 * Elements collection.
 */
(function($, Drupal, window, document, undefined) {
  Drupal.behaviors.govcms_ui_kit_elements = {
    attach: function(context, settings) {
      // Table scroll-y functionality.
      var $table = $('.content table'),
        $table_container = $('.content .table-container');

      if ($table.length && $table_container.length == 0) {
        $table.wrap('<div class="table-container"></div>');
      }

      // Wysiwyg link to image
      var $link = $('a:has(img)');
      if ($link.length) {
        $link.addClass('has-image');
      }
    }
  };

})(jQuery, Drupal, this, this.document);
