#include<iostream>
#include<string>
#include"span"
#include<tuple>
#include<vector>
#include <algorithm>
#include "boost/date_time/gregorian/gregorian.hpp"
#include <array>

//defines a person object
using Person = std::tuple<std::string, std::string, boost::gregorian::date>;


//Part B:
//prints a information about a person
void print_Person(Person t){
	std::cout << "Name of the Person: " << std::get<0>(t) << " Adress of Person: " << std::get<1>(t) 
		<< " Birthday of Person: " <<  std::get<2>(t) << std::endl;
}

//compares different birthday with the comparison operator
bool compare_Birthday(Person const One, Person Two){
	return std::get<2>(One) < std::get<2>(Two);
}

//Part D:
//Input: List of People
//Output: List of People sorted by BirthDate
void sort_Person(std::vector<Person>& People){

	std::sort(People.begin(), People.end(), compare_Birthday);
}

//Input: List of People
//Output: Print list of people
void print_People( std::vector<Person> People ){
	int n = People.size();
	std::cout << "List of people by name: ";
	for(int i = 0; i < n; i++){
		print_Person(People[i]);
	}
	std::cout << std::endl;
}

//print the span range of people
void printSpanRange(const std::span<int>& span){
	std::cout << "Range Based for loop: ";
	for(auto i: span){
		std::cout << i << std::endl;
	}
	std::cout << std::endl;
}

//print the list of people with an iterator
void printIterator(const std::span<int>& span){
	std::cout << "Iterator Based for loop: ";
	for(auto ptr{span.begin()}; ptr != span.end(); ++ptr){
		std::cout << *ptr << std::endl;
	}
	std::cout << std::endl;
}

//print with span 
void printSpanIndex(const std::span<int>& span){
	std::cout << "Index Based for loop: ";
	int n = span.size();
	for(auto ptr{0}; ptr != n; ptr++){
		std::cout << span[ptr] << std::endl;
	}
	std::cout << std::endl;
}

//get the first n elements in the span
std::span<int> n_first_elem_span(const std::span<int>& span, int N){
	return span.first(N);	
}

//get the last n elements in the span
std::span<int> n_last_elem_span(const std::span<int>& span, int N){
	return span.last(N);	
}

void testSubspan(const std::span<int>& span, int start, int length){
	auto subspan {span.subspan(start, length)};
	printSpanRange(subspan);
}


int main(){
	//Part A
	Person Julius = std::make_tuple("Julius Gruber", "Klammstrasse 3", boost::gregorian::date{1999, 9, 9} );
	print_Person(Julius);
	std::get<1>(Julius) = "New York";
	print_Person(Julius);
	Person Alfred = std::make_tuple("Alfred Gruber", "Klammstrasse 3", boost::gregorian::date{1974, 9, 3} );

	std::vector<Person> People = {Julius, Alfred};

	//Part C 
	//Part D
	print_People(People);
	sort_Person(People);
	print_People(People);

	int list[3] = {1, 2, 3};
	std::array<int, 4> fixed_arr {1, 2, 3, 4};
	std::vector<int> var_arr {1, 2, 3, 4, 5};

	//Part E
	auto span1 = std::span(list);
	printSpanRange(span1);
	auto span2 = std::span(fixed_arr);
	printIterator(span2);
	auto span3 = std::span(var_arr);
	printSpanIndex(span3);

	printSpanIndex(span1.first(2));
	printSpanIndex(span1.last(2);	
	printSpanIndex(n_first_elem_span(span1, 2));
	printSpanIndex(n_last_elem_span(span1, 2));

	testSubspan( span3, 0, 5);
	testSubspan( span3, 2, 3);

	// Bytes stuff
	float data[1]{ 3.141592f };
	auto const const_bytes = std::as_bytes(std::span{ data });
	for (auto const b : const_bytes)
	{
		std::cout << std::setw(2)
			<< std::hex
			<< std::uppercase
			<< std::setfill('0')
			<< std::to_integer<int>(b) << ' ';
	}
	
	// this code seems to show the value of the bytes that are set 
	// for the float number of pi

	return 0;
}
