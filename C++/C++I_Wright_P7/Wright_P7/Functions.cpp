// Dar Wright C++ 1 dwright40@cnm.edu
// 11-28-11
// WrightP7
// Functions.cpp

#include <string>				//for string object
#include <sstream>				//for streamstring
#include <iostream>				//for cout, cin, getline
#include <fstream>				//for file in & out
#include "Functions.h"			//For Functions
#include <algorithm> 
#define FILE "MobileCellularSubscriptions00-10.csv" //Mobile SubScription file


using namespace std;



//Write Functions
	//Write out header
void WriteGreeting()
{
		cout << "\n\nDar Wright, Program 7\n"
		<<"This program will open a file of data from\n"
		<<"http://www.itu.int/ITU-D/ict/statistics/"
		<<"\nMobile Celluar Subscriptions, and input the data.\n"
		<<"The program will then calculate the growth percentage for china and the us \n"
		<<"by year, show the year with the most growth for both countries,\n"
		<<"and compare the growth for the max growth year, and over ten years.\n";


}

	//Ask Customer if the want to play again
string PlayAgain()
{
	string play;
	cout << "\nThank you for using my calculator! I hope you enjoyed it!";
	cout << "\nWould you like to use the calculator again? yes/no:  ";

	getline(cin,play);

		return play;
}

	//Function to open file and read in data
bool ReadFile(string mobileCountry[], double mobile2000[], double mobile2001[],  
	double mobile2002[],double mobile2003[], double mobile2004[], 
	double mobile2005[],double mobile2006[], double mobile2007[], 
	double mobile2008[], double mobile2009[], double mobile2010[])
{


	ifstream input;

		//Open file
	input.open(FILE);

		//Check if file fails to open
	if(! input)
	{
		cout << "\n Cannot find " << FILE;
		return false;
	}
		
		//Message to user that file is being read
	cout << "\n Reading " << FILE << ", please wait...\n\n";
	
		
	/* 
	Inport data file.
	Data format:
	China,85260000.0,144820000.0,206005000.0,269953000.0,334824000.0,393406000.0,461058000.0,
	547306000.0,641245000.0,747214000.0,859003000.0,,6.72,11.33,16.02,20.87,25.74,30.09,35.07,
	41.42,48.28,55.97,64.04,,,Ministry of Information Industry (MII).,,
	Ministry of Information Industry (MII).,,Ministry of Information Industry (MII).,,
	Ministry of Information Industry (MII).,,Ministry of Information Industry (MII).,,
	Ministry of Information Industry (MII).,,Ministry of Information Industry (MII).,,
	Ministry of Information Industry (MII).,,Ministry of Industry and Information Technology,,
	Ministry of Industry and Information Technology,,Ministry of Industry and Information Technology
	*/


	while(!input.eof())
	{
		
		string trash;
		getline(input,trash);	//read and trash some of the lines
		
		for( int i = 0; i < 250; i++)
		{
			
				//read in the country
			getline(input, mobileCountry[i], ','); 

				//Read in data from 2000 & convert to a double
			char *pEnd;
			string s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;
			getline(input, s0, ',');
			mobile2000[i] = strtod(s0.c_str(), &pEnd);

				//Read in data from 2001 & convert to a double
			getline(input, s1, ',');
			mobile2001[i] = strtod(s1.c_str(), &pEnd);

				//Read in data from 2002 & convert to a double
			getline(input, s2, ',');
			mobile2002[i] = strtod(s2.c_str(), &pEnd);

				//Read in data from 2003 & convert to a double
			getline(input, s3, ',');
			mobile2003[i] = strtod(s3.c_str(), &pEnd);

				//Read in data from 2004 & convert to a double
			getline(input, s4, ',');
			mobile2004[i] = strtod(s4.c_str(), &pEnd);

				//Read in data from 2005 & convert to a double
			getline(input, s5, ',');
			mobile2005[i] = strtod(s5.c_str(), &pEnd);

				//Read in data from 2006 & convert to a double
			getline(input, s6, ',');
			mobile2006[i] = strtod(s6.c_str(), &pEnd);

				//Read in data from 2007 & convert to a double
			getline(input, s7, ',');
			mobile2007[i] = strtod(s7.c_str(), &pEnd);

				//Read in data from 2008 & convert to a double
			getline(input, s8, ',');
			mobile2008[i] = strtod(s8.c_str(), &pEnd);

				//Read in data from 2009 & convert to a double
			getline(input, s9, ',');
			mobile2009[i] = strtod(s9.c_str(), &pEnd);

				//Read in data from 2010 & convert to a double
			getline(input, s10, ',');
			mobile2010[i] = strtod(s10.c_str(), &pEnd);		

				//Trash the rest of the line
			getline(input,trash);
		}

	}

	//close the file
	input.close();

	return true;
}

	//Function to extract data and put in more usable containers
