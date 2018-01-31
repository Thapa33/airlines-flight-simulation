//BusinessJet.cpp 
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/27/2017
//This program is entirely of my work

#include"BusinessJet.h"
#include"BusinessJetFactory.h"
BusinessJet :: BusinessJet()
{

}

void BusinessJet:: createAircraft(){
	FlightDataParser * fdp = FlightDataParser :: getInstance();
	
	fdp->getAircraftData(BUSINESSJET, m_Plane_make, m_Plane_desc,&m_rateOfClimb,
		&m_wingSpan, &m_length ,&m_cruise_Speed,&m_cruise_Altitude);
	/*BusinessJetFactory * bsf = BusinessJetFactory::getInstance();
	bsf->getAircraft();*/
}