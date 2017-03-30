<?php

/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>

<header class="header" id="header" role="banner">
  <div class="header__inner">
    <?php if ($secondary_menu): ?>
      <nav class="header__secondary-menu" id="secondary-menu" role="navigation">
        <?php print theme('links__system_secondary_menu', array(
          'links' => $secondary_menu,
          'attributes' => array(
            'class' => array(
              'links',
              'inlineLinks--bordered--double',
              'clearfix',
            ),
          ),
          'heading' => array(
            'text' => isset($secondary_menu_heading) ? $secondary_menu_heading : '',
            'level' => 'h2',
            'class' => array('element-invisible'),
          ),
        )); ?>
      </nav>
    <?php endif; ?>
    <div class="logo-and-search">
      <div class="logo-wrapper">
        <div class="logo-aus-container">
          <?php if ($logo): ?>
            <?php
              $logo_alt = theme_get_setting('govcms_ui_kit_header_logo_alt');
              $logo_alt = !empty($logo_alt) ? $logo_alt : variable_get('site_name', 'Home');
              print theme('image', array(
                'path' => $logo,
                'alt' => $logo_alt,
              ));
            ?>
          <?php endif; ?>
        </div>
        <?php
        $toggle_secondary_logo = theme_get_setting('toggle_secondary_logo');

        if ($toggle_secondary_logo) {
          $secondary_logo_alt = theme_get_setting('secondary_logo_alt');
          $secondary_logo_alt = !empty($secondary_logo_alt) ? $secondary_logo_alt : variable_get('site_name', 'Home');
          $secondary_logo_path = theme_get_setting('secondary_logo_path');
          $secondary_logo_upload = theme_get_setting('secondary_logo_upload');
          if (!empty($secondary_logo_upload)) {

          }
          elseif (!empty($secondary_logo_path)) {
            $secondary_logo_img = theme('image', array(
              'path' => $secondary_logo_path,
              'alt' => $secondary_logo_alt,
              'attributes' => array('class' => array('header__logo-image')),
            ));
            $secondary_logo_class = array('header__logo');

            print l($secondary_logo_img, $front_page, array(
              'html' => TRUE,
              'attributes' => array(
                'id' => 'secondary-logo',
                'title' => $secondary_logo_alt,
                'rel' => 'home',
                'class' => $secondary_logo_class,
              ),
            ));
          }
        }
        ?>
        <?php if (theme_get_setting('govcms_ui_kit_header_title')): ?>
          <div class="header-title"><?php print decode_entities(theme_get_setting('govcms_ui_kit_header_title')); ?></div>
        <?php endif; ?>
      </div>
      <?php print render($page['header']); ?>
    </div>
  </div>
</header>

<div id="nav">
  <?php print render($page['navigation']); ?>
  <nav class="mobile-nav" id="mobile-nav">
    <?php
      $menu = menu_navigation_links('main-menu');
      print theme('links__main_menu', array('links' => $menu));
    ?>
  </nav>
</div>

<div id="page">

  <?php
    // Render the sidebars to see if there's anything in them.
    $sidebar_first = render($page['sidebar_first']);
    $sidebar_second = render($page['sidebar_second']);
  ?>

  <?php print render($page['highlighted']); ?>

  <div id="main">
    <div id="content" class="column" role="main">
      <div class="content-header">
        <div class="content-header-inner">
          <?php print $breadcrumb; ?>
          <a href="#skip-link" id="skip-content" class="element-invisible" tabindex="-1">Go to top of page</a>
          <a id="main-content"></a>
          <?php print render($title_prefix); ?>
          <?php if ($title): ?>
            <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
          <?php endif; ?>
          <?php print render($title_suffix); ?>
        </div>
      </div>
      <div class="content-body">
        <?php print $messages; ?>
        <?php print render($tabs); ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
        <div class="content-body-inner<?php print $sidebar_first ? ' has-sidebar' : ' no-sidebar'; ?> clearfix">
          <?php print render($page['content']); ?>
          <?php print $feed_icons; ?>
          <?php if ($sidebar_first): ?>
            <aside class="sidebar-first">
              <?php print $sidebar_first; ?>
            </aside>
          <?php endif; ?>
        </div>
      </div>
    </div>
  </div>

  <?php if ($sidebar_second): ?>
    <aside class="sidebar-second" role="complementary">
      <?php print $sidebar_second; ?>
    </aside>
  <?php endif; ?>

  <div id="footer">
    <?php print render($page['footer']); ?>
    <div class="region-bottom-container">
      <?php print render($page['bottom']); ?>
    </div>
  </div>
</div>
