#/bin/bash

# This is a script that launches the KCachegrind to analyze the
# time (instruction) usage. This is just for purpose of demonstration for use
# of callgrind to do time profiling

./compile_script.sh
valgrind --tool=callgrind ./qsort 1000
kcachegrind callgrind.out.*
rm callgrind.out.*
