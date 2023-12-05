#!/usr/bin/bash

rm -rf output
hadoop jar /home/vishal/hadoop/share/hadoop/tools/lib/hadoop-streaming-3.3.6.jar -input iris.data -output output -mapper mapper.py -reducer reducer.py 
cat output/part-00000 

# cat iris.data | ./mapper.py | sort | ./reducer.py