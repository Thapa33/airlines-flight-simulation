//BusinessJet.h 
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/25/2017
//This program is entirely of my work
#ifndef BUSINESSJET_H
#define BUSINESSJET_H
#include<iostream>
#include "Aircraft.h"
#include"AircraftTypes.h"
#include"FlightDataParser.h"
class Aircraft;
class BusinessJet : public Aircraft
{
private:
public:
	BusinessJet();
	void createAircraft();

};
#endif