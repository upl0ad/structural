#!/usr/bin/env bash

set -xe
cc -Werror -Wall -pedantic -o bst bst.c
./bst > tree.dot

echo "running dot -Tsvg tree.dot"
dot -Tsvg tree.dot > tree.svg
