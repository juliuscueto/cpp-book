#include "all.h"

auto output_all = [](auto first, auto last, auto output_iter){
    for (auto iter = first; iter != last; iter++, output_iter++)
    {
        *output_iter = *iter;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> v = {1, 2, 3, 4, 5,};
    std::vector<int> destination{};
    output_all(
        std::begin(v),
        std::end(v),
        std::begin(destination)
    );  
}
