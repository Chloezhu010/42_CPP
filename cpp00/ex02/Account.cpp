/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:52:42 by chloe             #+#    #+#             */
/*   Updated: 2025/05/12 10:54:07 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

/* init static var */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* static methods */
int Account::getNbAccounts()
{
    return (_nbAccounts);
}

int Account::getTotalAmount()
{
    return (_totalAmount);
}

int Account::getNbDeposits()
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
            << ";total:" << _totalAmount
            << ";deposits:" << _totalNbDeposits
            << ";withdrawals:" << _totalNbWithdrawals
            << std::endl;
}

void Account::_displayTimestamp()
{
    std::cout << "[19920104_091532] ";   
}

/* constructor & destructor */
Account::Account(int initial_deposit)
{
    /* init value */
    this->_accountIndex = this->_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += initial_deposit;
    /* printout info */
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
            << ";account:" << this->_amount
            << ";created" << std::endl;
}

Account::~Account()
{
    /* printout info */
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
            << ";amount:" << this->_amount
            << ";closed" << std::endl;
}

/* instance methods */
void    Account::makeDeposit(int deposit)
{
    int p_amount = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    /* printout */
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
            << ";p_amount:" << p_amount
            << ";deposit:" << deposit
            << ";amount:" << this->_amount
            << ";nb_deposits:" << this->_nbDeposits
            << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    /* init check 
        - withdrawal amount needs to be < _amount
    */
    if (withdrawal > this->_amount)
    {
        _displayTimestamp();
        std::cout << "index:" << this->_accountIndex
            << ";p_amount:" << this->_amount
            << ";withdrawal:refused"
            << std::endl;
        return (false);
    }
    
    int p_amount = this->_amount;
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    /* printout */
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
            << ";p_amount:" << p_amount
            << ";withdrawal:" << withdrawal
            << ";amount:" << this->_amount
            << ";nb_withdrawals:" << this->_nbWithdrawals
            << std::endl;
    return (true);
}

int     Account::checkAmount(void) const
{
    return (this->_amount);
}

void    Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
            << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals
            << std::endl;
}