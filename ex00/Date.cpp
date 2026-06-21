#include "Date.hpp"
#include <stdexcept>
#include <iomanip>

Date::Date(): _year(0), _month(1), _day(1)
{

}

static bool isLeapYear(unsigned int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

Date::Date(unsigned int year, unsigned int month, unsigned int day): _year(year), _month(month), _day(day)
{
	if (month < 1 || month > 12)
		throw std::invalid_argument("Month not valid");

	unsigned int daysInMonth[] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};

	unsigned int maxDays = daysInMonth[month - 1];

	if (month == 2 && isLeapYear(year))
		maxDays = 29;

	if (day < 1 || day > maxDays)
		throw std::invalid_argument("Day not valid");
}

Date::~Date()
{

}

Date&	Date::operator=(const Date& date)
{
	_year = date._year;
	_month = date._month;
	_day = date._day;
	return (*this);
}

bool	Date::operator>(const Date& date) const
{
	if (this->_year > date._year)
		return true;
	else if (this->_year < date._year)
		return false;
	if (this->_month > date._month)
		return true;
	else if (this->_month < date._month)
		return false;
	if (this->_day > date._day)
		return true;
	return false;
}

bool	Date::operator<(const Date& date) const
{
	if (this->_year < date._year)
		return true;
	else if (this->_year > date._year)
		return false;
	if (this->_month < date._month)
		return true;
	else if (this->_month > date._month)
		return false;
	if (this->_day < date._day)
		return true;
	return false;
}

bool	Date::operator==(const Date& date) const
{
	if (this->_year == date._year && this->_month == date._month && this->_day == date._day)
		return true;
	return false;
}

unsigned int	Date::getYear() const
{
	return _year;
}

unsigned int	Date::getMonth() const
{
	return _month;
}

unsigned int	Date::getDay() const
{
	return _day;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os << std::setfill('0')
	<< std::setw(4) << date.getYear() << "-"
	<< std::setw(2) << date.getMonth() << "-"
	<< std::setw(2) << date.getDay();

	return os;
}
