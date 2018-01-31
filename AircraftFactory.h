//AircraftFactory.h 
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/25/2017
//This program is entirely of my work
#pragma once
#include<iostream>
#include"Aircraft.h"
class Aircraft;
using namespace std;

class AircraftFactory
{
public:
	char m_Plane_make[32];
	char m_Plane_desc[32];
	double m_rateOfClimb;
	double m_wingSpan;
	double m_length;
	double m_cruise_Speed;
	double m_cruise_Altitude;
	AircraftFactory();

	void setPlaneMake(char plane);
	void setPlaneDescription(char desc);
	void setRateOfClimb(double climbRate);
	void setWingspan(double wingspan);
	void setLength(double length);
	void setCruiseSpeed(double cruiseSpeed);
	void setCruiseAltitude(double cruiseAltitude);

	virtual Aircraft *getAircraft();
};