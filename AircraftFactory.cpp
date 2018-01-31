//AircraftFactory.cpp 
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/27/2017
//This program is entirely of my work

#include"AircraftFactory.h"

AircraftFactory :: AircraftFactory()
{

}
Aircraft  * AircraftFactory:: getAircraft()
{
	return NULL;
}

void AircraftFactory :: setPlaneMake(char plane){
	strcpy(m_Plane_make, &plane);
}
void AircraftFactory :: setPlaneDescription(char desc){
	strcpy(m_Plane_desc, &desc);
}
void AircraftFactory :: setRateOfClimb(double climbRate){
	m_rateOfClimb = climbRate;
}
void AircraftFactory :: setWingspan(double wingspan){
	m_wingSpan = wingspan;
}
void AircraftFactory :: setLength(double length){
	m_length = length;
}
void AircraftFactory :: setCruiseSpeed(double cruiseSpeed){
	m_cruise_Speed = cruiseSpeed;
}
void AircraftFactory :: setCruiseAltitude(double cruiseAltitude){
	m_cruise_Altitude = cruiseAltitude;
}