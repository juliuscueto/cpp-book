#include "all.h"

template < typename T, typename Allocator = std::allocator<T> >
class vector
{
    public:
        using value_type = T;
        using pointer = T*;
        using const_pointer = const pointer;
        using reference = value_type &;
        using const_reference = const reference;
        using allocator_type = Allocator;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using iterator = pointer;
        using const_iterator = const_pointer;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;
    private:
        pointer first;
        pointer last;
        pointer reserved_last;
        allocator_type alloc;
        using traits = std::allocator_traits<allocator_type>;
        pointer allocate(size_type)
        template < typename Allocator >
        void f(Allocator & alloc)
        {
            traits::allocate(alloc, 1);
        }
    public:
        vector( const allocator_type & alloc ) noexcept
            : alloc(alloc)
        {}
        vector()
            : vector( allocator_type() )
        {}
        vector(size_type size, const allocator_type & alloc = allocator_type())
            : vector(alloc)
        {
            resize(size)
        }
        vector(size_type size, const_reference value, const allocator_type & alloc = allocator_type())
            : vector(alloc)
        {
            resize(size, value)
        }
        ~vector();
        iterator begin() noexcept
        { return first ; }
        iterator end() noexcept
        { return last ; }
        iterator begin() const noexcept
        { return first ; }
        iterator end() const noexcept
        { return last ; }
        iterator cbegin() const noexcept
        { return first ; }
        iterator cend() const noexcept
        { return last ; }
        iterator rbegin() noexcept
        { return reverse_iterator { last } ; }
        iterator rend() noexcept
        { return reverse_iterator { first } ; }
        iterator rbegin() const noexcept
        { return reverse_iterator { last } ; }
        iterator rend() const noexcept
        { return reverse_iterator { first } ; }
        iterator crbegin() const noexcept
        { return reverse_iterator { last } ; }
        iterator crend() const noexcept
        { return reverse_iterator { first } ; }

        size_type size() const noexcept
        {
            return end() - begin();
        }
        bool empty() const noexcept
        {
            return size() == 0;
        }
        size_type capacity() const noexcept
        {
            return reserved_last - first;
        }
        reference operator [](size_type i)
        { return first[i];}
        const_reference operator[](size_type i)
        { return first[i];}
        reference at(size_type i)
        {
            if ( i >= size() )
            {
                throw std::out_of_range("Index is out of range");
            }
            return first[i];
        }
        const_reference at(size_type i) const
        {
            if ( i >= size() )
            {
                throw std::out_of_range("Index is out of range");
            }
            return first[i];
        }
        reference front()
        { return first; }
        const_reference front() const
        { return first; }
        reference back()
        { return last - 1; }
        const_reference back() const
        { return last - 1; }
        pointer data() noexcept
        { return first; }
        const_pointer data() const noexcept
        { return first; }
        
        vector & operator =( const vector & x );

        void push_back( const T & x );
        T & operator []( std::size_t i ) noexcept;
};

int main(int argc, char const *argv[])
{
    vector<int> v(100);
    for (auto i = 0; i != 100; ++i)
    {
        v[i] = i;
    }
}
