#include <string>
#include <boost/algorithm/string.hpp>
#include <iostream>

// Part b

//password function 
//trying without reference
bool password(const std::string s) {
	//check if the file
    if (s.size() < 8 ) {
		std::cout << "must be at least 8 characters" << std::endl;
		return false;
	}
	if (!boost::all(s, boost::is_alnum())){
		std::cout << "not alphanumeric" << std::endl;
		return false;
	}
    //check for lower case
	if (boost::all(s, boost::is_lower())) {
		std::cout << "no upper case" << std::endl;
		return false;
	}
    //check for control characters	
    if (boost::contains(s, "\*")) {
		std::cout << "no control characters" << std::endl;
		return false;
	}
    //check for spaces
	if (boost::contains(s, " ")) {
		std::cout << "no spaces" << std::endl;
		return false;
	}
    std::cout << "Legit Password" << std::endl;
	return true;
};

int main() {

	// Part a

	std::string str1(" abd1 234");

	// check if all digits or letters
	std::cout << std::boolalpha << boost::all(str1, boost::is_alnum()) << std::endl;
	// check if only digits
	std::cout << std::boolalpha << boost::all(str1, boost::is_digit()) << std::endl;
	// check if only characters 
	std::cout << std::boolalpha << boost::all(str1, boost::is_lower()) << std::endl;

    //Part b
    //Try the different passwords

	std::string pwd("DanielDuffy1952");
	password(pwd); //combination 
	pwd ="DanielDuffy";
	password(pwd);
	pwd = "U19520829";
	password(pwd);
	pwd = "19520829U";
	password(pwd);

    //all the 4 passwords are allowd
    return 0;
}
