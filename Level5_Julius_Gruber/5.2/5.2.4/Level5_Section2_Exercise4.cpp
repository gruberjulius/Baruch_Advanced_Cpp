#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main() {
    //Part A
    std::regex myReg10("/");
    std::string S3 = "2016/3/15";
    std::vector<std::string> extractedData;

    std::sregex_token_iterator it(S3.begin(), S3.end(), myReg10, -1);
    std::sregex_token_iterator end;

    for (; it != end; ++it) {
        extractedData.push_back(*it);
    }

    // Print the extracted data
    for (const auto& element : extractedData) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    //Part B
    std::vector<std::string> extractedData_1;

    std::sregex_token_iterator it_1(S3.begin(), S3.end(), myReg10, -1);

    for (; it_1 != end; ++it_1) {
        extractedData_1.push_back(*it_1);
    }

    // Print the extracted data
    for (const auto& element : extractedData_1) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    
    // Part C
    // used always a vector of strings

    return 0;
}
