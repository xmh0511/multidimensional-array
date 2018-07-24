//
// Created by dy2018 on 18-7-24.
//

#ifndef STRING_MUL_ARRAY_HPP
#define STRING_MUL_ARRAY_HPP
template<int...Numbers>
struct cal_multi
{
};
template<int First,int...Numbers>
struct cal_multi<First,Numbers...>
{
    static const int value = First*cal_multi<Numbers...>::value;
};
template<int Last>
struct cal_multi<Last>
{
    static const int value = Last;
};

template<typename T,int Dim,int...Args>
struct Arr
{

};
template<typename T,int Dim,int U,int...Args>
struct Arr<T,Dim,U,Args...>:Arr<T,Dim,Args...>
{
    Arr(long* pos_ptr = new long(),T* arr_ptr = new T[cal_multi<U,Args...>::value]):Arr<T,Dim,Args...>(pos_ptr,arr_ptr),weight(cal_multi<Args...>::value),_total_size(cal_multi<U,Args...>::value),_pos_ptr(pos_ptr),type_ptr(arr_ptr)
    {
    }
    Arr<T,Dim,Args...>& operator[](int index)
    {
        (*_pos_ptr) += (index * weight);
        return static_cast<Arr<T,Dim,Args...>&>(*this);
    }
    int weight;
    int _total_size;
    T* type_ptr = nullptr;
    long* _pos_ptr;
};
template<typename T,int Dim,int U>
struct Arr<T,Dim,U>
{
    Arr(long* pos_ptr = nullptr,T* arr_ptr= nullptr):weight(1),_pos_ptr(pos_ptr),type_ptr(arr_ptr)
    {
        if(_pos_ptr== nullptr){
            single_dim = true;
        }
        if(arr_ptr== nullptr){
            type_ptr = new T[U];
        }
    }
    ~Arr()
    {
        delete []type_ptr;
    }
    T& operator[](int index)
    {
        int tmp_pos = 0;
        if(!single_dim){
            (*_pos_ptr) += index;
            tmp_pos = (*_pos_ptr);
            (*_pos_ptr) = 0;
        }else{
            tmp_pos = index;
        }
        return type_ptr[tmp_pos];
    }
    int weight;
    long* _pos_ptr;
    T* type_ptr = nullptr;
    bool single_dim = false;
};
#endif //STRING_MUL_ARRAY_HPP
