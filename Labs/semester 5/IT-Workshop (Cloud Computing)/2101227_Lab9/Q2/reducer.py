#!/usr/bin/env python3

import sys
from typing import Optional, List

current_word: Optional[str] = None
current_count: int = 0
word: Optional[str] = None

# input comes from STDIN
for line in sys.stdin:
    # remove leading and trailing whitespace
    line_new: List[str] = line.strip().split("\t", 1)

    # parse the input we got from mapper.py
    # convert count (currently a string) to int
    word = line_new[0]
    count: int = int(line_new[1])

    # this IF-switch only works because Hadoop sorts map output
    # by key (here: word) before it is passed to the reducer
    if current_word == word:
        current_count += count
    else:
        if current_word:
            # write result to STDOUT
            print(f"{current_word}\t{current_count}")
        current_count = count
        current_word = word

# do not forget to output the last word if needed!
if current_word == word:
    print(f"{current_word}\t{current_count}")
