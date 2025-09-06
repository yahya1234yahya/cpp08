#include "Span.hpp"
#include <limits>


Span::Span()
{
    size_value = 0;
}
Span::Span(unsigned int n) : size_value(n)
{

}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this == &other)
    {
        this->size_value = other.size_value;
        this->container = other.container;
    }
    return (*this);
}

void Span::addNumber(int nb)
{
    if (container.size() + 1 > size_value)
    {
        throw std::runtime_error("sizze out of bound");
    }
    container.insert(container.end(), nb);
}

unsigned long Span::shortestSpan() const
{
    if (container.size() < 2)
        throw std::runtime_error("not enough number");

    
    std::vector<int>sorted = container;
    std::sort(sorted.begin(), sorted.end());
    unsigned long minspan = std::numeric_limits<unsigned long>::max();


    for (size_t i = 1; i < sorted.size(); i++)
    {
        unsigned long difrence = static_cast<unsigned long>(sorted[i]) - sorted[i - 1];
        if (difrence < minspan)
            minspan = difrence;
    }

    return minspan;
}

unsigned long Span::longestSpan() const
{
    if (container.size() < 2)
        throw std::runtime_error("not enough number");
    int min = *std::min_element(container.begin(), container.end());
    int max = *std::max_element(container.begin(), container.end());

    return (static_cast<unsigned long>(max) - min)

}

unsigned int Span::size() const
{
    return size_value;
}

int Span::getValue(unsigned int i) const
{
    if (i >= container.size())
    {
        throw std::runtime_error("the input is out of bound");
    }
    return (container[i]);
}


