//City.h
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 10/17/2017
//This program is entirely of my work
#ifndef CITY_H
#define CITY_H
#include<iostream>
#include<string>
#include"CityDataParser.h"
#include"FlightDataParser.h"

using namespace std;

class City
{
private:
	char m_city[32];
	char m_state[32];
	char m_symbol[32];
	double m_latitude;
	double m_longitude;
public:
	City();
	City(char city, char state, char symbol, double latitude =0.0, double longitude = 0.0);
	~City(); //class destructior
	const char *getCity() const;
	const char *getState() const;
	const char *getSymbol() const;
	double getLatitude() const;
	double getLongitude() const;
	void setCity(char *city);
	void setState(char *state);
	void setSymbol(char * symbol);
	void setLatitude(double latitude);
	void setLongitude(double longitude);
	void fillCityData(CityDataParser *cdp);


};

#endif
