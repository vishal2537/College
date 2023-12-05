#!/usr/bin/bash
rm -rf output
hadoop jar /home/vishal/hadoop/share/hadoop/tools/lib/hadoop-streaming-3.3.6.jar -input inputfile -output output -mapper mapper.py -reducer reducer.py 
cat output/part-00000 

# cat big.txt | ./mapper.py | sort -t \t -k1 | ./reducer.py