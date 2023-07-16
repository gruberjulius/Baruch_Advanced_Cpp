//Part A
//The regular expression std::regex ecmaReg("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?") includes various kinds of numbers. 
//Integer numbers: It matches numbers consisting of one or more digits, some with a plus (+) or minus (-) sign.
//Decimal numbers: It matches numbers with a decimal point followed by one or more digits. The decimal part is not required
//Exponential notation: It matches numbers in exponential notation, where "e" or "E" represents the exponent and can be followed by an optional plus or minus sign and one or more digits.

//Part B
#include <iostream>
#include <regex>
#include <string>

bool isValidNumber(const std::string& number) {
    std::regex ecmaReg("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?");
    return std::regex_match(number, ecmaReg);
}

int main() {
    std::string validNumbers[] = {
        "123",
        "-45",
        "3.14",
        "+0.5",
        "2e3",
        "-1.23e-4"
    };

    std::string invalidNumbers[] = {
        "abc",
        "12.34.56",
        "1e",
        "e2",
        "1.2.3",
    };

    // Testing valid numbers
    std::cout << "Valid Numbers:" << std::endl;
    for (const auto& number : validNumbers) {
        if (isValidNumber(number)) {
            double value = std::stod(number);
            std::cout << number << " (Converted to double: " << value << ")" << std::endl;
        } else {
            std::cout << number << " (Invalid)" << std::endl;
        }
    }

    // Testing invalid numbers
    std::cout << "\nInvalid Numbers:" << std::endl;
    for (const auto& number : invalidNumbers) {
        if (isValidNumber(number)) {
            double value = std::stod(number);
            std::cout << number << " (Converted to double: " << value << ")" << std::endl;
        } else {
            std::cout << number << " (Invalid)" << std::endl;
        }
    }

    return 0;
}


//Part C
//we sue the stod function to convert to double and print next to value in the code
