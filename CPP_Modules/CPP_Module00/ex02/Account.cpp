#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <sstream> 
#include <string>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _accountIndex = 0;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _amount = initial_deposit;
    _accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}

int	Account::getNbAccounts(void){
    return (_nbAccounts);
}

int	Account::getTotalAmount(void){
    return (_totalAmount);
}

int	Account::getNbDeposits(void){
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
    return (_totalNbWithdrawals);
}

int	Account::checkAmount(void) const{
    return (this->_amount);
}

std::string get_format(int i)
{
    std::string ret;
    std::stringstream stream;

    if (i < 10)
    {
        stream << i;
        stream >> ret;
        ret.insert(0,"0");
    }
    else
    {
        stream << i;
        stream >> ret;
    }
    stream.clear();
    return ret;
}

void Account::_displayTimestamp(void){
    time_t timestamp = time(NULL);
    struct tm *timeInfos = localtime( &timestamp );
    std::cout << '[' << timeInfos->tm_year + 1900 << get_format(timeInfos->tm_mon + 1) << get_format(timeInfos->tm_mday) << "_"
    << get_format(timeInfos->tm_hour) << get_format(timeInfos->tm_min) << get_format(timeInfos->tm_sec) << "] ";
}

void	Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << _amount + deposit << ";";
    std::cout << "nb_deposits:" << ++_nbDeposits << std::endl;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";

    if (_amount - withdrawal > 0)
    {
        std::cout << "withdrawal:" << withdrawal << ";";
        std::cout << "amount:" << _amount - withdrawal << ";";
        std::cout << "nb_withdrawals:" << ++_nbWithdrawals << std::endl;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        return (true);
    }
    else
    {
        std::cout << "withdrawal:" << "refused" << std::endl;
        return (false);
    }
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}