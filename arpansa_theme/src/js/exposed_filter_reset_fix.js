/**
 * @file
 * exposed_filter_reset_fix.js
 *
 * Custom script to fix https://www.drupal.org/project/views/issues/1109980. It
 * refreshes the page, and scrolls to the section with the public formal
 * submissions.
 */
var currentPageURL = window.location.href;
var anchorID = "#public_submissions";
var newURL = currentPageURL.split('?')[0].split('#')[0];

(function($, Drupal, window, document, undefined) {
  $(document).delegate('.views-reset-button .form-submit', 'click', function(event) {
    window.location = newURL;
    window.location.hash = anchorID;
    location.reload();
    return false;
  });
})(jQuery, Drupal, this, this.document);
