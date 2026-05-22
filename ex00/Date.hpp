#pragma once

class Date
{
	private:
		unsigned int	_year;
		unsigned int	_month;
		unsigned int	_day;
	public:
		Date(unsigned int year, unsigned int month, unsigned int day);
		Date();
		Date&	operator=(const Date& date);
		~Date();
};
