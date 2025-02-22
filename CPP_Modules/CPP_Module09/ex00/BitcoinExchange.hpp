#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange
{
	public :
		class Date
		{
			public:
				int _year;
				int _month;
				int _day;
				Date();
				Date(const std::string s);
				~Date();
		};

		BitcoinExchange(std::string, std::map<BitcoinExchange::Date *, float>);
		~BitcoinExchange();
		void printRes();
		Date* _date;
		float _quant;
		float _val;
	private :
		void getClosestDate(std::map<BitcoinExchange::Date *, float> m);
};

#endif