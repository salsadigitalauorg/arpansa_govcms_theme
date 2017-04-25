#!/bin/bash

pwd=`dirname "$0"`
$pwd/../../test/post-db-copy/sqlsan.sh $1 $2 $3 $4
