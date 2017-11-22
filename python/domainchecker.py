#!/opt/imh-python/bin/python2.7
'''
Checks domains in /etc/trueuserdomains and looks for obvious
fraud or phishing domains on cPanel servers.
'''

import re
from rads.common import send_email


__version__ = 'v0.1 Fraud Domain Checker'
__author__ = 'Riley, Kolby'


class DomainChecker():
    '''
    Checks for suspicious domain names on cPanel servers
    and sends an email notification if any are found.
    Both the badwords and whitelist are stored in a plain text file.
    '''

    def __init__(self,
                 badwords_file='/opt/domainchecker/badwords',
                 whitelist_file='/opt/domainchecker/whitelist',
                 domains_file='/etc/trueuserdomains'):
        '''
        Load definitions, whitelist, and domains
        Initialize list for matches

        :param badwords_file: - plain text file of possible phishing terms.
        :param whitelist_file: - plain text file of known good domains.
        :param domains_file: - plain text file of domains on the server.
        '''
        # Load definitions
        self.definitions = []
        self.load_definitions(badwords_file)

        # Load whitelist
        self.whitelist = []
        self.load_whitelist(whitelist_file)

        # Load domains
        self.domains = []
        self.load_domains(domains_file)

        # Remove whitelist domains from domains list
        for domain in self.domains:
            if domain in self.whitelist:
                self.domains.remove(domain)
        
        # List of matches found
        self.matches = []
        self.match_text = ""

    def load_definitions(self, target_file):
        '''
        Returns definitions of possible phishing words from file.

        :param file: File to load definitions from.
        '''
        try:
            with open(target_file, "r") as definitions_file:
                for line in definitions_file:
                    self.definitions.append(line.strip())
        except IOError:
            print 'ERROR: Could not open ' + target_file

    def load_whitelist(self, target_file):
        '''
        Returns whitelist domains from file.

        :param file: File to load whitelist from.
        '''
        try:
            with open(target_file, "r") as whitelist_file:
                for line in whitelist_file:
                    self.whitelist.append(line.strip())
        except IOError:
            print 'ERROR: Could not open ' + target_file

    def load_domains(self, target_file):
        '''
        Returns domains on the server as a list.

        :param file: File to load domains on the server.
        '''
        domain_pattern = re.compile(r'^(.*):')
        try:
            with open(target_file, "r") as domains_file:
                for line in domains_file:
                    # Strip away domain owner and just get domain
                    domain = domain_pattern.search(line)
                    line = domain.group()[:-1]
                    self.domains.append(line.strip())
        except IOError:
            print 'ERROR: Could not open ' + target_file

    def run(self):
        '''
        Open /etc/trueuserdomains and checks every line from the badwords list.
        Matches found that are in the whitelist are ignored
        '''
        for domain in self.domains:
            for bad_word in self.definitions:
                if bad_word in domain:
                    self.matches.append(domain)
                    self.match_text += ('Match: ' + domain +
                                        ' contains the text \"' +
                                        bad_word + '\"\n')
        if not self.matches:
            print 'No matches to possible phishing words found.'
        else:
            print self.match_text,
            self.send_str()

    def send_str(self):
        '''
        Send a notification via smtplib.
        '''
        to_addr = 'str@imhadmin.net'
        subject = 'Possible fraudulent or phishing domains found!'
        body = ('The following domains contain keywords that may be '
                'fraudulent activity-\n\n' + self.match_text)
        if send_email(to_addr, subject, body) is False:
            print ('ERROR: Could not send str regarding '
                   'possible phishing domain failed.')


def main():
    '''
    Run domain checker.
    '''
    checker = DomainChecker()
    checker.run()

if __name__ == "__main__":
    main()
