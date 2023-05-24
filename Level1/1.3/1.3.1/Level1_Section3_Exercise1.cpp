#include<iostream>

//Task B)
void print(){};
//this is the tail function


// Variadic function Template that takes
// variable number of arguments and prints
// all of them.
template <typename T, typename... Types>
void print(T var1, Types... var2)
{
	std::cout << var1 << std::endl;
      
	print(var2...);
}


int main(){
    // Variadic function templates
    int j = 1; double d = 2.0;
    print(j); print(d); print(j, d); print(d, j);
    std::cout << "\n3 params \n";
    print(d, j, std::bitset<8>(233));
    return 0;
}
