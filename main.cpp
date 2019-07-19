/*
*****************************************************************
Main class

Brief Description
1. Read file and store them in vector
2. Prompt the menu and get user choice
3. Run the selected choice and display result
4. Exit program

******************************************************************
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Date.h"
#include "Time.h"
#include "Vector.h"
#include "Weather.h"

using namespace std;

void menuOption();									// Display the menu 
void readData();									// Read the Data from file 
void totalSolarRad(int year2);						// Display the Total Solar Radiation of each month for that year
void allData(int year3);							// Write to file about the weather
void averageSpdYear(int year2);						// Display the average wind speed of each month for that year
bool checkYear(int year);							// Check if the year is in the data
bool checkMonth(int mth, int year);					// Check if the month is in the dataa
float averageSpeed(int mth1, int year1);			// Return the Average Wind Speed for the specific month and year
float averageTemp(int mth1, int year1);				// Return the Average Air Temperature for the specific month and year
float convertsolarRad(float sr);					// Convert W per 10 min to kW per hour
float totalSolarRadMonth(int mth, int year);		// Return the total solar radiation for the specific month and year
string month(int input);							// Convert numeric month to alphabetical month


Vector<Weather> windData;


int main()
{
	int choice = 0;
	cout << fixed << showpoint << setprecision(1);
	readData();
	while (choice != 5)
	{

		menuOption();
		cout << "Choice : ";
		cin >> choice;

		if (choice < 1 || choice>5)
			cout << "Invalid Choice" << endl;
		switch (choice) {
		case 1: {
			int mth1, yearIn1;
			string alpmth;
			float avgspd1, avgtemp1;
			cout << "Choice 1" << endl;
			cout << "Enter the year" << endl;
			cin >> yearIn1;
			cout << endl;
			if (checkYear(yearIn1) == false)
			{
				cout << "No Data for year " << yearIn1 << endl;
			}
			else
			{

				do {
					cout << "Enter the month" << endl;
					cin >> mth1;
					cout << endl;
					if (mth1 < 1 || mth1>12)
						cout << "Invalid month\n" << endl;
				} while (mth1 < 1 || mth1>12);
				if (checkMonth(mth1, yearIn1) == false)
				{
					cout << "No Data for " << month(mth1) << endl;
				}
				else {

					avgspd1 = averageSpeed(mth1, yearIn1);
					avgtemp1 = averageTemp(mth1, yearIn1);
					alpmth = month(mth1);

					cout << alpmth << " " << yearIn1 << ": " << avgspd1 << " km/h, " << avgtemp1 << " degrees C" << endl;
				}
			}
			break;

		}

		case 2:
		{
			int yearIn2;

			cout << "Enter the year" << endl;
			cin >> yearIn2;
			cout << endl;
			averageSpdYear(yearIn2);
			cout << endl;
			break;
		}
		case 3:
		{
			int yearIn3;

			cout << "Enter the year" << endl;
			cin >> yearIn3;
			cout << endl;
			totalSolarRad(yearIn3);
			break;
		}
		case 4:
		{
			int yearIn4;

			cout << "Enter the year" << endl;
			cin >> yearIn4;
			cout << endl;
			allData(yearIn4);
			cout << "Done" << endl;
			break;
		}

		case 5:
			cout << "Thank you" << endl;
		}
	}

	system("Pause");
	return 0;
}
void menuOption() {

	cout << endl;
	cout << "Please enter your choice" << endl;
	cout << "1. The average wind speed and average temperature for a specified month and year." << endl;
	cout << "2. Average wind speed and average ambient air temperature for each month of a specified year" << endl;
	cout << "3. Total solar radiation in kWh/m2 for each month of a specified year." << endl;
	cout << "4. Average wind speed(km/h),average ambient air temperature and \ntotal solar radiation in kWh/m2 for each month of a specified year." << endl;
	cout << "5. Exit the pogram." << endl;
}
void readData()
{
	string filename;
	ifstream input;

	cout << "Enter file name: " << endl;
	cin >> filename;

	input.open(filename);

	if (!input)
		cout << "Error opening the file.";
	input.ignore(500, '\n');
	while (!input.eof()) {
		string line, line2, s_Day, s_Month, s_Year, s_Hr, s_Min, s_Spd, s_T;
		float sRad;
		getline(input, s_Day, '/');
		getline(input, s_Month, '/');
		getline(input, s_Year, ' ');

		getline(input, s_Hr, ':');
		getline(input, s_Min, ',');

		float spd1, temp1;

		for (int i = 0; i < 10; i++)
		{
			input >> spd1;
			input.ignore(50, ',');
		}

		input >> sRad;
		input.ignore(50, ',');

		for (int i = 0; i < 6; i++)
		{
			input >> temp1;
			if (i == 5)
				getline(input, line, '\n');
			else
				input.ignore(50, ',');
		}

		int day1 = stoi(s_Day);
		int month1 = stoi(s_Month);
		int year1 = stoi(s_Year);
		int hour1 = stoi(s_Hr);
		int min1 = stoi(s_Min);

		Weather Wd1; //create a record
		Date date1;
		Time time1;
		date1.setDate(day1, month1, year1);
		time1.setTime(hour1, min1);
		Wd1.setDate(date1);
		Wd1.setTime(time1);
		Wd1.setWindSp(spd1);
		Wd1.setSolarR(sRad);
		Wd1.setAirTemp(temp1);

		windData.push_back(Wd1);//push inside vector

	}
	input.close();
}
bool checkYear(int year) {
	int yearYes = 0;
	for (int i = 0; i < windData.size(); i++)
	{
		if (year == windData.at(i).getYear())
			yearYes++;
	}
	if (yearYes == 0)
		return false;
	else
		return true;
}
bool checkMonth(int mth, int year) {


	int numofmonth = 0;
	for (int i = 0; i < windData.size(); i++)
	{
		if (year == windData.at(i).getYear())
		{
			if (mth == windData.at(i).getMonth()) {
				numofmonth++;
			}
		}
	}
	if ((numofmonth == 0))
		return false;
	else
		return true;
}
float averageSpeed(int mth1, int year1) {

	float numofdata = 0;
	float avgSpeed;
	float totalSpeed = 0;

	for (int i = 0; i < windData.size(); i++)
	{
		if (windData.at(i).getMonth() == mth1 && windData.at(i).getYear() == year1)
		{
			
			totalSpeed = totalSpeed + windData.at(i).getWindSp();
			
			numofdata++;
			
		}
	}
	avgSpeed = totalSpeed / numofdata;
	return avgSpeed;

}
string month(int input)
{
	switch (input) {
	case 1:
		return "January";
		break;
	case 2:
		return "Feburary";
		break;
	case 3:
		return "March";
		break;
	case 4:
		return "April";
		break;
	case 5:
		return "May";
		break;
	case 6:
		return "June";
		break;
	case 7:
		return "July";
		break;
	case 8:
		return "August";
		break;
	case 9:
		return "September";
		break;
	case 10:
		return "October";
		break;
	case 11:
		return "November";
		break;
	case 12:
		return "December";
		break;

	}
	return "Invalid";
}
float averageTemp(int mth1, int year1)
{
	float numofdata = 0;
	float avgTemp;
	float totalTemp = 0;

	for (int i = 0; i < windData.size(); i++)
	{
		if (windData.at(i).getMonth() == mth1 && windData.at(i).getYear() == year1)
		{
			totalTemp = totalTemp + windData.at(i).getAirTemp();
			numofdata++;
			//cout << "The total speed after added is : " << totalTemp << endl;
			//cout << "the num of data is : " << numofdata << endl;
		}
	}
	avgTemp = totalTemp / numofdata;
	return avgTemp;
}
void averageSpdYear(int year2)
{
	float avgSpd, avgTemp;
	cout << year2 << endl;

	for (int i = 1; i <= 12; i++) {
		if (checkMonth(i, year2) == false)
		{
			cout << month(i) << ": No Data" << endl;
		}
		else
		{
			avgSpd = averageSpeed(i, year2);
			avgTemp = averageTemp(i, year2);
			cout << month(i) << ": " << avgSpd << " km/h, " << avgTemp << " degrees C" << endl;
		}

	}
}
float convertsolarRad(float sr)
{
	return (sr / 6) / 1000;
}
float totalSolarRadMonth(int mth, int year)
{
	float totalSr = 0;
	for (int i = 0; i < windData.size(); i++)
	{
		if (mth == windData.at(i).getMonth() && year == windData.at(i).getYear())
		{
			if (windData.at(i).getSolarR() >= 100)
				totalSr = totalSr + windData.at(i).getSolarR();
		}
	}
	totalSr = convertsolarRad(totalSr);
	return totalSr;
}
void totalSolarRad(int year2)
{
	float total = 0;
	cout << year2 << endl;

	for (int i = 1; i <= 12; i++)
	{
		if (checkMonth(i, year2) == false)
		{
			cout << month(i) << ": No Data" << endl;
		}
		else {
			total = totalSolarRadMonth(i, year2);
			cout << month(i) << " " << total << " kWh/m2" << endl;
		}
	}
}
void allData(int year3)
{
	float avgSpd;
	float avgTem;
	float totalSR;
	ofstream dataFile;
	dataFile.open("WindTempSolar.csv");
	dataFile << year3 << endl;
	if (checkYear(year3) == false)
	{
		dataFile << "No Data" << endl;
	}
	else
	{
		for (int i = 1; i <= 12; i++)
		{
			if (checkMonth(i, year3) == true)
			{
				avgSpd = averageSpeed(i, year3);
				avgTem = averageTemp(i, year3);
				totalSR = totalSolarRadMonth(i, year3);
				dataFile << fixed << setprecision(1) << month(i) << "," << avgSpd << "," << avgTem << "," << totalSR << endl;
			}
		}
	}
	dataFile.close();
}


