#include "BankAcount.hpp"

/* default constructor */
BankAcount::BankAcount()
{
    std::cout << "BankAcount: Default constructor called" << std::endl;
}

BankAcount::BankAcount(size_t n): _balance(n)
{
    std::cout << "BankAcount: Constructor called" << std::endl;
}

/* copy constructor */
BankAcount::BankAcount(const BankAcount& other)
{
    std::cout << "BankAcount: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
BankAcount& BankAcount::operator=(const BankAcount& other)
{
    std::cout << "BankAcount: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_balance = other._balance;
    }
    return *this;
}

/* destructor */
BankAcount::~BankAcount()
{
    std::cout << "BankAcount: Destructor called" << std::endl;
}

/* member functions */
void BankAcount::withdraw(size_t withdraw_amount)
{
    std::lock_guard<std::mutex> lock(mtx); // auto lock, unlock mtx
    if (_balance >= withdraw_amount)
    {
        std::cout << "Withdraw successfully\n";
        _balance -= withdraw_amount;
    }
    else
        std::cout << "Withdraw failed\n";
}

/* getter */
size_t BankAcount::getBalance()
{
    std::lock_guard<std::mutex> lock(mtx);
    return (_balance);
}

/* setter */  

