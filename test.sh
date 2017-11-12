#!/bin/bash
# test script
EXEC="./geneology.out"
echo -ne "\n" | $EXEC init
# $EXEC display
# $EXEC mate 0 1
# $EXEC display
$EXEC mate 0 1 2 3 4
$EXEC display
# $EXEC mate 0 1 2 3
# $EXEC display
# $EXEC mate 0 1 4 5