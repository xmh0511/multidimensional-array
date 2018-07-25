#include <iostream>
#include "multielement_array.hpp"
struct data
{
    int id;
    std::string text;
};
int main()
{
    xmh::Array<int,3,3> ar;
    ar[1][1] = 1024;
    std::cout<< ar[1][1]<<std::endl;
    ar[2][2] = 2048;
    std::cout<<ar[2][2]<<std::endl;
    std::cout<< ar[1][1]<<std::endl;
    xmh::Array<int,3> one;
    one[0] = 300;
    std::cout<<one[0]<<std::endl;
    xmh::Array<double,2,2,3> two;
    two[1][1][2] = 10.023;
    std::cout<<two[1][1][2]<<std::endl;
    xmh::Array<data,2,2> s_arr;
    s_arr[0][1]={1024,"just a test"};
    std::cout<<s_arr[0][1].id<<"-------"<<s_arr[0][1].text<<std::endl;
    return 0;
}