#include <string>
#include <boost/bimap.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/bimap/list_of.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <iostream>

//Part A
// Creation of the combinations
using setList = boost::bimap < boost::bimaps::set_of<std::string>, boost::bimaps::list_of<int>>;
using setSet = boost::bimap < boost::bimaps::set_of<std::string>, boost::bimaps::set_of<int>>;
using setUnord = boost::bimap < boost::bimaps::set_of<std::string>, boost::bimaps::unordered_set_of<int>>;
using multiList = boost::bimap < boost::bimaps::multiset_of<std::string>, boost::bimaps::list_of<int>>;
using multiSet = boost::bimap < boost::bimaps::multiset_of<std::string>, boost::bimaps::set_of<int>>;
using multiUnord = boost::bimap < boost::bimaps::multiset_of<std::string>, boost::bimaps::unordered_set_of<int>>;
using unordList = boost::bimap < boost::bimaps::unordered_set_of<std::string>, boost::bimaps::list_of<int>>;
using unordSet = boost::bimap < boost::bimaps::unordered_set_of<std::string>, boost::bimaps::set_of<int>>;
using unordUnord = boost::bimap < boost::bimaps::unordered_set_of<std::string>, boost::bimaps::unordered_set_of<int>>;

// Part C
// template function to print bimap
template <typename Bimap>
void print(const Bimap& bimap) {
	for (auto it = bimap.begin() ; it != bimap.end(); ++it) {
		std::cout << it->left << " : " << it->right << ", ";
	};
	std::cout << std::endl;
}

int main() {

	// Part B
    // Defining custom lists for each case

	setList bm1;
	bm1.insert(setList::value_type("A", 1));
	bm1.insert(setList::value_type("B", 2));
	bm1.insert(setList::value_type("C", 3));
	std::cout << "set-list: ";
	print(bm1);

	setSet bm2;
	bm2.insert(setSet::value_type("A", 1));
	bm2.insert(setSet::value_type("B", 2));
	bm2.insert(setSet::value_type("C", 3));
	std::cout << "set-set: ";
	print(bm2);

	setUnord bm3;
	bm3.insert(setUnord::value_type("A", 1));
	bm3.insert(setUnord::value_type("B", 2));
	bm3.insert(setUnord::value_type("C", 3));
	std::cout << "set-unorderedset: ";
	print(bm3);

	multiList bm4;
	bm4.insert(multiList::value_type("A", 1));
	bm4.insert(multiList::value_type("B", 2));
	bm4.insert(multiList::value_type("C", 3));
	std::cout << "multiset-list: ";
	print(bm4);

	multiSet bm5;
	bm5.insert(multiSet::value_type("A", 1));
	bm5.insert(multiSet::value_type("B", 2));
	bm5.insert(multiSet::value_type("C", 3));
	std::cout << "multiset-set: ";
	print(bm5);

	multiUnord bm6;
	bm6.insert(multiUnord::value_type("A", 1));
	bm6.insert(multiUnord::value_type("B", 2));
	bm6.insert(multiUnord::value_type("C", 3));
	std::cout << "multiset-unorderedset: ";
	print(bm6);

	unordList bm7;
	bm7.insert(unordList::value_type("A", 1));
	bm7.insert(unordList::value_type("B", 2));
	bm7.insert(unordList::value_type("C", 3));
	std::cout << "unorderedset-list: ";
	print(bm7);

	unordSet bm8;
	bm8.insert(unordSet::value_type("A", 1));
	bm8.insert(unordSet::value_type("B", 2));
	bm8.insert(unordSet::value_type("C", 3));
	std::cout << "unorderedset-set: ";
	print(bm8);

	unordUnord bm9;
	bm9.insert(unordUnord::value_type("A", 1));
	bm9.insert(unordUnord::value_type("B", 2));
	bm9.insert(unordUnord::value_type("C", 3));
	std::cout << "unorderedset-unorderedset: ";
	print(bm9);

}
