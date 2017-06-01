/**
 * Global variables.
 */
var desktop_breakpoint = 1200;
var large_tablet_breakpoint = 1024;
var tablet_breakpoint = 768;
var mobile_breakpoint = 420;

var desktop_column = 1170;

/**
 * govCMS general bootstrapping.
 */
(function($, Drupal, window, document, undefined) {
  var TabsAccordion = function() {
    var $ = jQuery;
    var _self = this;

    var scrollTopConst = $('#header').height() + 20;
    var accordionItemSelectors = [{
      head: '.horizontal-tabs-pane legend'
    }];

    this.init = function(context) {
      // Create Accordions
      // DEFAULT IS CLOSED, SET AND HID BY CSS
      for (var i = 0; i < accordionItemSelectors.length; i++) {
        $(accordionItemSelectors[i].head).unbind('click').wrapInner('<button></button>');

        $(accordionItemSelectors[i].head).on('click', function() {
          var topPos = 0;
          var tabIndex = $(this).parent().index();
          $(this).parent().parent().find('>fieldset').addClass('horizontal-tab-hidden');
          $(this).parent().parent().parent().find('.horizontal-tabs-list li').removeClass('selected').eq(tabIndex).addClass('selected');
          $(this).parent().toggleClass('horizontal-tab-hidden');

          if (!$(this).parent().hasClass('horizontal-tab-hidden')) {
            // if open, scroll to that accordion item's header position
            $("html, body").animate({
              scrollTop: $(this).offset().top
            }, 100);
          }
        });
      }
    };
  };

  Drupal.behaviors.govcms_ui_kit = {
    attach: function(context, settings) {
      // Object Fit Polyfill for IE. Used on News Teaser Images.
      objectFitImages();

      // Setup accordion
      var accordion = new TabsAccordion();
      accordion.init(context);

    }
  };

})(jQuery, Drupal, this, this.document);
