#!/usr/bin/env python
'''
scrape_ip_address.py: scrape_ip_address() - Find and return first IP address from a string.
'''
import re


def scrape_ip_address(line):
    '''
    Find and return first IP address from a string.

    :param line: string of text to search
    :returns: string -- IP address if found. If not, 'None' is returned.
    '''
    ip_regex = re.compile('(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.'
                          '(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.'
                          '(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.'
                          '(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)')
    match = ip_regex.search(line)
    if match:
        return match.group()
    else:
        return None

if __name__ == '__main__':
    print scrape_ip_address('2017-09-17 00:02:12 [106992] SMTP connection from (ylmf-pc) [195.154.41.63]:63671 I=[209.182.200.165]:25 lost')
