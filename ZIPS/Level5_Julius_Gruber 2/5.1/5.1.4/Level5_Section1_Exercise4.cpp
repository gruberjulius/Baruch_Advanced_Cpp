#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>
#include <list>
#include <boost/algorithm/string.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"

using Data = std::tuple<boost::gregorian::date, std::vector<double>>;
using ResultSet = std::list<Data>;

ResultSet read_csv(const std::string& filename) {
    //activate the filestream
    std::fstream file(filename);
    //if file is not opened
    if (!file.is_open()) {
        std::cout << "Failed to open " << filename << std::endl;
        return ResultSet();
    } else {
        //if file is opened
        ResultSet data;
        std::string line;
        std::getline(file, line);  // Removing the header
        //load the data in the file
        while (std::getline(file, line)) {
            std::vector<std::string> row;
            boost::split(row, line, boost::is_any_of(","));

            std::vector<double> numbers;
            for (int i = 1; i < row.size(); ++i) {
                numbers.push_back(boost::lexical_cast<double>(row[i]));
            }

            data.push_back(std::make_tuple(boost::gregorian::from_simple_string(row[0]), numbers));
        }

    //return the data
    return data;
    }
}

int main() {

	auto data{ read_csv("data.csv") };
	
}
