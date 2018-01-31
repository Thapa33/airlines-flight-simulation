//BusinessJetFactory.h
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/25/2017
//This program is entirely of my work
#ifndef BUSINESSJETFACTORY_H
#define BUSINESSJETFACTORY_H
#include<iostream>
#include"AircraftFactory.h"
#include"Aircraft.h"
#include"BusinessJet.h"
class Aircraft;
class BusinessJetFactory : public AircraftFactory
{
private:
	int instanceNumber;
	BusinessJetFactory();
public:
	~BusinessJetFactory();
	int getInstanceNumber();
	static BusinessJetFactory *getInstance();
	Aircraft * getAircraft();

	void  createAircraft(AircraftType t);
	

};
#endif