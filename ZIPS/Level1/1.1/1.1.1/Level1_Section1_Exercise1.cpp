#include<iostream>
#include<vector>
#include<array>

int main(){
	
    std::vector<double> vec= {1, 2 ,3, 4, 5};

	const int mult = 2;

    // a.

    std::transform(vec.begin(), vec.end(), vec.begin(), [=](double& i){return mult *i;});

     for(const auto & b: vec){ 
        std::cout << b << std::endl;
     }

     
     // b.
     vec= {1, 2 ,3, 4, 5};

    std::transform(vec.begin(), vec.end(), vec.begin(), [&](double& i){return mult *i;});

     for(const auto & b: vec){ 
        std::cout << b << std::endl;
     }

     // c.

     auto minmax = [](std::vector<double> vec){return std::make_pair(*std::min_element(vec.begin(), vec.end()), *std::max_element(vec.begin(), vec.end()));};

    auto result = minmax(vec);
    std::cout << result.first << "  " <<  result.second << std::endl;

    //d.

    auto result2 = std::minmax_element(vec.begin(), vec.end());
    std::cout << *result2.first  << "  " <<  *result2.second  << std::endl;


    return 0;  
}	

