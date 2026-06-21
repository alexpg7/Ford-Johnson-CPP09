#include "BitcoinExchange.hpp"
#include <iomanip>

BitcoinExchange::BitcoinExchange()
{
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
	return ;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this == &copy)
		return (*this);
	return (*this);
}

void	BitcoinExchange::loadData(std::map<Date, float> data)
{
	_data = data;
}
void BitcoinExchange::printData()
{
	std::ios oldState(nullptr);
	oldState.copyfmt(std::cout);

	std::cout << std::fixed << std::setprecision(2);

	for (std::map<Date, float>::const_iterator it = _data.begin();
		it != _data.end();
		++it)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}

	std::cout.copyfmt(oldState);
}

std::map<Date, float>&	BitcoinExchange::getData()
{
	return _data;
}