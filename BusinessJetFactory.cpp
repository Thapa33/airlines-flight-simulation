//BusinessJetFactory.cpp 
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/27/2017
//This program is entirely of my work

#include"BusinessJetFactory.h"

#include"Aircraft.h"
BusinessJetFactory :: BusinessJetFactory()
{
}
BusinessJetFactory :: ~BusinessJetFactory()
{
}

int BusinessJetFactory :: getInstanceNumber()
{
	return instanceNumber;
}

BusinessJetFactory * BusinessJetFactory :: getInstance()
{
	static int counter = 1;
	static BusinessJetFactory *theInstance = NULL;
	if(theInstance == NULL)
	{
		theInstance = new BusinessJetFactory();
		theInstance->instanceNumber = counter;
	}
	return theInstance;
}
Aircraft *BusinessJetFactory::getAircraft()
{
	return new BusinessJet;
}
	
void BusinessJetFactory :: createAircraft( AircraftType t){
	FlightDataParser *fdp = FlightDataParser::getInstance();
	//char m_Plane_Type[32];
	/*char m_Plane_make[32];
	char m_Plane_desc[32];
	double m_rateOfClimb;
	double m_wingSpan;
	double m_length;
	double m_cruise_Speed;
	double m_cruise_Altitude;*/

	
	

	fdp->getAircraftData(BUSINESSJET, m_Plane_make, m_Plane_desc,
		&m_rateOfClimb, &m_wingSpan, &m_length , &m_cruise_Speed, &m_cruise_Altitude);
	
	
}