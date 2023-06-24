#include <iostream>
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"


using Data = std::tuple<boost::gregorian::date, std::vector<double>>; 
using ResultSet = std::list<Data>;

ResultSet get_csv(const std::string filename){
    std::fstream file(filename);

    ResultSet res;

    std::string row_string;
    std::getline(file, row_string);
    Data row_data;

    //reading in the needed lines
    while(std::getline(input, row_string)){
        std::vector<std::string> Vec;
        boost::split(Vec, row_string, boost::is_any_of(",")); //seperate from coma
        std::get<0>(row_data) = boost::gregorian::from_string(strVec[0]); //convert to gregorian

        // convert to double 
        for (int i = 1; i < strVec.size(); i++) {
            std::get<1>(row_data).push_back(boost::lexical_cast<double>(Vec[i]));  
            
        }
        //push back in result file
        res.push_back(row_data); 
    }

    return res;
}

int main(){
   ResultSet results = get_csv("data.csv");
   std::vector<double> first_row = std::get<1>(results.front());

   for(auto elem: first_row){
       std::cout << elem << std::endl;
   }

}
