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

template<typename T>
void print_size()
{
    std::cout << sizeof(T) << std::endl;
}

void * memcpy(void * dest, void const * src, std::size_t n)
{
    auto d = static_cast<std::byte *>(dest);
    auto s = static_cast<std::byte const *>(src);

    for (std::size_t i = 0; i < n; i++)
    {    
        d[i] = s[i];
    }
    return dest;
}

template<typename To, typename From>
To bit_cast(From const & from)
{
    To to;
    memcpy(&to, &from, sizeof(To));
    return to;
}

template<typename T>
struct iota_iterator
{
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using reference = T &;
    using pointer = T *;
    using iterator_category = std::bidirectional_iterator_tag;

    T value;

    iota_iterator(T value = 0)
        : value(value) {}

    iota_iterator & operator +=(difference_type n)
    {
        value += n;
        return *this;
    }
    iota_iterator operator +(difference_type n) const
    {
        auto temp = *this;
        temp += n;
        return *temp;
    }
    iota_iterator operator -=(difference_type n)
    {
        value -= n;
        return *this;
    }
    iota_iterator operator -(difference_type n) const
    {
        auto temp = *this;
        temp -= n;
        return *temp;
    }
    reference operator *() noexcept {return value;}
    const reference operator *() const noexcept {return value;}

    iota_iterator & operator ++() noexcept
    {
        ++value;
        return *this;
    }
    iota_iterator operator ++(int) noexcept
    {
        auto temp = *this;
        ++*this;
        return temp;
    }

    iota_iterator & operator --() const noexcept
    {
        --value;
        return *this;
    }

    iota_iterator operator --(int) const noexcept
    {
        auto temp = *this;
        --*this;
        return temp;
    }

    bool operator == (iota_iterator const & i) const noexcept
    {
        return value == i.value;
    }
    bool operator != (iota_iterator const & i) const noexcept
    {
        return !(*this == i);
    }

    difference_type operator - (iota_iterator const & i)
    {
        return value - i.value;
    }
    bool operator < (iota_iterator const & i) const noexcept
    {return value < i.value;}
    bool operator > (iota_iterator const & i) const noexcept
    {return value > i.value;}
    bool operator <= (iota_iterator const & i) const noexcept
    {return value <= i.value;}
    bool operator >= (iota_iterator const & i) const noexcept
    {return value >= i.value;}
};

template<typename T>
iota_iterator<T> operator +(
    typename iota_iterator<T>::difference_type n,
    iota_iterator<T> const & i
)
{return i + n;}

template<typename T>
iota_iterator<T> operator -(
    typename iota_iterator<T>::difference_type n,
    iota_iterator<T> const & i
)
{return i - n;}

struct Logger
{
    std::string name;
    Logger(std::string name)
        : name(name)
    {std::cout << name << " was constructed"s << std::endl;}
    ~Logger()
    {std::cout << name << " was destructed"s << std::endl;}
};


int main(int argc, char const *argv[])
{
    int * int_array_ptr = new int[5]{1,2,3,4,5};
}