void getUseful(string mobileCountry[], double mobile2000[], double mobile2001[],  
	double mobile2002[],double mobile2003[], double mobile2004[], 
	double mobile2005[],double mobile2006[], double mobile2007[], 
	double mobile2008[], double mobile2009[], double mobile2010[],
	double china[], double us[])
{
	int chinaIndex = -1;
	
		//Message to user that data is being organzied
	cout << "\nOrganizing data into useful arrays...";

			//Search for index # that holds data for China
		for(int i = 0, j = 0; i < 250; j ++, i++)
		{
			string ch = "China";
			
			if(mobileCountry[i] == ch)
			{
				chinaIndex = i;
				break;
			}
		}

			//Search for index # that holds data for US
	int UsIndex = -1;
		for(int j = 0; j < 250; j ++)
		{
			string us = "United States";
			
			if(mobileCountry[j] == us)
			{
				UsIndex = j;
				break;
			}
		}
	
		//Fill array for china with data 
		china[0] = mobile2000[chinaIndex];
		china[1] = mobile2001[chinaIndex];
		china[2] = mobile2002[chinaIndex];
		china[3] = mobile2003[chinaIndex];
		china[4] = mobile2004[chinaIndex];
		china[5] = mobile2005[chinaIndex];
		china[6] = mobile2006[chinaIndex];
		china[7] = mobile2007[chinaIndex];
		china[8] = mobile2008[chinaIndex];
		china[9] = mobile2009[chinaIndex];
		china[10] = mobile2010[chinaIndex];

		//Fill array for US with data
		us[0] = mobile2000[UsIndex];
		us[1] = mobile2001[UsIndex];
		us[2] = mobile2002[UsIndex];
		us[3] = mobile2003[UsIndex];
		us[4] = mobile2004[UsIndex];
		us[5] = mobile2005[UsIndex];
		us[6] = mobile2006[UsIndex];
		us[7] = mobile2007[UsIndex];
		us[8] = mobile2008[UsIndex];
		us[9] = mobile2009[UsIndex];
		us[10] = mobile2010[UsIndex];

}

		//Function to calculate the growth rate of cell phone
		//Subscriptions for China nad US by yr and over 10 yrs
void calcGrowth(double china[], double us[],  
				double growthChina[], double growthUs[],
				double &growth10yrChina, double &growth10yrUs)

{

		//Message to user that data is being anazlized and calculated
	cout << "\nCalculating the growth percentage per year...";
	
	//calc growth for each year for china and US 

	for(int i = 0, j = 1; i < 11; i++, j++)
	{
		growthChina[i] = ((china[j] - china[i]) / china[i]) * 100;
		growthUs[i] = ((us[j] - us[i]) / us[i]) * 100;

	}

	growth10yrChina = ((china[10] - china[0])/ china[0]) * 100;
	growth10yrUs = ((us[10] - us[0])/ us[0]) * 100;

}

	//Function to determine maximum growth per year and over ten yrs
