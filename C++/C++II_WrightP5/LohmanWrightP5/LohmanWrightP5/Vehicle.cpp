//Lakesha Lohman and Dar Wright
//llohman@cnm.edu
//Program 5: GROUP PROJECT - The Mayberry Speed Trap Class(vehicle.cpp)

#include"Vehicle.h"
#include"Date.h"
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

//constructor
Vehicle::Vehicle()
{
	speed = 0;
	 
	driver = "";
	vehiclePlate = "";
	driverLicense = "";
	datetimestamp = "";
}

//overloaded constructor
Vehicle::Vehicle(int sp, string dri, string pL, string dL)
{
	speed = sp; 
	driver = dri;
	vehiclePlate = pL;
	driverLicense = dL;
}

//set vehicle speed;
void Vehicle::SetSpeed(int sp)
{
	speed = sp;
}

//set license plate number
void Vehicle::SetPlate(string pL)
{
	vehiclePlate = pL;
}

//set driver name;
void Vehicle::SetDriver(string dri)
{	
	driver = dri;
}

//set driver license number
void Vehicle::SetDriverLicense(string sdL)
{
	driverLicense = sdL;

}


//get vehicle speed - returns a string
int Vehicle::getVehicleSpeed()
{
	return speed;
}

//get license plate - returns a string
string Vehicle::getDriverLicense()
{
	return driverLicense;
}

//get vehicle description - returns a stringstream object
string Vehicle::getVehicleDescription()
{
	stringstream vDesc;

	vDesc << datetimestamp << " Vehicle speed: "  << speed << " mph " 
		  <<" License plate No. " << state << vehiclePlate 
		  <<"\n Driver: " << driver << " Driver License No. " << state << driverLicense;

	vehicleDesc = vDesc.str();

	return vehicleDesc;
}


