#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bscalar)
{
	return ;
}

BitcoinExchange::~BitcoinExchange()
{
	return ;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& scalar)
{
	return (*this);
}

void	BitcoinExchange::loadInput(std::map<std::string, float> input)
{
	_inputmap = input;
}
