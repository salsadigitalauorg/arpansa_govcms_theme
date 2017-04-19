/**
 * Side Bar Menu.
 */
(function($, Drupal, window, document, undefined) {

  var $widget = null;
  var is_menu_desktop = true;

  // =========================================================
  // DESKTOP TOGGLES
  // =========================================================
  function toggle_button_click(e) {
    var $button = $(e.currentTarget);
    var $menu = $button.parents('li').children('ul.menu');
    var was_closed = $button.hasClass('menu-closed');

    if (was_closed) {
      expand($menu, $button);
    }
    else {
      collapse($menu, $button);
    }
  }

  function add_toggle_buttons() {
    // Only add buttons to first and second level of menu items.
    $widget.find('.menu-block-wrapper > ul > li, .menu-block-wrapper > ul > li > ul > li').each(function(idx) {
      var $list_item = $(this);
      var $sub_menu = $list_item.children('ul.menu');
      if ($sub_menu.length > 0) {
        var is_active_trail = $list_item.hasClass('active-trail');
        var $button = $('<button class="sidebar-toggle-menu" aria-controls="' + $sub_menu.attr('id') + '" aria-expanded="true" title="Collapse menu">Toggle sub menu</button>');
        if (is_active_trail) {
          expand($sub_menu, $button);
        }
        else {
          collapse($sub_menu, $button);
        }
        $sub_menu.attr('id', 'sidebar-submenu-' + idx);
        $list_item.children('a').wrap('<div class="sidemenu-item"></div>').after($button);
        $button.unbind('click', toggle_button_click).bind('click', toggle_button_click);
      }
    });
  }

  function collapse($menu, $button) {
    $menu.addClass('menu-closed').attr('aria-hidden', 'true');
    $button.addClass('menu-closed').attr('aria-expanded', 'false').attr('title', 'Expand menu');
  }

  function expand($menu, $button) {
    $menu.removeClass('menu-closed').attr('aria-hidden', 'false');
    $button.removeClass('menu-closed').attr('aria-expanded', 'true').attr('title', 'Collapse menu');
  }


  function remove_toggle_buttons() {
    // Clean up any elements and attributes created.
    $widget.find('.sidebar-toggle-menu').remove();
    $widget.find('[id^=sidebar-submenu]').removeAttr('id').removeAttr('aria-hidden').removeClass('menu-closed');
  }

  // =========================================================
  // MOBILE ACCORDION
  // =========================================================
  function enable_mobile_accordion() {
    $widget.each(function() {
      var cur_widget = $(this);
      var display_text = cur_widget.children('h2').html();
      var $content = cur_widget.children('.content');
      $content.attr('id', 'sidebar-menu-content');
      var $button = $('<button aria-controls="sidebar-menu-content" aria-expanded="false">' + display_text + '</button>');
      cur_widget.children('h2').html($button);
      $button.unbind('click', sidebar_accordion_button_click).bind('click', sidebar_accordion_button_click);
    });
  }

  function disable_mobile_accordion() {
    var display_text = $widget.children('h2').children('button').html();
    $widget.children('h2').empty().html(display_text);
    $widget.children('.content').removeAttr('id').removeClass('showing');
  }

  function sidebar_accordion_button_click(e) {
    var $button = $(e.currentTarget);
    var was_showing = $button.hasClass('showing');
    var $cur_widget = $button.parent().parent();

    if (was_showing) {
      $button.removeClass('showing').attr('aria-expanded', 'false');
      $cur_widget.children('.content').removeClass('showing');
    }
    else {
      $button.addClass('showing').attr('aria-expanded', 'true');
      $cur_widget.children('.content').addClass('showing');
    }
  }

  // =========================================================
  // RESPONSIVE
  // =========================================================
  function side_menu_responsive() {
    var w = window.innerWidth || document.documentElement.clientWidth;
    // Mobile (No toggles).
    if (w < large_tablet_breakpoint && is_menu_desktop) {
      // Disable menu toggles.
      is_menu_desktop = false;
      enable_mobile_accordion();
    }
    // Desktop (Toggles).
    else if (w >= large_tablet_breakpoint && !is_menu_desktop) {
      is_menu_desktop = true;
      add_toggle_buttons();
      disable_mobile_accordion();
    }
  }

  Drupal.behaviors.govcms_ui_kit_sidebar = {
    attach: function(context, settings) {
      $widget = $('#block-menu-block-left-nav, .page-search .block-facetapi', context);
      if ($widget.length > 0) {
        $widget.each(function() {
          add_toggle_buttons();
          $(window).unbind('resize', side_menu_responsive).bind('resize', side_menu_responsive);
          side_menu_responsive();
        });
      }

      // Add active class to a list for facet API.
      var $active_markup = $('.facetapi-active');
      $active_markup.each(function() {
        $(this).parent().addClass('active');
      });
    }
  };

})(jQuery, Drupal, this, this.document);
