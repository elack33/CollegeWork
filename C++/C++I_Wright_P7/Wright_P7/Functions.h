// Dar Wright C++ 1 dwright40@cnm.edu
// 11-28-11
// WrightP7
// Functions.h

#include <string>		//for string object

using namespace std;

	//declare function prototypes

	//Play again function, to run the program again
void WriteGreeting();
string PlayAgain();

	//Function to open the file and read in the data
bool ReadFile(string mobileCountry[], double mobile2000[], double mobile2001[],  
	double mobile2002[],double mobile2003[], double mobile2004[], 
	double mobile2005[],double mobile2006[], double mobile2007[], 
	double mobile2008[], double mobile2009[], double mobile2010[]);

	//Function to take the data read and put it into more usable formats
void getUseful(string mobileCountry[], double mobile2000[], double mobile2001[],  
	double mobile2002[],double mobile2003[], double mobile2004[], 
	double mobile2005[],double mobile2006[], double mobile2007[], 
	double mobile2008[], double mobile2009[], double mobile2010[],
	double china[], double us[]);

	//Function to calculate the growth of cell phone subscripts per year
	//and over ten years
void calcGrowth(double china[], double us[], double growthChina[], double growthUs[],
				double &growth10yrChina, double &growth10yrUs);

	//Function to find the year of maximum growth and the growth amount
void maxGrowth(double growthChina[], double growthUs[], double temp1[], 
			double temp2[],	double &maxUS, double &maxChina, int &yearMaxUs, 
			int &yearMaxChina);

	//Function to compare the maximum growth amount and determine which country had the most growth
	//each year and over ten years
void compareResults(double &maxUS, double &maxChina, double &growth10yrChina, double &growth10yrUs, 
		double &compareChinaUsMax, double &compareChinaUs10yr,
		string &compareHigh, string &compareLow, 
		string &compareHigh10yr, string &compareLow10yr);

	//Function to output the results into a file.
bool outPut(double &maxUS, double &maxChina, int &yearMaxUs, int &yearMaxChina,
			double &growth10yrUs, double &growth10yrChina, int year[],
			double &compareChinaUsMax, double &compareChinaUs10yr, string &compareHigh, 
			string &compareLow, string &compareHigh10yr, string &compareLow10yr);
