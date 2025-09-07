#include <iostream>
#include "Span.hpp"
#include <vector>
int main()
{
    {
        std::cout << "***/ Normal test /***" << std::endl;
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(6);
        sp.addNumber(150);
        sp.addNumber(1);
        sp.addNumber(-10);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "***/ test multiple add /***" << std::endl;
        Span sp = Span(5);
        std::vector<int> vec(5, 15);

        sp.addMulti(vec.begin(), vec.end());

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << std::endl;

    }

    {
        std::cout << "***/ testing overflow /***" << std::endl;
        Span sp = Span(3);
        sp.addNumber(2147483647);
        sp.addNumber(-2147483648);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << std::endl;

    }

    {
        std::cout << "***/ testing errors /***" << std::endl;
        Span sp = Span(3);
        try
        {
            sp.addNumber(5);
            sp.addNumber(5);
            sp.addNumber(5);
            sp.addNumber(5);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << std::endl;

    }
    {
        Span sp = Span(3);
        try
        {
            sp.addNumber(1);
            std::cout << sp.shortestSpan() << std::endl;
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        std::cout << std::endl;

    }
    return 0;
}