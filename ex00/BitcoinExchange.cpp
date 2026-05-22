#include "BitcoinExchange.hpp"

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

void	BitcoinExchange::loadInput(std::map<Date, float> input)
{
	_inputmap = input;
}
