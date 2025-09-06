#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span
{
    private:
        std::vector<long long> container;
        unsigned int size_value;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span &operator=(const Span& other);

        unsigned long long shortestSpan()  const;
        unsigned long long longestSpan() const ;
        unsigned int size()const ;
        long long getValue(unsigned int i) const;
};





#endif