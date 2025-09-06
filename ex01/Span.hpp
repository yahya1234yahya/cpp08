#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

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
            
        }
};

// todo 
// add the addMulti template
// add main()



#endif