void maxGrowth(double growthChina[], double growthUs[], double temp1[], 
			double temp2[],	double &maxUS, double &maxChina, int &yearMaxUs, 
			int &yearMaxChina)
{

		//Message to user that data is being anazlized and calculated
	cout << "\nCalculating the maximum growth percetange...";

		//Moving data into different array to sort and find the largest, without
		//Compromising Index Values as they will be needed for another function
	for(int i = 0, j = 0; j < 11; i++, j++)
	{
		temp1[j] = growthUs[j];
		temp2[i] = growthChina[i];
	}
	
	double max1 = temp1[0];
	double max2 = temp2[0];

		//Find the maximum value
	for(int l = 0, m = 0; m < 11; l ++, m++)
	{
			if(temp1[m] > max1)
			{
				max1 = temp1[m];
			}

			if(temp2[l] > max2)
			{
				max2 = temp2[m];
			}

			maxUS = max1;
			maxChina = max2;

	}

		//Match the maximum value to an index number
	for(int i = 0; i < 11; i++)
		{
			
			if(growthUs[i] == max1)
			{
				yearMaxUs = i;

				if(yearMaxUs == 0)
				{
					yearMaxUs = 1;
				}

				break;
			}
		}


	for(int j = 0; j < 11; j ++)
		{
			if(growthChina[j] == max2)
			{
				yearMaxChina = j;

				if(yearMaxChina == 0)
				{
					yearMaxChina = 1;
				}

				break;
			}


		}


	
}

	//Function to compare the results
void compareResults(double &maxUS, double &maxChina, double &growth10yrChina, double &growth10yrUs, 
		double &compareChinaUsMax, double &compareChinaUs10yr, string &compareHigh, string &compareLow, 
		string &compareHigh10yr, string &compareLow10yr)
{
	
		//Message to user that results are being compared
	cout << "\nComparing results...";
	
		//Compare maximum values for yearly growth
	if(maxUS > maxChina)
	{
		compareChinaUsMax = maxUS - maxChina;
		compareHigh = "United States";
		compareLow = "China";
	}
	else
	{
		compareChinaUsMax = maxChina - maxUS;
		compareHigh =  "China";
		compareLow = "United States";
	}

		//Compare maximum values for 10 yr growth
	if(growth10yrUs > growth10yrChina)
	{
		compareChinaUs10yr = growth10yrUs - growth10yrChina;
		compareHigh10yr = "United States";
		compareLow10yr = "China";
	}
	else
	{
		compareChinaUs10yr = growth10yrChina - growth10yrUs;
		compareHigh10yr = "China";
		compareLow10yr = "United States";

	}
}


	//Call function to prepare report with results
bool outPut(double &maxUS, double &maxChina, int &yearMaxUs, int &yearMaxChina,
			double &growth10yrUs, double &growth10yrChina, int year[],
			double &compareChinaUsMax, double &compareChinaUs10yr, string &compareHigh, 
			string &compareLow, string &compareHigh10yr, string &compareLow10yr)
{
	string filename;
	
		//Ask user for name for report file
	cout << "\nPlease enter a filename for the result file (output.txt):   ";
	cin >> filename;
	cin.ignore();

	ofstream resultOut;

	resultOut.open(filename.c_str());

	if(!resultOut)
	{
		return false;
	}

	else
	{

		//Create result report
	stringstream ss1;
						
	ss1.setf(ios::fixed | ios::showpoint);
	ss1.precision(2);
	ss1 << "China had the most growth, (" << maxChina << "% )"
		<< " in cell phone subscriptions between: "
		<< year[(yearMaxChina -1)] << " and " <<year[(yearMaxChina)] 
		<< ".\n"
		<< "The US had the most growth, (" << maxUS << "% )"
		<< " in cell phone subscriptions between: "
		<< year[(yearMaxUs -1)] << " and " <<year[(yearMaxUs)] 
		<< ".\n\n"
		<< "China experienced an overall growth of " << growth10yrChina
		<< "% over ten years.\n"
		<< "The US experienced an overall growth of " << growth10yrUs
		<< "% over ten years.\n\n"
		<< compareHigh << " grew " << compareChinaUsMax << "% more then " 
		<< compareLow << " at the highest growth rate per year.\n"
		<< compareHigh10yr << " grew " << compareChinaUs10yr << "% more then "
		<< compareLow10yr << " over ten years.";

	string output;
	output = ss1.str();
			
	resultOut << output;

	resultOut.close();

	return true;

	}

	
}




