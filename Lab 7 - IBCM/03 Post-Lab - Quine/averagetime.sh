#!/bin/bash

# Iain Muir, iam9ez
# March 26th, 2020
# averagetime.sh

declare -i iterations=5
TOTAL_RUNTIME=0

# Prompt the user to input the number of iterations
read -p "Enter the exponent for counter.cpp: " exponent

# If the user inputs quit, exit the program
if [[ "$exponent" == "quit" ]] ; then
    echo "Quitting the program..."
    exit 0

# Else, loop through 5 iterations: calculate runtime and add to running counter
else
    for (( i=1; i<=$iterations; i++)) ; do
	echo "Running iteration $i..."
	RUNTIME=`./a.out $exponent | tail -1`
	echo "Time taken: " $RUNTIME "ms"
	TOTAL_RUNTIME=$(( $TOTAL_RUNTIME + $RUNTIME ))
    done
fi

# Print the total runtime
echo "Five iterations took" $TOTAL_RUNTIME "ms"

# Calculate and print the average runtime
AVG_RUNTIME=$(( $TOTAL_RUNTIME / 5 ))
echo "Average runtime was" $AVG_RUNTIME "ms"
