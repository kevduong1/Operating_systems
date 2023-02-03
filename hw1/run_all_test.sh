#!/bin/bash

# specify the directory
dir=$1

# loop through all subdirectories and look for the "build" subfolder
for subdir in "$dir"/*/; do
  if [ -d "$subdir/build" ]; then
    pushd "$subdir/build"
    for exec_file in *_test; do
      if [ -x "$exec_file" ]; then
        ./"$exec_file"
      fi
    done
    popd
  fi
done