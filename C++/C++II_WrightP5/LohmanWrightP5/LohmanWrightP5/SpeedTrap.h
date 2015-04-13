// Dar Wright 2275 C++ II dwright40@cnm.edu
// 03-05-12
// LohmanWrightP5
// SpeedTrap.h

/*
This class will check the call a patrol officer to check 
the vehicles speed
and the drivers license, then assign fees if speeding.
*/

#ifndef _SPEEDTRAP_H
#define _SPEEDTRAP_H

#include <string>				//for string object

#include "Date.h"				//for Date Class
#include "SpeedTrap.h"			//for SreedTrap Class
#include "TrafficGenerator.h"	//for TrafficGenerator Class
#include "Vehicle.h"			//for Vehicle Class
#include "PatrolOfficer.h"		//for Patrol Officer Class


using namespace std;

class SpeedTrap
{
private:
	string radarCopName; //variable for cop name 
	//since onyl one cop writes tickets, only one name is needed.
	string chaseNames[50]; //array to hold names
	void fillPONames(); //method to fill the array with name
	bool bReady; //bool to see if name file was opened
	string radarCopBadge; //variable to hold badge number

	double singleFee; //to hold fee for each violation
	string jailSummary; //to hold yes or no for jailed in summary
	//array to hold badge numbers  index for name and badge number will match
	string chaseCopBadges[50]; 

	int copIndex; //set the number of the cop index

	ofstream summary; //log file name
	Date timeIn; //for time stamp

	double totalMoney; //variable for total fees
	double jailFees; //variable for the jail fee
	bool bSpeeding; //variable to hold is vehicle is speeding
	bool bJailed; //variable to hold if driver sent to jail
	bool bLicValid; //variable to hold is driver lic is valid
	int vehiclesTicketed; //variable to hold how many drivers ticketed
	int vehiclesJailed; //variable to hold how many drivers jailed
	double feeStructure[7]; //array to hold speeding fines

	void fillTicketSpeedAndFees(); //method to fill fee array
	bool bReady_Trap_log; //bool to check if log file opened
	string trap_birthday; //variable to hold time stamp
	string logFileName; //variable for log name
	void openLogFile(); //method to open log file
	void writeLogFile(); //method to write to log file

public:
	SpeedTrap(); //constructor

	//method to call patrolofficer class to check if vehicle was speeding
	//and to check if license is valid.
	void checkSpeed(int speed); 

	bool getbReady_TrapLog(); //returns if log opened
	bool getBPONames(); //returns if names file opened
	void setCopIndex(int c); //random picks a cop and badge number to chase speeders
	void setbLicValid(bool b); //get if license valid bool from main
	~SpeedTrap(); //closes log file
};

#endif