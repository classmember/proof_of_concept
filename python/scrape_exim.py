#!/usr/bin/env python
'''
Search log entries in past hour for a string
and return first IP address in entry.
'''

import re
import datetime
from dateutil import parser


def scrape_exim(search_term='ylmf-pc', log='/var/log/exim_mainlog'):
    '''
    Returns first IP address from line in log file matching search term.

    :param search_term: string of text to search
    :param log: file to open for searching
    '''
    ip_list = []  # list of matching ip addresses
    one_hour_ago = datetime.datetime.now() - datetime.timedelta(hours=1)
    time_pattern = re.compile(r'^(.*\:\d\d) \[')

    with open(log, 'r') as log_file:
        for line in log_file:
            if time_pattern.search(line):
                entry_time = time_pattern.search(line)
                entry_datetime = parser.parse(entry_time.group(1))
                if entry_datetime > one_hour_ago:
                    if re.search(search_term, line):
                        ip_list.append(str(scrape_ip_address(line)))

    # return unique set of matching IP addresses
    return list(set(ip_list))


def scrape_ip_address(line):
    '''
    Find and return first IP address from a string.

    :param line: string of text to search
    :returns: string -- IP address if found. If not, 'None' is returned.
    '''
    ip_pattern = re.compile(r'(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.'
                            r'(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.'
                            r'(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.'
                            r'(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)')
    match = ip_pattern.search(line)
    if match:
        return match.group()
    else:
        return None

if __name__ == '__main__':
    print scrape_exim()
