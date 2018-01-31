//SingleEnginePlane.h
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/25/2017
//This program is entirely of my work
#ifndef SINGLEENGINE_H
#define SINGLEENGINE_H
#include<iostream>
#include "Aircraft.h"
class Aircraft;
class SingleEnginePlane : public Aircraft
{
private:
public:
	SingleEnginePlane();
	void createAircraft();

};
#endif