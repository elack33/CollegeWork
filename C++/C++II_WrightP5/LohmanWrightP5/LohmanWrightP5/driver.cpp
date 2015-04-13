//Dar Wright 2275 C++ II dwright40@cnm.edu
// 03-05-12
// LohmanWrightP5
// driver.cpp

/*This program will model traffic as it goes through a speed trap. 
A patrol officer with a radar gun will tag the vehicle and chase vehicles 
will pursue if the vehicle is in fact speeding.
The program will ask for the number of vehicles to send through
the trap and create log files of the results.
*/

#include <iostream>				//for cout, cin, getline
#include <string>				//for string object
#include <sstream>				//For String Stream
#include <ctime>				//for time
#include "SpeedTrap.h"			//for SreedTrap Class
#include "TrafficGenerator.h"	//for TrafficGenerator Class
#include "Vehicle.h"			//for Vehicle Class
#include "PatrolOfficer.h"		//for Patrol Officer Class

void WriteGreeting();

using namespace std;

int main()
{
	TrafficGenerator tg;
	SpeedTrap st;
	srand((unsigned)time(0));
	int test = 0;
	int count = 0;
	WriteGreeting();
	bool nameRead = false;
	bool logReady = false;
	bool copName = false;
	bool trafficLog = false;
	bool good = false;

	do
	{
		cout << "\nPlease enter the number of vehicles you want "
			<< "\nto run through the speed trap (no more then 50): ";
		cin >> count;
		cin.ignore();
		cin.clear();
		cin.sync();

		if(count > 51)
			{
				cout << "\nYou entered an invalid number, please try again.";
				good = false;

			}
		else if(count < 1 )
			{
				cout << "\nYou entered an invalid number, please try again!";
				good = false;
			}

		else
			{
				cout << "\nStarting the Mayberry Speed Trap!\n";
				good = true;
			}
		
	}while(good == false);


	int i = 1;
	do{
		tg.setvCount(count);
		tg.startVehicle();
	
		nameRead = tg.getbReady();
		copName = st.getBPONames();

		if(nameRead == false || copName == false)
		{
			cout << "\nUnable to read in names file. Please try again.";
		}
		else if(i == 1)
			{
				logReady = tg.getbReadyLog();
				trafficLog = st.getbReady_TrapLog();
				if(logReady == false || trafficLog == false)
				{
					cout << "\nUnable to open summary log file. Please try again.";

				}
				else
				{
					cout << "\nGenerating log files, please wait....";
				}
			}

		else
		{
		int speed = 0;
		speed = tg.getVehicleSpeed();
		st.setbLicValid(tg.getbLicenseValid());
		st.setCopIndex(i);
		st.checkSpeed(speed);

		}
		
		i++;
	}while (i < count );
		
	cout << "\n\nThank you for using the Mayberry Speed trap program!"
		<<"\n\nPlease feel free to view the summary.txt (for the traffic generator),"
		<<"\nto see how many people went through the trap, "
		<< "\nand the TicketLog.txt(for speed trap)"
		<<"\nto see how many people were SPEEDING!!!!!\n\n";

	return 0;
}//end main
		
void WriteGreeting()
{
		cout << "\n\n Lakesha Lohman & Dar Wright, CIS2275 - Program 5 \n"
			<< "The Mayberry Speed Trap!\n"
			<< "This program will ask a user for how many vehicles to run \n" 
			<< "through the speed trap and create a log file with details \n"
			<< "of each vehicle in it, and create a report of how many cars\n"
			<< "were speeding and if they were fined. \n\n";
}