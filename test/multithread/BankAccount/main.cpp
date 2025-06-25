#include "BankAcount.hpp"

int main()
{
    BankAcount myAccount(100);
    
    std::thread t1(&BankAcount::withdraw, &myAccount, 60);
    t1.join();
    std::cout << "Balance: " << myAccount.getBalance() << std::endl;

    std::thread t2(&BankAcount::withdraw, &myAccount, 50);
    t2.join();
    std::cout << "Balance: " << myAccount.getBalance() << std::endl;

    return 0;
}