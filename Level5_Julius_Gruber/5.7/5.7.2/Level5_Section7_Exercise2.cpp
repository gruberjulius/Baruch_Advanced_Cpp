#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/list_of.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>


// Part A

// structs for tags
struct IpAddress {};
struct DomainName {};

// DNS type
using DNS = boost::bimap <
	boost::bimaps::unordered_set_of < boost::bimaps::tagged < boost::uuids::uuid, IpAddress >>,
	boost::bimaps::unordered_set_of < boost::bimaps::tagged < std::string, DomainName >>,
	boost::bimaps::list_of_relation
>;

// Part c

// function to print dns data
void print(const DNS& dnsDatabase) {
	std::cout << "currently existing : " << std::endl;
	for (auto it =  dnsDatabase.begin() ; it != dnsDatabase.end(); ++it) {
		std::cout << "- ip: " << it->get<IpAddress>() << ", domain: " << it->get<DomainName>() << std::endl;
	}
}

int main() {

	// Part B

	DNS dnsDatabase;
	boost::uuids::string_generator gen;

	// creating elements
	dnsDatabase.push_back(DNS::value_type( boost::uuids::uuid(gen("acde070d-8c4c-4f0d-9d8a-162843c10333")), "duckduckgo"));
	dnsDatabase.push_back(DNS::value_type( boost::uuids::uuid(gen("acde070d-8c4c-4f0d-9d8a-162843c10334")), "bing"));
	dnsDatabase.push_back(DNS::value_type( boost::uuids::uuid(gen("acde070d-8c4c-4f0d-9d8a-162843c10335")), "google"));

	
	// searching domain from ip
	boost::uuids::uuid searchIp{gen("acde070d-8c4c-4f0d-9d8a-162843c10333")};
	auto  searchIpIt = dnsDatabase.by<IpAddress>().find(searchIp);
	if (searchIpIt != dnsDatabase.by<IpAddress>().end()) {
		std::cout << "ip address '" << searchIp << "' has domain name: '" 
			<< searchIpIt->get<DomainName>() << "'" << std::endl;
	}

	// searching ip from domain
	std::string searchDomain{ "bing" };
	auto  searchDomainIt{ dnsDatabase.by<DomainName>().find(searchDomain) };
	if (searchDomainIt != dnsDatabase.by<DomainName>().end()) {
		std::cout << "domain name '" << searchDomain << "' has ip address: '"
			<< searchDomainIt->get<IpAddress>() << "'" << std::endl;
	}
	std::cout << std::endl;
	
	// Part c
	print(dnsDatabase);


}
