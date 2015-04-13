//Lakesha Lohman and Dar Wright
//llohman@cnm.edu
//Program 5: GROUP PROJECT - The Mayberry Speed Trap Class(patrolofficer.h)

/* The Patrol Officer class deals with one vehicle at a time. The vehicle
will enter the speed trap and the radar cop checks the vehicle to determine
if it is speeding. If so, a ticket speed range is set. The chase cop will
stop the vehicle and check for valid/invalid licenses. If the license
is not valid, the chase cop takes the driver to jail. Next chase cop
will lineup to chase the next speeder.*/


#ifndef _PATROLOFFICER_H
#define _PATROLOFFICER_H

#include<string>
#include"Vehicle.h"


using namespace std;

class PatrolOfficer
{
private:

	string badgeNo;	//badge number - greater than 100, less than 1000
	
	int speed;
	int Ticketed;
	string radarCopName;	//radar officer name

	string chaseCopName;	//chase officer name

	bool bIsSpeeding;	//set to true if speeding, false if not
	int speedFeeIndex; //returns the index number for the fee
	bool bDriverValid; //is license valid from speed trap
	bool bJail;	//variable to hold if driver taken to jail
	
public:

	PatrolOfficer();		//constructor

	PatrolOfficer(string radName, string badgeNum);	//possible overloaded constructor

	void SetChaseCopsName(string n);			//set chase cop name
	void SetChaseCopsBadge(string b);			//set chase cop badge number; 

	int getSpeed();		//index of speeding range

	string setRadarCopName();	//return radar cop's name
	string setChaseCopName();	//return chase cop's name

	void vehicleCheckSpeed(int sp, bool bDriverValid);	//pass in int speed

	//adjusted method to return value
	bool takeToJail() {return bJail;}		//go to jail for invalid or no license

	bool getIsSpeeding() {return bIsSpeeding;} //give back if speed bool to speedtrap
	int getSpeedFeeIndex() {return speedFeeIndex;} //Return index number for fee range

};

#endif





