#pragma once
#include <iostream>
#include <map>
#include "Date.hpp"

class	BitcoinExchange
{
	private:
		std::map<Date, float>	_inputmap;
		std::map<Date, float>	_data;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &bscalar);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& scalar);
		void	loadInput(Date, float> input);
};
