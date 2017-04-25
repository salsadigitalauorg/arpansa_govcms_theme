#!/bin/bash

site="$1"
target_env="$2"
source_branch="$3"
deployed_tag="$4"
repo_url="$5"
repo_type="$6"
domain="<your domain url for prod>"

case $target_env in
    'dev' )
        domain="<your domain url for dev>"
        ;;
    'test' )
        domain="<your domain url for test>"
        ;;
esac

drush @$target_env ac-domain-purge $domain
drush @$target_env cc all
