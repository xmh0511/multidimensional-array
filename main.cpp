#include <iostream>
#include "mul_array.hpp"
int main()
{
    Arr<int,3,3> ar;
    ar[1][1] = 1024;
    std::cout<< ar[1][1]<<std::endl;
    ar[2][2] = 2048;
    std::cout<<ar[2][2]<<std::endl;
    std::cout<< ar[1][1]<<std::endl;
    Arr<int,3> one;
    one[0] = 300;
    std::cout<<one[0]<<std::endl;
    Arr<double,2,2,3> two;
    two[1][1][2] = 10.023;
    return 0;
}