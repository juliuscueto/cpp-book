#include "all.h"

int plus(int x, int y)
{
    return x + y;
}

double plus(double x, double y)
{
    return x + y;
}

std::string plus(std::string x, std::string y){
    return x + y;
}

int main(int argc, char const *argv[])
{
    auto cat = "cat"s ;
    auto dog = "dog"s ;

    if ( cat < dog )
    {   // 猫は小さい
        std::cout << "cat is smaller.\n"s ;
    }
    else
    {   // 犬は小さい
        std::cout << "dog is smaller.\n"s ;
    }

    auto longcat = "longcat"s ;

    if ( longcat > cat )
    {   // longcatは長い
        std::cout << "Longcat is Looong.\n"s ;
    }
    else
    {
        std::cout << "Longcat isn't that long. Sigh.\n"s ;
    }
}