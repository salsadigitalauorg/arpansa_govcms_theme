/**
 * @file
 * ga_social_interaction.js
 *
 * Custom script to track Social interactions with GA.
 */
(function($, Drupal, window, document, undefined) {
  Drupal.behaviors.arpansa_ga_social_interaction_tracking = {
    attach: function(context, settings) {
      $('.service-links a').click(function(ev) {
        var $service = '';
        if ($(this).hasClass('service-links-facebook')) {
          $service = 'Facebook';
        }
        else if ($(this).hasClass('service-links-twitter')) {
          $service = 'Twitter';
        }
        else if ($(this).hasClass('service-links-linkedin')) {
          $service = 'LinkedIn';
        }
        else if ($(this).hasClass('service-links-google-plus')) {
          $service = 'Google Plus';
        }
        else if ($(this).hasClass('service-links-email')) {
          $service = 'Email';
        }
        if ($service != '') {
          ga('send', 'social', $service, 'share', $(document).attr('location').href);
        }
      });
    }
  };
})(jQuery, Drupal, this, this.document);
