#include "easyfind.hpp"

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vContainer(4, 40);
    vContainer[3] = 5;
    try
    {
        easyfind(vContainer, 8);
        std::cout << "value is found \n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        easyfind(vContainer, 5);
        std::cout << "value is found \n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}