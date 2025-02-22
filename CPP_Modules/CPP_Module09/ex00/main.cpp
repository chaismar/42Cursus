#include "BitcoinExchange.hpp"

#include <iterator>
#include <utility>
#include <functional>
#include <cctype>
#include <ios>
#include <iostream>
#include <sstream>


#define ER_OP_FILE "ERROR : data.csv : can't read file/file doesn't exist"
#define ER_ARGS "ERROR : number of args is wrong"
#define ER_CSV_CORRUPT "ERROR: data.csv : data corrupted"
#define ER_INPUTFILE "ERROR : "<< av[1] << " : can't read file/file doesn't exist"
#define ER_VAL_POS	"ERROR : not a positive number."
#define ER_VAL_HIGH "ERROR : too large a number."
#define ER_VAL_FLOAT "ERROR : value is no float."
#define ER_FORM "ERROR : format should be YYYY-MM-DD | floating_val"
#define ER_DATE "ERROR : bad input => " << s

void clear_map(std::map<BitcoinExchange::Date*, float> m)
{
	std::map<BitcoinExchange::Date*, float>::iterator it = m.begin();
	while(it != m.end())
	{
		delete (it->first);
		it++;
	}
}

float getFloat(std::string s)
{
	std::istringstream iss(s);
	float f;
	iss >> f;
	return (f);
}

std::map<BitcoinExchange::Date *, float> fill_csv(std::ifstream &csv)
{
	std::map <BitcoinExchange::Date*, float> m ;
	std::string s;

	std::getline(csv, s);
	int i = 0;
	while (csv.peek() != EOF)
	{
		getline(csv, s);
		m.insert(std::pair <BitcoinExchange::Date*, float> (new BitcoinExchange::Date(s), getFloat(s.substr(11))));
		i++;
	}
	return m;
}

int ft_stoi(const std::string & s ) {
    int i;
    std::istringstream(s) >> i;
    return i;
}

int get_max_month_day(int month, int year)
{
	int days[] = {0, 31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && year % 4 == 0)
		return 29;
	return (days[month]);
}

int check_date_min(int yyyy, int mm, int dd)
{
	if (yyyy == 2009 && mm == 01 && dd < 02)
		return (1);
	return (0);
}
int check_date_max(int yyyy, int mm, int dd)
{
	time_t timer;
	char buffer[20];
	struct tm * timeinfo;
	std::string s;

	time(&timer);
	timeinfo = localtime(&timer);
	strftime(buffer, 20, "%F", timeinfo);
	s = buffer;
	if (yyyy > ft_stoi(s.substr(0,4)))
		return (1);
	if ((yyyy == ft_stoi(s.substr(0,4)) && mm > ft_stoi(s.substr(5,2))))
		return (1);
	if ((yyyy == ft_stoi(s.substr(0,4)) && (mm == ft_stoi(s.substr(5,2))) && dd > ft_stoi(s.substr(8,2))))
		return (1);
	return (0);
}

int	check_date(int yyyy, int mm, int dd)
{
	if (yyyy < 2009 || yyyy > 2024)
		return (1);
	if (mm <= 0 || mm > 2024)
		return (1);
	if (dd <= 0 || dd > get_max_month_day(mm, yyyy))
		return (1);
	if (check_date_min(yyyy, mm, dd) || check_date_max(yyyy, mm, dd))
		return (1);
	return (0);
}

int csvIsFloat(std::string s)
{
	std::istringstream iss(s);
	float f;
	iss >> f;
	if (iss.fail())
		return (1);
	if (f < 0)
		return (1);
	return (0);
}

int inputIsFloat(std::string s)
{
	std::istringstream iss(s);
	float f;
	iss >> f;
	if (iss.fail())
	{
		std::cerr << ER_VAL_FLOAT << std::endl;
		return (1);
	}
	if (f < 0)
	{
		std::cerr << ER_VAL_POS << std::endl;
		return (1);
	}
	if (f > 100)
	{
		std::cerr << ER_VAL_HIGH << std::endl;
		return (1);
	}
	return (0);
}

int csv_is_correct(std::string s)
{
	if (check_date(ft_stoi(s.substr(0,4)), ft_stoi(s.substr(5,2)), ft_stoi(s.substr(8,2))))
		return (1); 
	if (s.substr(4,1) != "-" || s.substr(7,1) != "-" || s.substr(10,1) != ",")
		return (1); 
	if (csvIsFloat(s.substr(11)))
		return (1);
	return (0);
}

int check_csv(std::ifstream &csv)
{
	std::string s;

	std::getline(csv, s);
	while (csv.peek() != EOF)
	{
		getline(csv, s);
		if (csv_is_correct(s))
			return (1);
	}
	return (0);
}

int input_is_correct(std::string s)
{	
	if (check_date(ft_stoi(s.substr(0,4)), ft_stoi(s.substr(5,2)), ft_stoi(s.substr(8,2))))
	{
		std::cerr << ER_DATE << std::endl;
		return (1);
	}
	if (s.substr(4,1) != "-" || s.substr(7,1) != "-" || s.substr(11,1) != "|")
	{
		std::cerr << ER_FORM << std::endl;
		return (1);
	}
	if (inputIsFloat(s.substr(12)))
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << ER_ARGS << std::endl;
		return (1);
	}
	std::ifstream csv ("data.csv");
	if (!csv.is_open())
		std::cerr << ER_OP_FILE << std::endl;
	if (check_csv(csv) == 1)
	{
		std::cerr << ER_CSV_CORRUPT << std::endl;
		return (1);
	}
	csv.close();
	std::ifstream csv2 ("data.csv");
	std::map<BitcoinExchange::Date *, float> m = fill_csv(csv2);
	std::ifstream input(av[1]);
	if (!input.is_open())
		std::cerr << ER_INPUTFILE << std::endl;
	std::string s;
	std::getline(input, s);
	while (input.peek() != EOF)
	{
		std::getline(input, s);
		if (input_is_correct(s) == 0)
		{
			BitcoinExchange btc(s, m);
			btc.printRes();
		}
	}
	clear_map(m);
}