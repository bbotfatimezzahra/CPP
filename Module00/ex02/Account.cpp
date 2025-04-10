#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalAmount = 0;

void	_displayTimestamp( void )
{
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

void	Account::displayAccountsInfos(void)
{
	std::cout << "accounts:";
	std::cout << Account::getNbAccounts();
	std::cout << ";total:";
	std::cout << Account::getTotalAmount();
	std::cout << ";deposits:";
	std::cout << Account::getNbDeposits();
	std::cout << ";withdrawals:";
	std::cout << Account::getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::displayStatus(void) const
{
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";	
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";	
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << ++this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withd)
{
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";	
	std::cout << "withdrawal:";
	if (this->_amount < withd)
	{
		std::cout << "refused" << std::endl;
		return (0);
	}
	std::cout << withd << ";";
	this->_amount -= withd;
	Account::_totalAmount -= withd;
	Account::_totalNbWithdrawals++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
	return (1);
}

Account::~Account(void)
{
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}
