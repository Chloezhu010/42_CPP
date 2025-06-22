#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

class Span
{
    private:
        unsigned int _N; // max size to store numbers
        std::vector<int> _nums; // container to hold ints
    public:
        /* constructors */
        Span();
        Span(unsigned int n);               
        Span(const Span& other);
        
        /* operator overload */
        Span& operator=(const Span& other);
        
        /* destructor */
        ~Span();

        /* member functions */
        void addNumber(int input);
        int  shortestSpan();
        int  longestSpan();
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        
        class ExceedMaxSize : public std::exception {
            public:
                const char* what() const throw() {
                    return "Error: Exceed max size\n";
                }
        };

        class NotEnoughNum : public std::exception {
            public:
                const char* what() const throw() {
                    return "Error: Not enough number\n";
                }
        };
};

#endif
