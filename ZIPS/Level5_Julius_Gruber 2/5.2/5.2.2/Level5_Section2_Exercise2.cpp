#include <iostream>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>

int main()
{
    boost::regex mySearchReg("(rain)|(Spain)");

    std::string myText("The rain in Spain stays mainly on the plain");

    boost::smatch match;
    std::cout << "match found: " << std::boolalpha << boost::regex_search(myText, match, mySearchReg) << std::endl;
    int n = match.size();
    for(int i = 0;i < n;i++){
        std::cout << "result: " << match[i] << std::endl;
    }
    return 0;
}
