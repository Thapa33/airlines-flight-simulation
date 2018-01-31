//Aircraft.h 
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/25/2017
//This program is entirely of my work
#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include<iostream>
#include<string.h>

#include"CityDataParser.h"
#include"FlightDataParser.h"

using namespace std;

class Aircraft 
{
protected:
	//AircraftType m_Plane_Type[32];
	char m_Plane_make[32];
	char m_Plane_desc[32];
	double m_rateOfClimb;
	double m_wingSpan;
	double m_length;
	double m_cruise_Speed;
	double m_cruise_Altitude;

public:

	Aircraft();
	Aircraft(char plane_make, char plane_desc,double rateOfClimb, double wingSpan, 
		double length, double cruiseSpeed =0.0 ,double cruiseAltitude= 0.0);
	
	~Aircraft();
	//AircraftType *getPlaneType();
	const char *getPlaneMake() const;
	const char *getPlaneDescription() const;
	double  getRateOfClimb() const;
	double getWingSpan() const;
	double getLength() const;
	double getCruise_Speed() const;
	double getCruise_Altutude() const;
	
	void setPlaneType(AircraftType t);
	void setPlaneMake(char *planeMake);
	void setPlaneDescription(char * planetype);
	void setRateOfClimb(double climbRate);
	void setWingSpan(double wingspan);
	void setLength(double length); 
	void setCruiseSpeed(double cruiseSpeed);
	void setCruiseAltitude(double cruiseAltitude);
	//void fillData(FlightDataParser fdp);

};

#endif