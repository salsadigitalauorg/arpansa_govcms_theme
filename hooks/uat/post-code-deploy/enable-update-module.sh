#!/bin/sh
#
# Cloud Hook: enable-update-module
#

# Map the script inputs to convenient names.
site=$1
target_env=$2
drush_alias=$site'.'$target_env

# Execute a standard drush command.
drush @$drush_alias en -y update
