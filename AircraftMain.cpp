//AircraftMain.cpp 
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/27/2017
//This program is entirely of my work

#include<iostream>
#include"Aircraft.h"
#include"AircraftFactory.h"

#include"Simulation.h"
using namespace std;
int main()
{

	cout<<"-----------------------------------------------\n\n";
	cout<<"Welcome to the Aircraft Simulation Software\n";
	cout<<"-----------------------------------------------\n\n";
	Simulation sim;
	sim.RunSimulation();

	system("pause");
	return 0;
}
