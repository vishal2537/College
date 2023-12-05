#!/usr/bin/bash

# cd "/home/Lab9/Q0"
rm -rf output
hadoop jar /home/vishal/hadoop/share/hadoop/tools/lib/hadoop-streaming-3.3.6.jar -input big.txt -output output -mapper mapper.py -reducer reducer.py 

# cat big.txt | ./mapper.py | sort | ./reducer.py
cat output/part-00000 