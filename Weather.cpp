#include <iostream>
#include "Weather.h"


using namespace std;

Weather::Weather() //Constructor
{
	windSp = 0;
	solarR = 0;
	airTemp = 0;
}
Weather::Weather(int d, int m, int y, int hr, int mn, float w, float sr, float aT):date(d, m, y), time(hr, mn) //COnstructor
{
	windSp = w;
	solarR = sr;
	airTemp = aT;
}

Weather::~Weather()//Destructor
{
}

//Getter Function
void Weather::setDate(Date dt)
{
	date = dt;
}

void Weather::setTime(Time time1)
{
	time = time1;
}
void Weather::setWindSp(float ws){
	windSp = ws;
}
void Weather::setSolarR(float sr) {
	solarR = sr;
}
void Weather::setAirTemp(float air){
	airTemp = air;
}

//Setter FUnction
int Weather::getMonth() const
{
	return date.getMonth();
}

int Weather::getYear() const
{
	return date.getYear();
}
float Weather::getWindSp() const
{
	return windSp;
}

float Weather::getSolarR() const
{
	return solarR;
}

float Weather::getAirTemp() const
{
	return airTemp;
}
void Weather::print() const //Print
{
	cout << windSp << "," << solarR << "," << airTemp << endl;
}
