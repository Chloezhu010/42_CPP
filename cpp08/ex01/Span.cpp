#include "Span.hpp"

/* default constructor */
Span::Span()
{
    std::cout << "Span: Default constructor called" << std::endl;
}

/* constructor */
Span::Span(unsigned int n): _N(n)
{
    std::cout << "Span: Constructor called" << std::endl;
}

/* copy constructor */
Span::Span(const Span& other)
{
    std::cout << "Span: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
Span& Span::operator=(const Span& other)
{
    std::cout << "Span: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_N = other._N;
        this->_nums = other._nums;
    }
    return *this;
}

/* destructor */
Span::~Span()
{
    std::cout << "Span: Destructor called" << std::endl;
}

/* member functions */
void Span::addNumber(int input)
{
    if (_nums.size() + 1 <= _N)
        _nums.push_back(input);
    else
        throw ExceedMaxSize();
}

int  Span::shortestSpan()
{
    if (_nums.size() <= 1)
        throw NotEnoughNum();
    else
    {
        // copy to a temp vetor
        std::vector<int> temp = _nums;
        // sort the temp vector
        std::sort(temp.begin(), temp.end());
        // compare the adjacent numbers and find the shortest span
        int min = temp[1] - temp[0];
        for (unsigned int i = 1; i < (temp.size() - 2); i++)
        {
            if (min >= temp[i + 1] - temp[i])
                min = temp[i + 1] - temp[i];
        }
        return (min);
    }
}

int  Span::longestSpan()
{
    if (_nums.size() <= 1)
        throw NotEnoughNum();
    else
    {
        std::vector<int>::iterator max = std::max_element(_nums.begin(), _nums.end());
        std::vector<int>::iterator min = std::min_element(_nums.begin(), _nums.end());
        return (*max - *min);
    }
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    int addSize = std::distance(begin, end);
    if (_nums.size() + addSize <= _N)
        _nums.insert(_nums.end(), begin, end);
    else
        throw ExceedMaxSize();
}
