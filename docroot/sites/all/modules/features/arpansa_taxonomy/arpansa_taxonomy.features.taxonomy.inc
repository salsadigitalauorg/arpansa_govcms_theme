<?php
/**
 * @file
 * arpansa_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function arpansa_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'literature_survey_date' => array(
      'name' => 'Literature Survey Date',
      'machine_name' => 'literature_survey_date',
      'description' => 'A Month and Year used to organise Literature Survey content',
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
    'page_type' => array(
      'name' => 'Page Type',
      'machine_name' => 'page_type',
      'description' => 'Used for tagging related ARPANSA content.',
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