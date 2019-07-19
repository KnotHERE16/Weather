//Date.cpp
#include <iostream>
#include "Date.h"

using namespace std;

//Constructor
Date::Date() 
{
	day = 1;
	month = 1;
	year = 2000;
}

Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

//Destructor
Date::~Date()
{
}

//Setter Function
void Date::setDay(int d)
{
	day = d;
}
void Date::setMonth(int m)
{
	month = m;
}
void Date::setYear(int y)
{
	year = y;
}
void Date::setDate(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

//Getter Function
int Date::getDay() const
{
	return day;
}
int Date::getMonth() const
{
	return month;
}
int Date::getYear() const
{
	return year;
}

// Print Function
void Date::print() const
{
	cout << day << "/"
		<< month << "/"
		<< year << " ";


}

//ostream operator
ostream& operator << (ostream& osObject, const Date& date1)
{
	osObject << date1.day
		<< "/" << date1.month
		<< "/" << date1.year<<": ";

	return osObject;
}

//istream opreator
istream& operator >> (istream& isObject, Date& date1)
{
	isObject >> date1.day >> date1.month >> date1.year;

	return isObject;
}