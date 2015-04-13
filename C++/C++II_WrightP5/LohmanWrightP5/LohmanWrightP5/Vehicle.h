//Lakesha Lohman and Dar Wright
//llohman@cnm.edu
//Program 5: GROUP PROJECT - The Mayberry Speed Trap Class(vehicle.h)

/* This class represents one vehicle at a time. It will have
three get functions, and return a string description of the 
vehicle speed, license plate , driver name, and driver license.*/

#ifndef _VEHICLE_H
#define _VEHICLE_H

#include<string>

using namespace std;

class Vehicle
{
private: 
	
	int speed;			//how fast vehicle travels
	
	int count;			//vehicle counter

	string driver, vehicleDesc;		//driver name and vehicle description
	
	string driverLicense, vehiclePlate;//driver license and license plate numbers
	
	string state;						//state driver is from

	string datetimestamp;			//time on ticket

public:

	Vehicle();			//constructor
	Vehicle(int speed, string driver, string pL, string dL);//overloaded constructor

	void SetSpeed(int sp);				//set vehicle speed
	void SetDriver(string dri);			//set driver name
	void SetPlate(string pl);			//set license plate number
	void SetDriverLicense(string sdL);	//set driver license number

	int getVehicleSpeed();						//get vehicle speed
	string getDriverLicense();						//get driver license
	string getVehicleDescription();		//get vehicle description string


};

#endif







