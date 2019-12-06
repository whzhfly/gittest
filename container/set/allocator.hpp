#ifndef __ALLOCATOR__
#define __ALLOCATOR__
#include <iostream>
using namespace std;

namespace Joe
{
template<typename T>
class allocator
{
public:
    using size_type  = size_t;
    using value_type = T;
    using pointer    = value_type*;
    using reference  = value_type&;

    using const_reference  = const value_type&;
    using const_pointer    = const value_type*;
    using const_value_type = const value_type;
public:
    allocator() = default;
    inline pointer apply_memory(size_type size=1)const;
    inline void recycle_memroy(pointer _ptr)const;

    inline void deconstruct_object(pointer _ptr)const;
    inline void construct_object(pointer& _ptr)const;
    inline void construct_object(pointer& _ptr, const_value_type& val)const;
    ~allocator() = default;
};


template<typename T>
inline typename allocator<T>::pointer Joe::allocator<T>::apply_memory(size_type size)const
{
    pointer _adr = nullptr;
    try
    {
        _adr = (pointer)( ::operator new(sizeof(T)*size) );
    }
    catch(std::bad_alloc & e )
    {
        std::cout << e.what() << std::endl;
    }
    return _adr;
}

template<typename T>
inline void Joe::allocator<T>::recycle_memroy(pointer _ptr)const
{
    operator delete[] (_ptr);
}

template<typename T>
inline void Joe::allocator<T>::construct_object(pointer& _ptr)const
{
    new(_ptr) T();
}

template<typename T>
inline void Joe::allocator<T>::construct_object(pointer& _ptr, const_value_type& val)const
{
    new(_ptr) T(val);
}

template<typename T>
inline void Joe::allocator<T>::deconstruct_object(pointer _ptr)const
{
    _ptr->~T();
}
}

#endif //__ALLOCATOR__






