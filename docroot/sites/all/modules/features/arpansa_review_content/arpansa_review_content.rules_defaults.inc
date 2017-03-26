<?php
/**
 * @file
 * arpansa_review_content.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function arpansa_review_content_default_rules_configuration() {
  $items = array();
  $items['rules_content_review'] = entity_import('rules_config', '{ "rules_content_review" : {
      "LABEL" : "Content Review Reminder",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "admin" ],
      "REQUIRES" : [ "views_bulk_operations", "rules" ],
      "ON" : { "cron" : [] },
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : { "view" : "admin_content_review|panel_due_to_review" },
            "PROVIDE" : { "entity_list" : { "entity_list" : "List of nodes to review" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "entity-list" ] },
            "ITEM" : { "list_item" : "Current node to review" },
            "DO" : [
              { "mail" : {
                  "to" : "website@arpansa.gov.au",
                  "subject" : "The page \\u0022[list-item:title]\\u0022 needs to be reviewed",
                  "message" : "The below page is due to be reviewed.\\r\\n\\r\\nTitle: [list-item:title]\\r\\nAuthored by: [list-item:field-authored-by]\\r\\nURL: [list-item:url]",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
