#include<iostream>
#include<cstdio>
#include<filesystem>
#include<system_error>
#include<string>
#include<fstream>
#include<boost/system/error_code.hpp>


//Part a 
boost::system::error_condition ReadFile(std::string file){
    
    //Open File
    std::ifstream in(file.c_str());

    //Return error condition if opening failed
    if(!in.is_open()){
  	  	return boost::system::errc::make_error_condition(boost::system::errc::no_such_file_or_directory);
	}	
	
	std::cout << in.rdbuf() << std::endl;
	
	in.close();

	return boost::system::error_condition();
}

//Part c
std::error_condition ReadFile_cl1(std::string file){
    
    //Open File
    std::ifstream in(file.c_str());

    //Return error condition if opening failed
    if(!in.is_open())  return std::make_error_condition(std::errc::no_such_file_or_directory);
	
	std::cout << in.rdbuf() << std::endl;

	in.close();

	return std::error_condition();
}

int main(){
    //Part a
    std::filesystem::path file_path = "file1.txt";

    std::string file1(file_path);
    std::cout << "Openening File 1: " << file1 << std::endl;
    std::cout << "Error Condition 1: " << ReadFile(file1).message() << std::endl;

    //Part b, reading in a non existing file
    std::string file2("No File");
    std::cout << "Openening File 2: " << file2 << std::endl;
    std::cout << "Error Condition 1: " << ReadFile(file2).message() << std::endl;

    //Part c, reading in a file with the c++11 functionality
    std::cout << "Openening File 1 with C++11 : " << file1 << std::endl;
    std::cout << "Error Condition 1: " << ReadFile_cl1(file1).message() << std::endl;
    return 0;
}
