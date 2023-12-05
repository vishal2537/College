#!/usr/bin/env python3

from typing import Optional
import sys

current_word: Optional[str] = None
word: Optional[str] = None

for line in sys.stdin:
    word = line.strip()

    if word != current_word:
        print(current_word)
        current_word = word

if current_word == word:
    print(current_word)
