//
// Created by dy2018 on 18-7-24.
//

#ifndef STRING_MUL_ArrayAY_HPP
#define STRING_MUL_ArrayAY_HPP
namespace xmh
{
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

    template<typename T,int...Args>
    struct Array
    {
        Array(long* pos_ptr,T* Array_ptr)
        {

        }
    };
    template<typename T,int U,int...Args>
    struct Array<T,U,Args...>:Array<T,Args...>
    {
        Array(long* pos_ptr = new long(),T* Array_ptr = new T[cal_multi<U,Args...>::value]):Array<T,Args...>(pos_ptr,Array_ptr),weight(cal_multi<Args...>::value),_total_size(cal_multi<U,Args...>::value),_pos_ptr(pos_ptr),type_ptr(Array_ptr)
        {
        }
        Array<T,Args...>& operator[](int index)
        {
            (*_pos_ptr) += (index * weight);
            return static_cast<Array<T,Args...>&>(*this);
        }
        int weight;
        int _total_size;
        T* type_ptr = nullptr;
        long* _pos_ptr;
    };
    template<typename T,int U>
    struct Array<T,U>
    {
        Array(long* pos_ptr = nullptr,T* Array_ptr= nullptr):weight(1),_pos_ptr(pos_ptr),type_ptr(Array_ptr)
        {
            if(_pos_ptr== nullptr){
                single_dim = true;
            }
            if(Array_ptr== nullptr){
                type_ptr = new T[U];
            }
        }
        ~Array()
        {
            delete []type_ptr;
            delete _pos_ptr;
        }
        T& operator[](int index)
        {
            int tmp_pos = 0;
            if(!single_dim){
                tmp_pos = (*_pos_ptr) + index;
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
}
#endif //STRING_MUL_ArrayAY_HPP
