#!/bin/bash

# Made this script for personal use, but it runs all the tests after we cmake in this build folder
# Leaving it here in case it's helpful for grading :)
# 0. cd into this build folder
# 1. cmake ..
# 2. make
# 3. bash run_all_test.sh

# Go through all sub-folders in the current directory
for dir in */; do
  # Go through all files in the sub-folder
  for file in "$dir"/*; do
    # Check if the file name ends in "_test" and is an executable file
    if [[ $file == *"_test" ]] && [ -x "$file" ]; then
      # Change the directory to the relative directory of the test file
      cd "$dir"
      # Run the test file
      echo "============================ RUNNING $file ======================================"
      ./"$(basename "$file")"
      # Change the directory back to the original directory
      cd ..
    fi
  done
done
