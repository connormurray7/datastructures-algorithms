#!/usr/bin/env bash

#This is the full path to the directory where this file is contained
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

python3 $DIR/test.py > output.txt
