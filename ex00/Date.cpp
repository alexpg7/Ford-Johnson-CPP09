#include "Date.hpp"

Date::Date(): _year(0), _month(0), _day(0)
{

}

Date::Date(unsigned int year, unsigned int month, unsigned int day): _year(year), _month(month), _day(day)
{

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
