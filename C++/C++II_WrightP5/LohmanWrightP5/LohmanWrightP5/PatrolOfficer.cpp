//Lakesha Lohman and Dar Wright
//llohman@cnm.edu
//Program 5: GROUP PROJECT - The Mayberry Speed Trap Class (patrolofficer.cpp)

#include"PatrolOfficer.h"
#include"Vehicle.h"
#include<string>

using namespace std;

//constructor
PatrolOfficer::PatrolOfficer()
{	//initialize variables;

	badgeNo = "";

	speed = 0;
	Ticketed = 0;
	radarCopName = "";
	chaseCopName = "";
	bIsSpeeding = false;
	speedFeeIndex = -1;
	bDriverValid = false;
	bJail = false;

}

//possible overloaded constructor
PatrolOfficer::PatrolOfficer(string radName, string badgeNum)
{
	radarCopName = radName;		//radar cop's name
	badgeNo = badgeNum;			//radar cop's badge number


	bool bLicenseValid = false;
	bool driverLicenseInvalid = true;

	//check for valid, invalid or no license; chase cop sends driver to jail


	if(bLicenseValid == false)
	{
		takeToJail();
	}

	
	else if (driverLicenseInvalid == false)
	{	
		chaseCopName;
		badgeNo;
		Ticketed;
		takeToJail();
	}

}


//set chase cop's name
void PatrolOfficer::SetChaseCopsName(string n)

{
	chaseCopName = n;
}

//set chase cop's badge number (changed back tostring)
void PatrolOfficer::SetChaseCopsBadge(string b)
{
	badgeNo = b;
}


void PatrolOfficer::vehicleCheckSpeed(int sp, bool bDriver)
{
	//gets passed is driver valid bool from speed trap & speed
	bDriverValid = bDriver;
{
	if(bDriverValid == false)
	{
		bJail = true;
	}
	else
	{
		bJail = false;
	}

	speed = sp;

	if(speed < 26)
	{
		bIsSpeeding = false;
	}
	else if(speed > 25 && speed < 34)
	{
		bIsSpeeding = true;
		speedFeeIndex = 0;
	}
	else if(speed > 33 && speed < 43)
	{
		bIsSpeeding = true;
		speedFeeIndex = 1;
	}
	else if(speed > 42 && speed < 52)
	{
		bIsSpeeding = true;
		speedFeeIndex = 2;
	}
	else if(speed > 51 && speed < 62)
	{
		bIsSpeeding = true;
		speedFeeIndex = 3;
	}
	else if(speed > 61 && speed < 71)
	{
		bIsSpeeding = true;
		speedFeeIndex = 4;
	}
	else if(speed > 71 && speed < 80)
	{
		bIsSpeeding = true;
		speedFeeIndex = 5;
	}
	else
	{
		bIsSpeeding = true;
		speedFeeIndex = 6;
	}
	
}



}

