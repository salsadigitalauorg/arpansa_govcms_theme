<?php
/**
 * @file
 * arpansa_entity.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function arpansa_entity_taxonomy_default_vocabularies() {
  return array(
    'file_tags' => array(
      'name' => 'File Tags',
      'machine_name' => 'file_tags',
      'description' => 'An editable list of Tags specifically for files.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
