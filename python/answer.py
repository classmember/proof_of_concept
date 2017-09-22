#!/usr/bin/python
'''
answer() - answers riddle
    
:example:
    >>> print answer()
    one fifths, two fifths, red fifths, blue fifths.
    >>> print answer('titles')
    one titles, two titles, red titles, blue titles.
    >>> print answer('titles', ['little', 'big', 'old', 'rigged'])
    little titles, big titles, old titles, rigged titles.
'''

def answer(noun = 'fifths', adjectives = ['one', 'two', 'red', 'blue']):
    '''
    :param noun: noun of answer
    :param adjectives: adjectives of answer
    :return: string containing answer
    '''
    ans = ''
    for word in adjectives:
        ans += word + ' ' + noun + ', '
    return ans[:-2] + '.'
