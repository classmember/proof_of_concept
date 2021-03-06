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
    std::string source_text (
        "  This is an IP address: 100.4.102.154.\n"
        "  Here is another: 12.34.56.78\n"
        "  3.147.12.42 - another\n");
    std::smatch matches;
    std::regex ip_address_pattern (
                   "\\b(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                   "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                   "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                   "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");

    std::cout << "Target sequence:\n"
            << source_text << "\n";

    std::cout << "Regular expression:\n"
            << "  /\\b(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.\n"
            << "     (25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.\n"
            << "     (25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.\n"
            << "     (25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b/\n\n";

    std::cout << "The following matches were found:\n";
    while (std::regex_search (source_text,
                              matches,
                              ip_address_pattern)) {
        // for each match
        for (auto match:matches) {
            // if match is at least minimum size of IP address
            if (match.length() >= 7) {
                std::cout << "  " << match << "\n";
            }
        }
        source_text = matches.suffix().str();
    }
    std::cout << "\n";
    return 0;
}
