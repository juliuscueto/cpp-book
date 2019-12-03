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

    typename Array::reference operator [] (std::size_t n) const
    {
        return *(*this + n);
    }

    bool operator < (array_iterator const & right) const
    {
        return i < right.i;
    }

    bool operator <= (array_iterator const & right) const
    {
        return i <= right.i;
    }

    bool operator > (array_iterator const & right) const
    {
        return i > right.i;
    }

    bool operator >= (array_iterator const & right) const
    {
        return i >= right.i;
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

    array_iterator operator +=(std::size_t n)
    {
        i += n;
        return *this;
    }

    array_iterator operator + (std::size_t n) const
    {
        auto copy = *this;
        copy += n;
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

    array_iterator operator -=(std::size_t n)
    {
        i -= n;
        return *this;
    }

    array_iterator operator - (std::size_t n) const
    {
        auto copy = *this;
        copy -= n;
        return copy;
    }
};

template<typename Array>
struct array_const_iterator
{
    Array & a;
    std::size_t i;

    array_const_iterator(typename array_iterator<Array>::iterator const & iter)
        : a(iter.a), i(iter.i){}

    array_const_iterator(Array const & a, std::size_t i)
        : a(a), i(i){}

    typename Array::const_reference operator*() const
    {
        return a[i];
    }

    typename Array::const_reference operator [] (std::size_t n) const
    {
        return *(*this + n);
    }

    bool operator < (array_const_iterator const & right) const
    {
        return i < right.i;
    }

    bool operator <= (array_const_iterator const & right) const
    {
        return i <= right.i;
    }

    bool operator > (array_const_iterator const & right) const
    {
        return i > right.i;
    }

    bool operator >= (array_const_iterator const & right) const
    {
        return i >= right.i;
    }

    array_const_iterator & operator ++()
    {
        ++i;
        return *this;
    }

    array_const_iterator operator ++(int)
    {
        array_const_iterator copy = *this;
        ++*this;
        return copy;
    }

    array_const_iterator operator +=(std::size_t n)
    {
        i += n;
        return *this;
    }

    array_const_iterator operator + (std::size_t n) const
    {
        auto copy = *this;
        copy += n;
        return copy;
    }

    array_const_iterator & operator --()
    {
        --i;
        return *this;
    }

    array_const_iterator operator --(int)
    {
        array_const_iterator copy = *this;
        ++*this;
        return copy;
    }

    array_const_iterator operator -=(std::size_t n)
    {
        i -= n;
        return *this;
    }

    array_const_iterator operator - (std::size_t n) const
    {
        auto copy = *this;
        copy -= n;
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
    using const_iterator = array_const_iterator<array>;

    value_type storage[N];

    reference operator[](size_type i)
    {
        return storage[i];
    }

    const_reference operator[](size_type i) const
    {
        return storage[i];
    }

    reference at(std::size_t n)
    {
        if ( n >= size()) throw std::out_of_range("Error: Out of Range");
        return storage[n];
    }

    const_reference at(std::size_t n) const
    {
        if ( n >= size()) throw std::out_of_range("Error: Out of Range");
        return storage[n];
    }

    size_type size() const
    {
        return sizeof(storage)/sizeof(value_type);
    }

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

    const_iterator begin() const {
        return const_iterator(*this, 0);
    }
    const_iterator end() const
    {
        return const_iterator(*this, N);
    }
    const_iterator cbegin() const {
        return const_iterator(*this, 0);
    }
    const_iterator cend() const
    {
        return const_iterator(*this, N);
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
    std::add_pointer_t<int> a = nullptr;
    std::add_pointer_t<int *> b = nullptr;
    std::add_pointer_t<int(int)> c = nullptr;

}