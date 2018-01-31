//SingleEnginePlaneFactory.h 
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/25/2017
//This program is entirely of my work
#ifndef SINGLEENGINEPLANEFACTORY_H
#define SINGLEENGINEPLANEFACTORY_H
#include<iostream>
#include"AircraftFactory.h"
#include"SingleEnginePlane.h"
class Aircraft;
class SingleEnginePlaneFactory : public AircraftFactory

{
private:
	int instanceNumber;
	SingleEnginePlaneFactory();
public:
	~SingleEnginePlaneFactory();
	int getInstanceNUmber();
	static SingleEnginePlaneFactory *getInstance();
	Aircraft * getAircraft();

};

#endif