#include "MutantStack.hpp"

/* default constructor */
template <typename T>
MutantStack<T>::MutantStack()
{
    std::cout << "MutantStack: Default constructor called" << std::endl;
}

/* copy constructor */
template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other): std::stack<T>(other)
{
    std::cout << "MutantStack: Copy constructor called" << std::endl;
}

/* copy assignment operator */
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    std::cout << "MutantStack: Copy assignment operator called" << std::endl;
    if (this != &other) {
       this->c = other.c; // c is the protected member in std::stack
    }
    return *this;
}

/* destructor */
template <typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "MutantStack: Destructor called" << std::endl;
}

/* member functions */
// iterator 
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}

// const_iterator
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return (this->c.end());
}

// reverse_iterator
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return (this->c.rend());
}

// const_reverse_iterator
template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
    return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    return (this->c.rend());
}
