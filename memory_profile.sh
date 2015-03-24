#/bin/bash

# This is a script that launches the massif-visualizer to analyze the
# memory usage. This is just for purpose of demonstration for using
# massif to do memory profiling

./compile_script.sh
valgrind --tool=massif ./qsort 1000
massif-visualizer massif.out.*
rm massif.out.*
