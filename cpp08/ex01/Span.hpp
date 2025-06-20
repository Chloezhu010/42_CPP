#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>

class Span
{
    private:
        unsigned int _N;
    public:
        /* constructors */
        Span();
        Span(unsigned int N);               
        Span(const Span& other);
        
        /* operator overload */
        Span& operator=(const Span& other);
        
        /* destructor */
        ~Span();

        /* member functions */
        void addNumber(unsigned int input);

        /* getter */

        /* setter */
};

#endif
