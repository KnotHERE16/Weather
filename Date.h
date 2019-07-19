/**
*********************************************************
*
* @file		Date.h
* @brief	A Date Class
* @version	1
* @date		11/03/2018
* @author	Aung Kyaw Myint
*
*****************************************************************
*/
#ifndef H_Date
#define H_Date

#include <iostream>

using namespace std;


class Date
{
	// Overloaing function -------------------------------------

	friend ostream& operator << (ostream&, const Date&);
	friend istream& operator >> (istream&, Date&);

	//----------------------------------------------------------

public:
	Date(); /// Constructor
	Date(int d, int m, int y);/// Constructor
	~Date(); /// Destructor

	// Setter Functions ----------------------------------------
	
	/**
	*@brief		Set the day
	*@param		
	*@return	void
	*/
	void setDay(int d);

	/**
	*@brief		Set the month
	*@return	void
	*/
	void setMonth(int m);
	/**
	*@brief		Set the year
	*@return	void
	*/
	void setYear(int y);
	/**
	*@brief		Set the Date
	*@return	void
	*/
	void setDate(int d, int m, int y);

	//Getters Functions ------------------------------------------------

	/**
	*@brief		Get the day
	*@return	Integer value day
	*/
	int getDay() const;

	/**
	*@brief		Get the month
	*@return	Integer value month
	*/
	int getMonth() const;

	/**
	*@brief		Get the year
	*@return	Integer value year
	*/
	int getYear() const;
	
	//------------------------------------------------------
	
	/**
	*@brief		Print out the date
	*@return	void
	*/
	void print() const;


	 
private:
	int day;	/// day variable
	int month;	/// month variable
	int year;	/// year variable
};
#endif