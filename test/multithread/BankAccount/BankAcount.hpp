#ifndef BANKACOUNT_HPP
#define BANKACOUNT_HPP

#include <iostream>
#include <thread>
#include <memory>

class BankAcount
{
    private:
        size_t  _balance;
        std::mutex mtx;
    public:
        /* constructors */
        BankAcount();
        BankAcount(size_t n);              
        BankAcount(const BankAcount& other);
        
        /* operator overload */
        BankAcount& operator=(const BankAcount& other);
        
        /* destructor */
        ~BankAcount();

        /* member functions */
        void withdraw(size_t value);
        
        /* getter */
        size_t getBalance();
        /* setter */
};

#endif
