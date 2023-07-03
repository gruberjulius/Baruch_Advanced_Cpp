#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"


//Part b

boost::gregorian::date date_parser(const std::string string){
    return  boost::gregorian::from_simple_string(string);  
}

//Part C
std::map<std::string, double> convertStringToMap(const std::string& input) {
  std::map<std::string, double> resultMap;

  std::stringstream ss(input);
  std::string token;

  while (std::getline(ss, token, ',')) {
    std::istringstream iss(token);
    std::string key, equals;
    double value;

    if (!(iss >> key >> equals >> value) || equals != "=") {
      // Invalid key-value pair format, skip to the next iteration
      continue;
    }

    resultMap[key] = value;
  }

  return resultMap;
}



int main(){
    //Part A
    std::string sA("1,2,3,4/5/9*56");

    //use a vector of strings to deallocate
    std::vector<std::string> strVec; 

    //splitting with boost splitting

    boost::split(strVec, sA, boost::is_any_of("/*,"));

    auto outStr { boost::join(strVec, "/")};

    std::cout << outStr << std::endl;

    //Part B
    std::string dateStr{ "2015-12-31" };
	auto greg_date = date_parser(dateStr);

    std::cout << greg_date << std::endl;


    //Part C

    std::string mapInput("port = 23, pin = 87, value = 34.4");
    std::map<std::string, double> resultMap = convertStringToMap(mapInput);

    // Print the resulting map
    for (const auto& pair : resultMap) {
        std::cout << pair.first << " = " << pair.second << std::endl;
    }

}
