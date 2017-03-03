#!/bin/bash

site="$1"
target_env="$2"
db_name="$3"
source_env="$4"

drush @$target_env sqlsan --sanitize-email=user+%uid@example.com
