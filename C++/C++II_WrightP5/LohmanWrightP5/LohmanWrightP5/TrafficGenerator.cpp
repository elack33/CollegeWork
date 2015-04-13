// Dar Wright 2275 C++ II dwright40@cnm.edu
// 03-05-12
// LohmanWrightP5
// TrafficGenerator.cpp

#include "SpeedTrap.h"			//for SreedTrap Class
#include "TrafficGenerator.h"	//for TrafficGenerator Class
#include "Date.h"				//for Date Class
#include "Vehicle.h"			//for Vehicle Class
#include "PatrolOfficer.h"		//for Patrol Officer Class

#include <fstream>				//for file in & out
#include <string>				//for string object
#include <sstream>				//for string stream


TrafficGenerator::TrafficGenerator()
{
	vCount = 1;
	vSpeed = 82;
	state = "NM";
	licensePlate = state + "CAT454";
	driverName = "LUIGI MARIO";
	
	for(int i = 0; i < 50; i++)
	{
		driverNames[i] = "LUIGI MARIO";
	}

	lineNumber = 1;

	timeMade = "13:14:15";
	dateMade = "03/05/2012";
	description = "Test test test";

	bReady = false;
	bReady_TG_Log = false;
	openLog();
}

void TrafficGenerator::startVehicle()
{
	readFile();
	
	chooseVehicleSpeed();

}

void TrafficGenerator::chooseVehicleSpeed()
{
	
	int n = 0;
	
	n = (rand()%8500)/100 + 16;

	vSpeed = n;
	chooseState();
}

void TrafficGenerator::chooseState()
{
	

	int n = 12489;
	n = rand() %1000;
	
	if(n < 700)
	{
		state = "NM";
	}
	else if(n > 760)
	{
		state = "OR";
	}
	else if(n > 820)
	{
		state = "TX";
	}
	else if(n > 880)
	{
		state = "AK";
	}
	else if(n > 940)
	{
		state = "GA";
	}
	else
	{
		state = "AL";
	}
	chooseLicensePlate();

}


void TrafficGenerator::chooseLicensePlate()
{
	
	int count = 1;
	string temp = "";
	string temp2 = "";
	char t;
	char n;
	while (count < 4)
	{
		t = rand() %26 + 65; //generate random CAPITAL LETTER
		n = rand() %10 + 48; //generate random number between 0 + 9
		count ++;
		temp += t;
		temp2 += n;
	}

	licensePlate = state + " " + temp + temp2;
	makeDriverLicense();

}

void TrafficGenerator::readFile()
{
	ifstream input;

	input.open("n.txt");

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
			getline(input, driverNames[i]);
			i++;
		}
		input.close();

	}
}

bool TrafficGenerator::getbReady()
{
	return bReady;
}

void TrafficGenerator::chooseDriverName()
{
	int n = 0;
	n = rand() % 500;
	n = n / 10;
	
	driverName = driverNames[n];
	writeLogFile();
}

void TrafficGenerator::makeDriverLicense()
{
	int count = 1;
	string temp2 = "";
	char n;
	while (count < 10)
	{
		//generate random number between 0 + 9
		n = (rand() %1000)/100 + 48; 
		count ++;
		temp2 += n;
	}

	int temp;
	temp = rand() %1000;
	if(temp < 800)
	{
		driverLicense = state + " " + temp2;
		bLicenseValid = true;
	}
	else
	{
		driverLicense = "Invalid License";
		bLicenseValid = false;
	}
	chooseDriverName();
}


bool TrafficGenerator::getbReadyLog()
{
	return bReady_TG_Log;
}

void TrafficGenerator::openLog()
{
	
	summary.open("summary.txt");

	timeMade = timeIn.CurrentTime();
	dateMade = dateIn.GetFormattedDate();

	if(!summary)
	{
		bReady_TG_Log = false;
	}

	else
	{
		bReady_TG_Log = true;
		
	}
	stringstream ss;
	ss << "\nLakesha Loman & Dar Wright, CIS 2275 Program 5"
		<< "\nTraffic Generator Log File\n"
		<< timeMade << "\n"
		<< dateMade << "\n\n"
		;
	summary << ss.str();
}


void TrafficGenerator::setvCount(int c)
{
	vCount = c;
}

void TrafficGenerator::writeLogFile()
{
	
	Vehicle rV(vSpeed, driverName, licensePlate, driverLicense);
	description = rV.getVehicleDescription();

	summary << "\n"<< lineNumber << "." << 
		description << "\n";

	++lineNumber;
}

int TrafficGenerator::getVehicleSpeed()
{
	return vSpeed;
}

TrafficGenerator::~TrafficGenerator()
{
	
	//close file
	summary.close();
}