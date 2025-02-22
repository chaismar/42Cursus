#include "BitcoinExchange.hpp"

#include <time.h>

void	BitcoinExchange::getClosestDate(std::map<BitcoinExchange::Date *, float> m)
{
	struct tm tm1;
	struct tm tm2;
	std::map<BitcoinExchange::Date*, float>::iterator it = m.begin();
	double resdif = 1;

	m.size();
	time_t rawtime;
	time(&rawtime);
	tm1 = *localtime(&rawtime);
	tm2 = *localtime(&rawtime);
	tm1.tm_year = _date->_year;
	tm1.tm_mon = _date->_month;
	tm1.tm_mday = _date->_day;

	while (it != m.end() && resdif > 0)
	{
		tm2.tm_year = it->first->_year;
		tm2.tm_mon = it->first->_month;
		tm2.tm_mday = it->first->_day;
		resdif = difftime(mktime(&tm1), mktime(&tm2));
		if (resdif == 0)
		{
			_val = it->second;
			return ;
		}
		it++;
	}
	it--;
	it--;
	_val = it->second;
}

BitcoinExchange::BitcoinExchange(std::string s, std::map<BitcoinExchange::Date *, float> m)
{
	std::istringstream iss(s.substr(12));

	_date = new Date(s);
	iss >> _quant;
	getClosestDate(m);
}

BitcoinExchange::~BitcoinExchange()
{
	delete(_date);
}

void BitcoinExchange::printRes()
{
	//2011-01-03 => 3 = 0.9
	std::cout << _date->_year << "-" << _date->_month << "-" << _date->_day << " => " << _quant << " = ";
	std::cout << _quant * _val << std::endl;
}
//--------------------------------------------------------------------------------------------------
int ft_btcstoi(const std::string & s ) {
    int i;
    std::istringstream(s) >> i;
    return i;
}



BitcoinExchange::Date::Date()
{
	_year = 2012;
	_month = 12;
	_day = 12;
}

BitcoinExchange::Date::Date(const std::string s)
{
	_year = ft_btcstoi(s.substr(0,4));
	_month = ft_btcstoi(s.substr(5,2));
	_day = ft_btcstoi(s.substr(8,2));


	//parcours la date et rempli year month day (verifie qu'il n'y a pas d'erreur)
}

BitcoinExchange::Date::~Date()
{

}