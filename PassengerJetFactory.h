//PassengerJetFactory.h 
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/25/2017
//This program is entirely of my work
#ifndef PASSENGERJETFACTORY_H
#define PASSENGERJETFACTORY_H
#include<iostream>
#include"AircraftFactory.h"
class Aircraft;
class PassengerJetFactory : public AircraftFactory
{
private:
	int instanceNumber;
	PassengerJetFactory();
public:
	~PassengerJetFactory();
	int getInstanceNumber();
	static PassengerJetFactory * getInstance();
	Aircraft *getAircraft();

};

#endif