#!/bin/bash

# clean objects and binaries
make -f build_ast.mk clean

# make file
make -f build_ast.mk

# test input pipeline
while read -p "Please provide input: " -r INPUT; do
    echo -e ${INPUT} | bin/print_canonical
done
