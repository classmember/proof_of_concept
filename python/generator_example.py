#!/usr/bin/env python
# generator_example.py

# open words_alpha.txt from:
# https://github.com/dwyl/english-words
f = open("words_alpha.txt")

# define generator that gets the next ten words
def next_ten_words():
    for word in range(10):
        yield( f.next() )

# use the generator through a for loop iteration
for word in next_ten_words():
    print( word )

# use the generator through a for loop iteration again
for word in next_ten_words():
    print( word )

# notice how the values are different each time?
for word in next_ten_words():
    print( word )

# close words_alpha.txt
f.close()
