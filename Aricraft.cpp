//Aircraft.cpp 
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/25/2017
//This program is entirely of my work

#include"Aircraft.h"


Aircraft :: Aircraft(char plane_make, char plane_desc,double rateOfClimb, double wingSpan, 
		double length, double cruiseSpeed,double cruiseAltitude)
{
	//m_Plane_Type[32] = plane_type;
	m_Plane_make[32] = plane_make;
	m_Plane_desc[32] = plane_desc;
	m_rateOfClimb = rateOfClimb;
	m_wingSpan = wingSpan;
	m_length = length;
	m_cruise_Speed = cruiseSpeed;
	m_cruise_Altitude = cruiseAltitude;
}


Aircraft :: Aircraft()
{
}
Aircraft :: ~Aircraft()
{
}

//AircraftType * Aircraft :: getPlaneType()
//{
//	return m_Plane_Type;
//}
const char *Aircraft :: getPlaneMake() const
{

	return m_Plane_make;
}
const char *Aircraft :: getPlaneDescription() const
{
	return m_Plane_desc;
}
double Aircraft :: getRateOfClimb() const
{
	return m_rateOfClimb;
}
double  Aircraft :: getWingSpan() const
{
	return m_wingSpan;
}
double  Aircraft :: getLength() const
{
	return m_length;
}
double  Aircraft :: getCruise_Speed() const
{
	return m_cruise_Speed;
}
double  Aircraft :: getCruise_Altutude() const
{
	return m_cruise_Altitude;
}

//void Aircraft :: setPlaneType(AircraftType t)
//{
//	*m_Plane_Type = t;
//	
//}

void Aircraft :: setPlaneMake(char *planeMake)
{
	strcpy(m_Plane_make, planeMake);
}
void Aircraft :: setPlaneDescription(char *planetype)
{
	strcpy(m_Plane_desc , planetype);
}
void Aircraft :: setRateOfClimb(double climbRate)
{
	m_rateOfClimb = climbRate;
}
void Aircraft :: setWingSpan(double wingspan)
{
	m_wingSpan = wingspan;
}
void Aircraft :: setLength(double length)
{
	m_length = length;
}
void Aircraft :: setCruiseSpeed(double cruiseSpeed)
{
	m_cruise_Speed = cruiseSpeed;
}
void Aircraft :: setCruiseAltitude(double cruiseAltitude)
{
	m_cruise_Altitude = cruiseAltitude;
}


