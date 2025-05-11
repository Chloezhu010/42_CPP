/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:52:42 by chloe             #+#    #+#             */
/*   Updated: 2025/05/11 21:57:29 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

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