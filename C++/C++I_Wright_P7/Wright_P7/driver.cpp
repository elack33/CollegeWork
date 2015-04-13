// Dar Wright C++ 1 dwright40@cnm.edu
// 11-28-11
// WrightP7
// driver.cpp



/*This program will open a file of data from
http://www.itu.int/ITU-D/ict/statistics/
Mobile Celluar Subscriptions, and input the data.
The program will then calculate the growth percentage for china and the us by year,
show the year with the most growth for both countries,
compare the growth over ten years.\n";
*/

#include <iostream>				//for cout, cin, getline
#include <string>				//for string object
#include "Functions.h"			//For Functions

using namespace std;


int main()
{
		//declare variables
	string answer = "yes";

	string mobileCountry[250];
	double mobile2000[250];
	double mobile2001[250];
	double mobile2002[250];
	double mobile2003[250];
	double mobile2004[250];
	double mobile2005[250];
	double mobile2006[250];
	double mobile2007[250];
	double mobile2008[250];
	double mobile2009[250];
	double mobile2010[250];

	double china[12];
	double us[12];

	double growthChina[11];
	double growthUs[11];
	double growth10yrChina = 0;
	double growth10yrUs = 0;
	
	double temp1[11];
	double temp2[11];

	double compareChinaUsMax;
	double compareChinaUs10yr;

	string compareHigh;
	string compareLow;
	string compareHigh10yr; 
	string compareLow10yr;

	double maxUS = 0;
	double maxChina = 0;
	int yearMaxUs = 0;
	int yearMaxChina = 0;

	int year[12] = {2000,2001,2002,2003,2004,2005,
					2006,2007,2008,2009,2010,'\0'};

		//Show greeting
	WriteGreeting();
		
		//Start loop to run program again
	while(answer == "yes")
	{

		//Call function to open the file and read data
	bool result = ReadFile(mobileCountry, mobile2000, mobile2001,  
	mobile2002,mobile2003, mobile2004,  
	mobile2005,mobile2006, mobile2007,  
	mobile2008, mobile2009, mobile2010);

		//Check to see if file opened
	if(result = false)
	{
		cout << "\nAn error occured, please try again.";
	}
	
		//Call function to organize data into more useful formats
	getUseful(mobileCountry, mobile2000,  mobile2001, mobile2002, mobile2003,  
			mobile2004,  mobile2005, mobile2006,  mobile2007, 
	 mobile2008,  mobile2009,  mobile2010, china, us);

		//Call function to calculate growth
	calcGrowth(china, us, growthChina, growthUs, growth10yrChina, growth10yrUs);

		//Call function to find maximum growth
	maxGrowth(growthChina,  growthUs,  temp1, temp2,  maxUS,  maxChina, 
				yearMaxUs, yearMaxChina);

		//Call function to compare growth
	compareResults(maxUS,  maxChina,  growth10yrChina,  growth10yrUs, 
		 compareChinaUsMax,  compareChinaUs10yr, compareHigh, compareLow, 
		compareHigh10yr, compareLow10yr);

		//Call function to report results to a file
	bool outputRestult = outPut(maxUS,  maxChina,  yearMaxUs,  yearMaxChina,
			 growth10yrUs,  growth10yrChina,  year, compareChinaUsMax,  
			 compareChinaUs10yr, compareHigh, compareLow, compareHigh10yr, 
			 compareLow10yr);

			//Check if file fails to save
		if(outputRestult = false)
		{
			cout << "\nAn error occured when trying to save the file, please try again.";
		}

			//Ask user if they want to run again
	answer = PlayAgain();
	
	}
		
	return 0;
}
		