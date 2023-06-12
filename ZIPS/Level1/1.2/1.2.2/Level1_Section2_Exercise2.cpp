#include<iostream>
#include<string>
#include<vector>
#include <chrono>


void print_vec(std::vector<int> vec){
	std::cout << "[ ";
	for(auto & x: vec){
		std::cout << x ;
	}
	std::cout << " ]";
}

void benchmark(){
	
	auto startIni{std::chrono::steady_clock::now() };
	for(int i = 0; i < 2000; i++){
		std::vector<double> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	}

	auto endIni{ std::chrono::steady_clock::now()};
	
	auto IniTime = endIni - startIni;

	auto startAssign{std::chrono::steady_clock::now() };
	for(int i = 0; i < 2000; i++){
		std::vector<double> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
		std::vector<double>	copyvec{ vec};
	}	
	auto endAssign{ std::chrono::steady_clock::now()};
	
	auto AssignTime = endAssign - startAssign;
	std::cout << std::endl;
	std::cout << "Time it took for assign: " << (AssignTime - IniTime).count() << std::endl; 


	auto startCopy{std::chrono::steady_clock::now() };
	for(int i = 0; i < 2000; i++){
		std::vector<double> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
		std::vector<double> copyvec = vec;
	}	
	auto endCopy{ std::chrono::steady_clock::now()};
	
	auto CopyTime = endCopy - startCopy;
	std::cout << "Time it took for copy: " << (CopyTime - IniTime).count() << std::endl; 


	auto startMove{std::chrono::steady_clock::now() };
	for(int i = 0; i < 2000; i++){
	
		std::vector<double> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

		std::vector<double> copyvec = std::move(vec);
	}	
	auto endMove{ std::chrono::steady_clock::now()};
	
	auto MoveTime = endMove - startMove;
	std::cout << "Time it took for move: " << (MoveTime - IniTime).count() << std::endl; 

}

int main(){
	//base example with string movements
	std::string a = "abcde";
	std::string b;
	std::string c;
	//content unchanged
	std::cout << a << std::endl;
	std::cout << b << std::endl;	
	std::cout << c << std::endl;	
	b = std::move(a);
	c = std::move(a);
	//content changed a and c are empty, b is now full
	std::cout << a << std::endl;
	std::cout << b << std::endl;	
	std::cout << c << std::endl;	

	std::vector<int> vec1 {1, 2, 3, 4, 5, 6};
    std::vector<int> vec2 {0, 0, 0, 0, 0, 0};
	print_vec(vec1);
	print_vec(vec2);

	vec2 = std::move(vec1);	

	print_vec(vec1);
	print_vec(vec2);

	benchmark();
	
	return 0;
}	
