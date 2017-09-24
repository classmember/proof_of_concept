#include <iostream>
#include <string>
#include <regex>

/**
 * compile:
 * g++ -g strip_ip_addresses.cpp -o strip_ip_addresses
 *
 * run:
 * ./strip_ip_addresses
 */

/**
 * @note this is the regex used for the IP address:
 *
 * \b(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.
 *   (25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.
 *   (25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.
 *   (25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\b
 *
 * @see https://www.regular-expressions.info/ip.html
 */

int main ()
{
  std::string s ("  This is an IP address: 100.4.102.154.\n"
                 "  Here's another: 12.34.56.78\n"
                 "  34.56.78.90 -- that's one too.\n");
  std::smatch m;
  std::regex e ("(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                   "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                   "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                   "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)");

  std::cout << "Target sequence:\n"
            << s << "\n";

  std::cout << "Regular expression:\n"
            << "  /(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.\n"
            << "     (25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.\n"
            << "     (25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.\n"
            << "     (25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)/\n";

  std::cout << "The following matches and submatches were found:\n";
  while (std::regex_search (s,m,e)) {
    for (auto x:m) std::cout << "  " << x << std::endl;
    s = m.suffix().str();
  }
  return 0;
}
