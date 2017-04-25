#!/bin/bash

pwd=`dirname "$0"`
$pwd/../../prod/post-code-deploy/clear-varnish.sh $1 $2 $3 $4 $5 $6
