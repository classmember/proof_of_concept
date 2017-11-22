#include <iostream>
#include <fstream>
#include <string>
#include <regex>

/**
 * compile:
 * g++ -O2 strip_ip_addresses_from_file.cpp -o scrape_ip
 *
 * run:
 * ./scrape_ip source_text.txt
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


int main (int argc, char *argv[])
{
    const std::string usage ("Usage: scrape [FILE]\n");
    std::ifstream input_file("source_text.txt");

    // make sure user provided an argument
    if ( argc != 3 ) {
        std::cout << usage;
        return 255;
    }

    // open file and read into string
    std::string source_text (
        (std::istreambuf_iterator<char>(input_file)),
        std::istreambuf_iterator<char>());

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
