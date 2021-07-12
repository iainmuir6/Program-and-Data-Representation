#!/bin/bash

# Iain Muir, iam9ez
# March 3rd, 2020
# averagetime.sh

# Prompt the user to input a dictionary and a grid, in that order
read -p "Dictionary: " dictionary
read -p "Grid: " grid

# Execute program 5 times, record each run time
RUN_TIME1=`./a.out $dictionary $grid | tail -1`
RUN_TIME2=`./a.out $dictionary $grid | tail -1`
RUN_TIME3=`./a.out $dictionary $grid | tail -1`
RUN_TIME4=`./a.out $dictionary $grid | tail -1`
RUN_TIME5=`./a.out $dictionary $grid | tail -1`

# Calculate average run time of the five executions
AVG_RUNTIME=$((   ($RUN_TIME1 + $RUN_TIME2 + $RUN_TIME3 + $RUN_TIME4 + $RUN_TIME5) / 5   ))

# Print out the average run time
echo "Average Runtime: " $AVG_RUNTIME
