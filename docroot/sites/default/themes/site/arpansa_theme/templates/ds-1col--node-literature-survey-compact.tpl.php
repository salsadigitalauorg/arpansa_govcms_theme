<?php

/**
 * @file
 * Display Suite 1 column template.
 */
?>
<<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <div class="field field-name-title field-type-ds field-label-inline clearfix">
	<?php print render($content['title'][0]['#markup']) ?>
  </div>

  <?php if (!empty($content['field_authored_by'][0]['#markup'])) :?>
	  <div class="field field-name-field-authored-by field-type-text field-label-inline clearfix">
	  	<div class="field-label"><?php print render($content['field_authored_by']['#title']) ?>:</div>
	  	<div class="field-items">
	  		<div class="field-item even"><h3><?php print render($content['field_authored_by'][0]['#markup']) ?></h3></div>
	  	</div>
	  </div>
  <?php endif; ?>

	<?php if (!empty($content['field_published_in'][0]['#markup'])) :?>
	  <div class="field field-name-field-published-in field-type-text field-label-inline clearfix">
	  	<div class="field-label"><?php print render($content['field_published_in']['#title']) ?>:</div>
	  	<div class="field-items">
	  		<div class="field-item even"><h3><?php print render($content['field_published_in'][0]['#markup']) ?></h3></div>
	  	</div>
	  </div>
	<?php endif; ?>

  <?php if (!empty($content['field_literature_survey_date'][0]['#markup'])) :?>
	  <div class="field field-name-field-literature-survey-date field-type-text field-label-inline clearfix">
	  	<div class="field-label"><?php print t('Date') ?>:</div>
	  	<div class="field-items">
	  		<div class="field-item even"><h3><?php print render($content['field_literature_survey_date'][0]['#markup']) ?></h3></div>
	  	</div>
	  </div>
	<?php endif; ?>

	<?php if (!empty($content['body'][0]['#markup'])) :?>
  <div class="field field-name-body field-type-text-with-summary field-label-inline clearfix">
  	<div class="field-label">Summary:</div>
  	<div class="field-items">
  		<div class="field-item even" property="content:encoded">
  			<?php print render($content['body'][0]['#markup']) ?>
			</div>
		</div>
	</div>
	<?php endif; ?>

	 <?php if (!empty($content['field_link_to'][0]['#element']['title'])) :?>
   <div class="field field-name-field-link-to field-type-link-field field-label-inline clearfix">
   		<div class="field-items">
   			<div class="field-item even">
   				<a href="<?php print render($content['field_link_to'][0]['#element']['display_url']) ?>" target="_blank"><?php print render($content['field_link_to'][0]['#element']['title']) ?></a>
   			</div>
   		</div>
   	</div>
    <?php endif; ?>

   	<?php if (!empty($content['field_commentary'][0]['#markup'])) :?>
   	<div class="field field-name-field-commentary field-type-text-long field-label-inline clearfix">
   		<div class="field-label"><?php print render($content['field_commentary']['#title']) ?>:</div>
   		<div class="field-items">
   			<div class="field-item even">
   				<?php print render($content['field_commentary'][0]['#markup']) ?>
			</div>
		</div>
	</div>
	<?php endif; ?>
</<?php print $ds_content_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
