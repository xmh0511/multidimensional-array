#include <iostream>
#include "mul_array.hpp"
int main()
{
    Arr<int,2,3,3> ar;
    ar[1][1] = 1024;
    std::cout<< ar[1][1]<<std::endl;
    ar[2][2] = 2048;
    std::cout<<ar[2][2]<<std::endl;
    std::cout<< ar[1][1]<<std::endl;
    Arr<int,1,3> one;
    one[0] = 300;
    std::cout<<one[0]<<std::endl;
    return 0;
}