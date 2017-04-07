/**
 * Text Resize.
 */
(function($, Drupal, window, document, undefined) {
  Drupal.behaviors.govcms_ui_kit_accordion = {
    attach: function(context, settings) {
      var $accordion_container = $('.view-faq', context),
        $accordion_header = $('.views-field-title ', context),
        top = '';

      if ($accordion_container.length) {
        $accordion_header.on('click', function() {
          /* if opening accordion, scroll to accordion item's top, if closing, scroll to container's top */
          top = $(this).parents('li').hasClass('opened') ? $accordion_container.offset().top : $(this).offset().top;
          $(this).parents('li').toggleClass('opened');

          $('html, body').animate({
            scrollTop: top
          }, 200);
        });
      }
    }
  };

})(jQuery, Drupal, this, this.document);
