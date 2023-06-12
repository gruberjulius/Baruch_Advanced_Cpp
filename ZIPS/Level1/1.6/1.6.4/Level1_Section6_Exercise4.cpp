#include<iostream>
#include<list>
#include<algorithm>
//Given Code

// C++ 98 approach
// Data storage types
template <typename T> struct old_Storage
{
    // Possible ADTs and their memory allocators
    // typedef std::vector<T, CustomAllocator<T>> type;
    // typedef std::vector<T, std::allocator<T>> type;

    typedef std::list<T, std::allocator<T>> type;

};

template <typename T>
class old_Client
{
    // An example of Composition
private:
    typename old_Storage<T>::type data; // typename mandatory

public:
    old_Client(int n, const T& val) : data(n, val) {};
    void print() const {
        std::for_each(data.begin(), data.end(),
            [](const T& n) { std::cout << n << ", "; });
        std::cout << '\n';
    }
};

//Alias template instead
template<typename T>
class new_Client{
	using new_Storage = std::list<T, std::allocator<T>>;

private:
	new_Storage data;

public:

	new_Client(int n, const T& val): data(n, val) {};
	void print() const{
		std::for_each(data.begin(), data.end(),
            		[](const T& n) { std::cout << n << ", "; });
        	std::cout << '\n';
	};
};





int main(){
	// Client of storage using typedef (C++ 98)
	int n = 10; int val = 2;
	old_Client<int> old_Client(n, val); 
	old_Client.print();
	//behaviour as expected

	//using list
	new_Client<int> new_Client(n, val); 
	new_Client.print();
	//same result as before
	return 0;
}
