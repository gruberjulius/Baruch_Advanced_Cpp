#include <boost/bimap.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <string>
#include <iostream>
#include <tuple>

// Part A

// 1:N assosication between title and author

using bm_type = boost::bimap<
	boost::bimaps::multiset_of<std::string>,
	boost::bimaps::set_of<std::string>,
	boost::bimaps::with_info<double>
>;

using value_type = bm_type::value_type;

// abstract assosication between title and author
using bm_type_abstract = boost::bimap<
	boost::bimaps::multiset_of<std::string>,
	boost::bimaps::set_of<std::string>,
	boost::bimaps::with_info<std::tuple<std::string,double>>
>;

using value_type_abstract = bm_type_abstract::value_type;

int main() {

	bm_type books;

	books.insert(value_type("Mark Twain", "Huckelberry Finn", 5));
	books.insert(value_type("JKR", "Harry Potter", 10));
	books.insert(value_type("Tolkien", "Lord of the Rings", 15));

	// Part B

    //print book from specific author
	auto search = books.left.find("JKR");
	std::cout << search->first << " has written '" << search->second << "' which costs " << search->info << std::endl;


	// Part C

    //abstract book
	bm_type_abstract books2;

	books2.insert(value_type_abstract(
		"Mark Twain",
		"Huckelberry Finn", 
		std::make_tuple("A boy and his adventures", 5)));

	books2.insert(value_type_abstract(
		"JKR", 
		"Harry Potter", 
		std::make_tuple("A little boy fighting against voldemordt", 10)));

	books2.insert(value_type_abstract(
		"Tolkien", 
		"Lord of the Rings", 
		std::make_tuple("Some hobbits walking arround", 15)));

	books2.insert(value_type_abstract(
		"Tolkien", 
		"Simarilion", 
		std::make_tuple("More stories", 20)));


	// printing book price from given author
	auto search2 = books2.left.find("Tolkien");
	std::cout << search2->first << " has written '" << search2->second << "' which costs " << std::get<0>(search2->info) << std::endl;
}
