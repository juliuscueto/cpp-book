#include "all.h"

template<typename T>
struct smart_ptr
{
    T * ptr;
    smart_ptr() : ptr(new T{}) {}
    ~smart_ptr(){ delete ptr ;}

    T & operator *() const noexcept{return *ptr;}
};

int main(int argc, char const *argv[])
{
    smart_ptr<int> ptr;
    *ptr = 123;
}
