<?php

/**
 * @file
 * Display Suite 1 column template.
 */

?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $footer_teaser_path; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['title']);
      hide($content['comments']);
      hide($content['links']);
      print render($content);
      print l('Read more', $node_url, array('attributes' => array('class' => 'readmore button')));
    ?>
  </div>
  <?php print render($content['links']); ?>

</div>