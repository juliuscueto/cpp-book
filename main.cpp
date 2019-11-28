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
    std::string x{};
    std::string y{};
    std::cin >> x >> y;
    std::cout << x << y;
}