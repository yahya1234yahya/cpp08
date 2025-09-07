#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>

class Span
{
    private:
        std::vector<int> container;
        unsigned int size_value;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span &operator=(const Span& other);
        
        void addNumber(int nb);
        unsigned long shortestSpan()  const;
        unsigned long longestSpan() const ;
        unsigned int size()const ;
        int getValue(unsigned int i) const;

        template <typename it>
        void addMulti(it start, it end)
        {
            int count = std::distance(start , end);
            if (count < 0)
            {
                throw std::runtime_error("error");
            }
            if (static_cast<unsigned int>(count) <= size_value - container.size())
            {
                container.insert(container.begin(),start, end);
            }
            else
            {
                int remain = size_value - container.size();
                if (remain == 0)
                {
                    throw std::runtime_error("range is full");
                }
                container.insert(container.begin(),start,  start + remain);
                throw std::runtime_error("cannot add it fully");
            }
        }
};


#endif