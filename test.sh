#!/bin/bash
# test script
E="./geneology.out"
echo -ne "\n" | $E init
$E display
$E mate 0 1
# $E display
# $E mate 0 1 2 3 4
# $E display
# $E mate 0 1 2 3
# $E display
# $E mate 0 1 4 5