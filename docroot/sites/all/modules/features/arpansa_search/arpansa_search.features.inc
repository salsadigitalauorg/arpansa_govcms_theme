<?php
/**
 * @file
 * arpansa_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function arpansa_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function arpansa_search_default_search_api_index() {
  $items = array();
  $items['site_search_index'] = entity_import('search_api_index', '{
    "name" : "Site Search Index",
    "machine_name" : "site_search_index",
    "description" : null,
    "server" : "core",
    "item_type" : "multiple",
    "options" : {
      "datasource" : { "types" : [ "node", "file" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "file" : { "type" : "integer", "entity_type" : "file" },
        "file:field_document_title" : { "type" : "text", "boost" : "5.0" },
        "file:field_file_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "file:field_file_tags:name" : { "type" : "list\\u003Ctext\\u003E" },
        "file:mime" : { "type" : "string", "boost" : "0.5" },
        "file:name" : { "type" : "text" },
        "node" : { "type" : "integer", "entity_type" : "node" },
        "node:author" : { "type" : "integer", "entity_type" : "user" },
        "node:body:value" : { "type" : "text" },
        "node:changed" : { "type" : "date" },
        "node:comment_count" : { "type" : "integer" },
        "node:created" : { "type" : "date" },
        "node:field_consultation_issue_text:value" : { "type" : "text" },
        "node:field_news_date" : { "type" : "date" },
        "node:field_page_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "node:field_subtitle" : { "type" : "text", "boost" : "2.0" },
        "node:field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_tags:name" : { "type" : "list\\u003Ctext\\u003E" },
        "node:promote" : { "type" : "boolean" },
        "node:sticky" : { "type" : "boolean" },
        "node:title" : { "type" : "text", "boost" : "5.0" },
        "node:type" : { "type" : "string" },
        "search_api_language" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "node:consultation" : "node:consultation",
              "node:news_article" : "node:news_article",
              "node:page" : "node:page",
              "node:webform" : "node:webform",
              "file:document" : "file:document"
            }
          }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "file:name" : true,
              "file:field_document_title" : true,
              "node:title" : true,
              "node:author" : true,
              "node:field_tags" : true,
              "node:field_page_type" : true,
              "node:field_subtitle" : true,
              "node:body:value" : true,
              "node:field_consultation_issue_text:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "file:name" : true,
              "file:field_document_title" : true,
              "node:title" : true,
              "node:field_subtitle" : true,
              "node:body:value" : true,
              "node:field_consultation_issue_text:value" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : { "status" : 0, "weight" : "15", "settings" : { "fields" : [] } },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "file:name" : true,
              "file:field_document_title" : true,
              "node:title" : true,
              "node:field_subtitle" : true,
              "node:body:value" : true,
              "node:field_consultation_issue_text:value" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : { "file:name" : "file:name" },
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['what_s_new_index'] = entity_import('search_api_index', '{
    "name" : "What\\u0027s New index",
    "machine_name" : "what_s_new_index",
    "description" : null,
    "server" : "core",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "consultation", "news_article", "page" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "field_news_date" : { "type" : "date" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "consultation" : "consultation",
              "news_article" : "news_article",
              "page" : "page"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_metatag_alter_callback" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "title" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "0",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_page().
 */
function arpansa_search_default_search_api_page() {
  $items = array();
  $items['content_search'] = entity_import('search_api_page', '{
    "index_id" : "site_search_index",
    "path" : "search",
    "name" : "Search",
    "machine_name" : "content_search",
    "description" : "",
    "options" : {
      "mode" : "terms",
      "fields" : [],
      "per_page" : "10",
      "result_page_search_form" : 1,
      "get_per_page" : 0,
      "view_mode" : "search_api_page_result",
      "empty_behavior" : ""
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
