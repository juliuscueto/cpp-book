#include "all.h"

template<typename Array>
struct array_iterator
{
    Array & a;
    std::size_t i;

    array_iterator(Array & a, std::size_t i)
        : a(a), i(i){}

    typename Array::reference operator*()
    {
        return a[i];
    }

    array_iterator & operator ++()
    {
        ++i;
        return *this;
    }

    array_iterator operator ++(int)
    {
        array_iterator copy = *this;
        ++*this;
        return copy;
    }

    array_iterator & operator --()
    {
        --i;
        return *this;
    }

    array_iterator operator --(int)
    {
        array_iterator copy = *this;
        ++*this;
        return copy;
    }
};

template <typename T, std::size_t N>
struct array
{
    using value_type = T;
    using reference = T &;
    using const_reference = T const &;

    using size_type = std::size_t;
    using iterator = array_iterator<array>;

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

    iterator begin()
    {
        return iterator(*this, 0);
    }
    iterator end()
    {
        return iterator(*this, N);
    }
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
    array<int, 5> a = {1,2,3,4,5};
    auto iter = a.begin();
    std::cout << *iter << std::endl;
    ++iter;
    std::cout << *iter << std::endl;
    ++iter;
    std::cout << *iter << std::endl;
    auto last = a.end();
    std::cout << *last << std::endl;
}