//City.cpp 
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/25/2017
//This program is entirely of my work
#include"City.h"

City :: City()
{

}
City :: City (char city, char state, char symbol, double latitude, double longitude)
	
{
	m_city[32] = city;
	m_state[32] = state;
	m_symbol[32] = symbol;
	m_latitude = latitude;
	m_longitude = longitude;
}
City :: ~City()  //class destructior
{
}

const char *City :: getCity() const 
{
	return m_city;
}
const char *City :: getState() const
{
	return m_state;
}
const char *City :: getSymbol() const
{
	return m_symbol;
}
double City :: getLatitude() const
{
	return m_latitude;
}
double City :: getLongitude() const 
{
	return m_longitude;
}
void   City :: setCity(char *city) 
{
	strcpy(m_city , city);
}
void   City :: setState(char *state)
{
	strcpy(m_state , state);
}
void   City :: setSymbol(char *symbol)
{
	strcpy(m_symbol, symbol);
}
void   City :: setLatitude(double latitude)
{
	m_latitude = latitude;
}
void   City :: setLongitude(double longitude)
{
	m_longitude = longitude;
}

void City:: fillCityData(CityDataParser *cdp)
{
	
	cdp->getCityData(m_city,m_state,m_symbol,&m_latitude,&m_longitude);
	/*
	cout<<m_city<<endl;
	cout<<m_state<<endl;
	cout<<m_symbol<<endl;
	cout<<m_latitude<<endl;
	cout<<m_longitude<<endl;
	*/
	
}
