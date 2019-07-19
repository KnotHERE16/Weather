/**
*********************************************************
*
* @file		Time.h
* @brief	A Time Class
* @version	1
* @date		11/03/2018
* @author	Aung Kyaw Myint
*
*****************************************************************
*/

#ifndef TIME_H
#define TIME_H
#include <iostream>

using namespace std;

class Time
{
	// Overloaing function -------------------------------------

	friend ostream& operator << (ostream&, const Time&);
	friend istream& operator >> (istream&, Time&);

	//----------------------------------------------------------

public:
	Time();///Constructor
	Time(int hh, int mm);///Constructor
	~Time();///Destructor

	// Setter Functions ----------------------------------------

	/**
	*@brief		Set the hour
	*@return	void
	*/
	void setHours(int hh);

	/**
	*@brief		Set the minute
	*@return	void
	*/
	void setMinutes(int mm);

	/**
	*@brief		Set the time
	*@return	void
	*/
	void setTime(int hh, int mm);

	//Getter Fuction --------------------------------------------

	/**
	*@brief		Get the hour
	*@return	Integer value hour
	*/
	int getHours();

	/**
	*@brief		Get the minute
	*@return	Integer value minutes
	*/
	int getMinutes();

	//-----------------------------------------------------------

	/**
	*@brief		Print out the Time 
	*@return	void
	*/
	void print() const;


private:
	int hours;		/// hours variables
	int minutes;	/// minutes variables

};
#endif