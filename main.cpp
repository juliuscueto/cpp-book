#include "all.h"

template <typename T, std::size_t N>
struct array
{
    using value_type = T;
    using reference = T &;
    using const_reference = T const &;

    using size_type = std::size_t;

    value_type storage[N];

    reference operator[](size_type i)
    {
        return storage[i];
    }

    const_reference operator[](size_type i) const
    {
        return storage[i];
    }

    size_type size() const
    {
        return sizeof(storage)/sizeof(value_type);
    };

    reference front(){return storage[0];}
    const_reference front() const{return storage[0];}
    reference back(){return storage[N-1];}
    const_reference back() const{return storage[N-1];}
};

template<typename Array>
void print(Array const & c)
{
    for (std::size_t i = 0; i < c.size(); ++i)
    {
        std::cout << c[i];
    }
    
}

int main(int argc, char const *argv[])
{
    std::array
    array<int, 5> hoge = {1,2,3,4,5};
    std::cout << hoge.size() << std::endl;
    print(hoge);
    std::cout << hoge.front() << hoge.back() << std::endl;
}