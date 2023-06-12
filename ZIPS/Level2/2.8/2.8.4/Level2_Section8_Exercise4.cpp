#include<iostream>
#include<vector>


std::vector<bool> Intersect(std::vector<bool> v1, std::vector<bool> v2) {
    std::vector<bool> output(v1.size());
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] == v2[i]) {
            output[i] = 1;
        }
        else {
            output[i] = 0;
        }
    };
    return output;
}

int main(){
    /*Part a:
   * Benefits:
        * Dynamic Size managment as it is an vector in comparision to the bitset, but not against the boost version
        * Non Contigous storage in memory: might be a benefit or an disadtvantage
        * provides iterator support
        * No subset version in comparison
        * abstract functionality from std::vector available
        * find_first() and find_next() for searching for specific bits within the bitset, which is not included in std::vector
        * performance 
    */
    
    std::vector<bool> v1 = { 1, 0, 1, 1, 0 };
    std::vector<bool> v2 = { 1, 0, 1, 0, 0 };
    auto intersect_out = Intersect(v1, v2);
    for (int i = 0; i < 5; i++)
        std::cout << v1[i] << ' ';


    std::cout << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << v2[i] << ' ';

    std::cout << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << intersect_out[i] << ' ';

    
    std::cout << std::endl;

    //Better to use functionality from the bitset classes
    return 0;
}
