#pragma once
#include <iostream>

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
		unsigned int	getDay() const;
		unsigned int	getYear() const;
		unsigned int	getMonth() const;
		bool	operator>(const Date& date) const;
		bool	operator<(const Date& date) const;
		bool	operator==(const Date& date) const;
		~Date();
};

std::ostream&	operator<<(std::ostream& os, const Date& date);
