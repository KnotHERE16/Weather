#include <iostream>
#include "Time.h"
using namespace std;

Time::Time()// Constructor
{
	hours = 0;
	minutes = 0;
}

Time::Time(int hh, int mm) //Constructor
{
	hours = hh;
	minutes = mm;
}

Time::~Time() //Destructor
{
}

//Setter Function
void Time::setHours(int hh)
{
	hours = hh;
}

void Time::setMinutes(int mm)
{
	minutes = mm;
}

void Time::setTime(int hh, int mm)
{
	hours = hh;
	minutes = mm;
}

//Getter Function
int Time::getHours()
{
	return hours;
}

int Time::getMinutes()
{
	return minutes;
}

void Time::print() const
{
	cout << hours << ":" << minutes << endl;
}

ostream& operator << (ostream& osObject, const Time& T1)
{
	osObject << T1.hours
		<< ":" << T1.minutes;

	return osObject;
}

//istream opreator
istream& operator >> (istream& isObject, Time& T1)
{
	isObject >> T1.hours >> T1.minutes;

	return isObject;
}