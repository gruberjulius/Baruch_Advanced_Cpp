#include <iostream>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>

int main() {


	// Part a
	std::cout << std::boolalpha;

	boost::regex myReg("[a-z]*");
	boost::regex myReg2("[a-z]+");

	std::string s1("aza");
	std::string s2("1");
	std::string s3("b");
	std::string s4("ZZ TOP");

	std::cout << s1 << ", " << boost::regex_match(s1, myReg) << std::endl;
	//true, is matching
	std::cout << s2 << ", " << boost::regex_match(s2, myReg) << std::endl;
	//false, numbers are not included
	std::cout << s3 << ", " << boost::regex_match(s3, myReg) << std::endl;
	//true, matching the expression
    std::cout << s4 << ", " << boost::regex_match(s4, myReg) << std::endl;
	//   false, blanck space included 

	std::cout << s1 << ", " << boost::regex_match(s1, myReg2) << std::endl;
	//   true, matching the expresson 
	std::cout << s2 << ", " << boost::regex_match(s2, myReg2) << std::endl;
	//   false, containes numbers
    std::cout << s3 << ", " << boost::regex_match(s3, myReg2) << std::endl;
	//   true, myReg2 range matching the expression
	std::cout << s4 << ", " << boost::regex_match(s4, myReg2) << std::endl;
	//   false, myReg does not contain upper alpha 

	// Part B

	boost::regex myNumericReg("\\d{2}");
	std::string f("34");
	std::string s("345");

	std::cout << f << ", " << boost::regex_match(f, myNumericReg)<< std::endl;  
	//   true, myNumericRegdigits has 3 digits
	std::cout << s << ", " << boost::regex_match(s, myNumericReg) << std::endl;
	//   false, has 3 digits 

	// Part C

	boost::regex myAltReg("(new)|(delete)");
	std::string s4A("new");
	std::string s5("delete");
	std::string s6("malloc");

	std::cout << s4A << ", " << boost::regex_match(s4A, myAltReg) << std::endl;  
	//   true, "new" one of the two options
	std::cout << s5 << ", " << boost::regex_match(s5, myAltReg) << std::endl;  
	//   true, "delete" is the keyword
	std::cout << s6 << ", " << boost::regex_match(s6, myAltReg) << std::endl;
	//   false, "malloc" not included in the list 


	// Part D

	boost::regex myReg3("A*");
	boost::regex myReg4("A+");
	boost::regex myReg5("(\\d{2})");
	boost::regex myReg6("\\d{2, 4}");
	boost::regex myReg7("\\d{1,}");

	std::string testA("1");

	std::cout << testA << ", " << boost::regex_match(testA, myReg3) << std::endl;  
	//   false, 1 is not not A
	std::cout << testA << ", " << boost::regex_match(testA, myReg4) << std::endl;
	//   false, 1 is not A and not working
	std::cout << testA << ", " << boost::regex_match(testA, myReg5) << std::endl;
	//   false, myReg5 wants 2 digits and only received 1 
	std::cout << testA << ", " << boost::regex_match(testA, myReg6) << std::endl;
	//   false, myReg6 wants to get 2 or 4 digits
	std::cout << testA << ", " << boost::regex_match(testA, myReg7) << std::endl;
	//   true, myReg7 wants 1 or more digits

	// Part E

	boost::regex rC("(\\w)*"); // Alphanumeric (word) A-Za-z0-9
	boost::regex rC1("(\\W)*"); // Not a word
	boost::regex rC2("[A-Za-z0-9_]*"); // Alphanumeric (word) A-Za-z0-9

	std::string sC1("abc");
	std::string sC2("A12678Z909za");

	std::cout << sC1 << ", " << boost::regex_match(sC1, rC) << std::endl;  
	//  true, abc is alphanumeric characters
	std::cout << sC1 << ", " << boost::regex_match(sC1, rC1) << std::endl;  
	//   true, abs is not a word  characters
	std::cout << sC1 << ", " << boost::regex_match(sC1, rC2) << std::endl;  
	//   true abc is alphanumeric characters
	std::cout << sC2 << ", " << boost::regex_match(sC2, rC) << std::endl;
	//   true, is alphanumeric characters
	std::cout << sC2 << ", " << boost::regex_match(sC2, rC1) << std::endl;
	//   true, is not a word characters
	std::cout << sC2 << ", " << boost::regex_match(sC2, rC2) << std::endl;
	//   true is alphanumeric characters

}
