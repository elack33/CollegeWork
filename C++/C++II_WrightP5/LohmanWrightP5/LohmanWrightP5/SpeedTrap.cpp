// Dar Wright 2275 C++ II dwright40@cnm.edu
// 03-05-12
// LohmanWrightP5
// SpeedTrap.cpp

#include "Date.h"				//for Date Class
#include "SpeedTrap.h"			//for SreedTrap Class
#include "Vehicle.h"			//for Vehicle Class
#include "TrafficGenerator.h"	//for TrafficGenerator Class
#include "PatrolOfficer.h"		//for Patrol Officer Class

#include <fstream>				//for file in & out
#include <string>				//for string object
#include <sstream>				//for string stream

SpeedTrap::SpeedTrap()
{
	radarCopName = "Bubba";
	chaseNames[50];
		
	bReady = false;
	radarCopBadge = "1234";
	chaseCopBadges[50];
		
	for(int i = 0; i < 50; i++)
		{
			chaseNames[i] = "Scooby Doo";
			chaseCopBadges[i] = 123;
		}

	copIndex = 0;

	totalMoney = 0;
	jailFees = 1000;
	jailSummary = "";
	bSpeeding = false;
	bJailed = false;
	vehiclesTicketed = 0;
	vehiclesJailed = 0;
	singleFee = 0;
	
	feeStructure[7];

	for(int i = 0; i < 7; i++)
	{
		feeStructure[i] = 1;
	}
	
	bReady_Trap_log = false;
	trap_birthday = "Bday";
	logFileName = "Ticket_log.txt";
	
	fillPONames();
	
}


void SpeedTrap::fillPONames()
{
	ifstream input;

	input.open("p.txt");

	if(!input)
	{
		bReady = false;
	}

	else
	{
		bReady = true;
		int i = 0;
		
		while(!input.eof() && i < 50)
		{
			getline(input, chaseNames[i]);
			i++;
		}
		input.close();

	}
	//set 50 cop badge numbers
	for(int i = 0; i < 50; i++)
	{
		int count = 1;
		string temp2 = "";
		char n;
		while (count < 7)
		{
			//generate random number between 0 + 9
			n = (rand() %1000)/100 + 48; 
			count ++;
			temp2 += n;
		}
		
		chaseCopBadges[i] = temp2;
	}
	fillTicketSpeedAndFees();
}

bool SpeedTrap::getBPONames()
{
	return bReady;

}

void SpeedTrap::fillTicketSpeedAndFees()
{

	feeStructure[0] = 110.00;
	feeStructure[1] = 130.00;
	feeStructure[2] = 150.00;
	feeStructure[3] = 160.00;
	feeStructure[4] = 190.00;
	feeStructure[5] = 210.00;
	feeStructure[6] = 220.00;

	openLogFile();
}

void SpeedTrap::openLogFile()
{
	summary.open("TicketLog.txt");

	string timeMade = "";

	timeMade = timeIn.CurrentTime();
	
	if(!summary)
	{
		bReady_Trap_log = false;
	}

	else
	{
		bReady_Trap_log = true;
		
	}
	stringstream ss;
	ss << "\nLakesha Loman & Dar Wright, CIS 2275 Program 5"
		<< "\nTicket Log File\n"
		<< timeMade << "\n"
		;
	summary << ss.str();

	
}



void SpeedTrap::setCopIndex(int c)
{
	copIndex = c;
	radarCopName = chaseNames[copIndex];
	radarCopBadge = chaseCopBadges[copIndex];
	
}

void SpeedTrap::setbLicValid(bool b)
{
	bLicValid = b;
}

void SpeedTrap::checkSpeed(int speed)
{
	int vSpeed = speed;
	
	int x = 0; //to hold speed index from PO class
	//create PO object
	PatrolOfficer po(radarCopName, radarCopBadge);
	//set values in
	po.vehicleCheckSpeed(vSpeed, bLicValid);
	
	//get values back

	double fee = 0;
	trap_birthday = timeIn.CurrentTime();
	
	bSpeeding = po.getIsSpeeding();
	bJailed = po.takeToJail();
	singleFee = 0;

	if(bJailed == true)
	{
		++vehiclesJailed;
		totalMoney += jailFees;
		singleFee = jailFees;
		jailSummary = "Yes";

	}

	else if(bSpeeding == true)
	{
		x = po.getSpeedFeeIndex();
		fee = feeStructure[x];
		vehiclesTicketed +=1;
		singleFee = fee;
		totalMoney += fee;
		jailSummary = "No";

	}
	
	writeLogFile();
}

void SpeedTrap::writeLogFile()
{
	stringstream ss;
	ss << "\nPO Name:  " << radarCopName 
		<< "\nBadge Number: " << radarCopBadge 
		<< "\nFees:        $" << singleFee
		<< "\nJailed?     : " << jailSummary
		<< "\n\n****Running total****\n" 
		<< "\nViolations:      " << vehiclesTicketed
		<< "\nDrivers Jailed: " << vehiclesJailed
		<< "\nTotal Fees:   $" << totalMoney << "\n\n"
		;
	summary << ss.str();
}

bool SpeedTrap::getbReady_TrapLog()
{
	return bReady_Trap_log;
}

SpeedTrap::~SpeedTrap()
{
	//close file
	summary.close();

}