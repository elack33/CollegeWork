// Dar Wright 2275 C++ II dwright40@cnm.edu
// 03-05-12
// LohmanWrightP5
// TrafficGenerator.h

/*
This class will use a random number generator to generate vehicle speed.
It will read a file to access drive names and generate driver license
for the vehicle.
It will also write a log file with the information.
*/

#ifndef _TRAFFICGENERATOR_H
#define _TRAFFICGENERATOR_H

#include <string>				//for string object
#include <fstream>				//for file in and out

#include "SpeedTrap.h"			//for SreedTrap Class
#include "TrafficGenerator.h"	//for TrafficGenerator Class
#include "Date.h"				//for Date Class
#include "Vehicle.h"			//for Vehicle Class
#include "PatrolOfficer.h"		//for Patrol Officer Class

using namespace std;

class TrafficGenerator
{
private:
	int vCount; //number of vehicles created
	int vSpeed; //vehicle speed
	int lineNumber; //variable for log file lines
	string licensePlate; //variable to hold License Plate
	string driverName; //variable to hold driver name
	string driverNames[50]; //array of strings to hold driver name options
	string driverLicense; //variable to hold driver license
	string timeMade; //variable to hold timestamp
	string dateMade; //variable to hold date
	string state; //variable to hold state 
	void chooseState(); // Method to choose state (70 % NM, 30% other)

	//opens name file and reads in 50 driver names.
	void TrafficGenerator::readFile(); 
	//bool to indicate if names file was read
	bool bReady;

	//vehicle class calls the following
	//string description; //vehicle string returned from vehicle class
	void chooseVehicleSpeed(); //uses randomization to choose vehicle speed
	void chooseLicensePlate(); //uses randomization to create  license plate
	void makeDriverLicense();  //uses randomization to create license
	bool bLicenseValid; //used to set valid or invalid drivers license
	void chooseDriverName();  //randomly chooses driver name from array
	//end vehicle class calls

	bool bReady_TG_Log; //checks if log file opened
	void openLog(); //opens & creates log file
	ofstream summary; //log file name
	void closeLog(); //closes log file

	void writeLogFile(); //writes the log file

	//Date class variables
	Date timeIn; //for time stamp
	Date dateIn; //for date stamp
	
public:
	TrafficGenerator(); //constructor
	~TrafficGenerator(); //desctructor
	int getVehicleSpeed();//to get speed to check for speeding	
	bool getbReady(); //returns bool for reading name file
	void startVehicle(); //gets vehicle description from vehicle class
	bool getbReadyLog(); //returns bool for opening log file

	//returns bool for valid drivers license
	bool getbLicenseValid() {return bLicenseValid;} 

	string description; //vehicle string returned from vehicle class

	void setvCount(int c); //sets how many vehicles the user choose
};


#endif