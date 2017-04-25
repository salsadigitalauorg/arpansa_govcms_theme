#!/bin/bash

site="$1"
target_env="$2"
db_name="$3"
source_env="$4"

drush @$target_env en update -y
drush @$target_env vset site_mail "developers@salsadigital.com.au"
