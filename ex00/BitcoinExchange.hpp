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
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& copy);
		void	loadInput(std::map<Date, float> input);
};
