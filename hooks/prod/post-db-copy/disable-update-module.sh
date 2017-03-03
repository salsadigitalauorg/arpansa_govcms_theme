#!/bin/sh
#
# Cloud Hook: disable-update-module
#

# Map the script inputs to convenient names.
site=$1
target_env=$2
drush_alias=$site'.'$target_env

# Execute a standard drush command.
drush @$drush_alias pm-uninstall -y update
