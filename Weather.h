/**
*********************************************************
*
* @file		Weather.h
* @brief	A Weather Class
* @version	1
* @date		11/03/2018
* @author	Aung Kyaw Myint
*
*****************************************************************
*/

#ifndef H_Weather
#define H_Weather

#include <iostream>
#include "Date.h"
#include "Time.h"

using namespace std;

class Weather
{
	
	
public:
	Weather();																	///Constructor
	Weather(int d, int m, int y, int hr, int mn, float w, float sr, float aT);	///Constructor
	~Weather();																	///Destructor

	// Setter Function --------------------------------------------------

	/**
	*@brief		Set the Wind Speed
	*@return	Void
	*/
	void setWindSp(float ws);

	/**
	*@brief		Set the Solar Radiation
	*@return	Void
	*/
	void setSolarR(float sr);

	/**
	*@brief		Set the Air Temperature
	*@return	Void
	*/
	void setAirTemp(float air);

	/**
	*@brief		Set the Date
	*@return	Void
	*/
	void setDate(Date dt);
	
	/**
	*@brief		Set the Time
	*@return	Void
	*/
	void setTime(Time time1);

	// Getter Function ---------------------------------------

	/**
	*@brief		Get the Wind Speed
	*@return	float value windSp
	*/
	float getWindSp() const;

	/**
	*@brief		Get the Solar Radiation
	*@return	float value	solarR
	*/
	float getSolarR() const;

	/**
	*@brief		Get the Air Temperature
	*@return	float value airTemp
	*/
	float getAirTemp() const;

	/**
	*@brief		Get the Month
	*@return	integer value date.month
	*/
	int getMonth() const;

	/**
	*@brief		Get the Year
	*@return	integer value date.year
	*/
	int getYear() const;
	
	/**
	*@brief		Print out the attributes of Weather
	*@return	void
	*/
	void print() const;

private:
	Date date;		///date Object
	Time time;		///time Object
	float windSp;	///windSp Variable
	float solarR;	///solarR Variable
	float airTemp;	///airTemp Variable


};

#endif