#include<iostream>


int main(){

    int size = 4;
    double val = 2.71;
    std::vector<double> data(size, val);
    auto fun = [&data]() mutable
    {
    for (std::size_t i = 0; i < data.size(); ++i){
        data[i] = 3.14;
        std::cout << data[i] << ",";
    }
    std::cout << "\n";
    };

    fun();

	//Part A
    auto fun1 = [data = std::move(data)]() mutable
    {
    for (std::size_t i = 0; i < data.size(); ++i){
        data[i] = 3.15;
        std::cout << data[i] << ",";
    }
    std::cout << "\n";
    };

    fun1();


    for (std::size_t i = 0; i < data.size(); ++i){
        data[i] = 3.14;
        std::cout << data[i] << ",";
    }

    //Part B

    int x = 1'000'000;
    auto fun4 = [&r = x]()
    {
        r*=2;
        std::cout << "\nr" << r;
    };
    fun4();


    //Part C
    
    int size2 = 3;
    double val2 = 1.41;
    std::vector<double> data2(size2, val2);
    std::array<double, 3> data3 = { 1.2, 2.4, 4.7 };

    //again use move and mutable function
    auto fun3 = [array = std::move(data2), array2 = std::move(data3)]() mutable {
        for (std::size_t i = 0; i < array.size(); ++i) {
            array[i] = 3.14;
            std::cout << array[i] << "/";
        }

        std::cout << '\n';

        for (std::size_t i = 0; i < array2.size(); ++i) {
            array2[i] = 2.71;
            std::cout << array2[i] << "/";
        }
    };
   
	fun3();

    if (0 == data2.size() || 0 == data3.size())
    {
        std::cout <<"\nDouble arrays have no elements, OK\n";
    }
    else
    {
        std::cout <<"\n Ouch!\n";
        for (std::size_t i=0;i<data2.size(); ++i)
        {
        std::cout<<data2[i]<<"^"; 
        }
    
        for (std::size_t i = 0; i < data3.size(); ++i)
        {
        std::cout<<data3[i]<<"^"; 
        }
    }

	return 0;
}


