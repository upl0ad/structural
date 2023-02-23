#!/usr/bin/env bash

set -xe
cc -Werror -Wall -pedantic -o bst bst.c
./bst > tree.dot
