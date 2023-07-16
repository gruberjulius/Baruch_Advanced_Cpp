#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>


int main() {
    std::string sA("a = 1, b = 2, c = 3");

    // Define the regular expression with the delimiter ","
    std::regex regexDelimiter(",");

    // Use std::sregex_token_iterator to extract substrings
    std::sregex_token_iterator iter(sA.begin(), sA.end(), regexDelimiter, -1);
    std::sregex_token_iterator end;

    // Store the extracted substrings in a vector
    std::vector<std::string> substrings(iter, end);

    // Print the extracted substrings
    for (const auto& substring : substrings) {
        std::cout << substring << std::endl;
    }


    // Process each substring
    for (const auto& substring : substrings) {
        std::vector<std::string> parts;
        boost::split(parts, substring, boost::is_any_of("="));

        // Ensure both left and right parts are present
        if (parts.size() == 2) {
            std::string key = boost::trim_copy(parts[0]);
            std::string value = boost::trim_copy(parts[1]);

            std::cout << "Key: " << key << ", Value: " << value << std::endl;
        }
    }

    return 0;
}
