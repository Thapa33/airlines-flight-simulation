//SingleEnginePlane.cpp 
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/27/2017
//This program is entirely of my work

#include"SingleEnginePlane.h"
SingleEnginePlane :: SingleEnginePlane()
{

}

void SingleEnginePlane:: createAircraft(){
	FlightDataParser * fdp = FlightDataParser :: getInstance();
	
	fdp->getAircraftData(SINGLEENGINE, m_Plane_make, m_Plane_desc,&m_rateOfClimb,
		&m_wingSpan, &m_length ,&m_cruise_Speed,&m_cruise_Altitude);
}