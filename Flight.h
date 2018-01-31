//Flight.h 
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/25/2017
//This program is entirely of my work
#pragma once
#ifndef Flight_H
#define Flight_H
#include<iostream>
#include<string>
#include"Aircraft.h"
#include"City.h"
//#include"Simulation.h"
#include"CityDataParser.h"
#include"FlightDataParser.h"
using namespace std;

class Simulation;
class Aircraft;
class Flight  
{
private:
	//FlightDataParser time;
	char  m_AirlineCompany[32];
	char M_aircraftType[32];
	Aircraft  aircraft;
	City dep_city;
	City arr_city;
		
	int m_flightNumber;
	char m_departure_City[4];
	int m_depart_Hour;
	int m_depart_minute;
	char m_arrival_City[4];
	double m_distance;
	//The below variable is for the calculation
	double timeToReachMaximumHeight;
	double m_estimated_Trip_Time;
	int m_current_latitude;
	int m_current_longitude;
	int m_estimated_arrival_hour;
	int m_estimated_arrival_mins;
	double m_distanceFrom_departure;
	double m_distanceTo_arrival;
	double m_current_Altitude;
	double m_time_elapsed_in_Hour;
	int m_currentSpeed;
	bool takeFlight;
	bool flightNumber;  // to print only once
	int descendingMinute;



public:
	Flight();
	Flight(char company, char aircraftType, int flightNumber, char departureCity, int departHour,
		int departMinute, char arrivalCity, double Distance);
	~Flight(); 
	const char *get_AirlineCompany() const;
	const char *get_Aircraft_Type() const;
	
	int  get_FlightNumber() const;
	const char *get_DepartureCity() const;
	int get_DepartureHour() const;
	int get_DepartureMinute() const;
	const char *get_ArrivalCity() const;
	double get_Distance() const;
	//void  getCurrentTime();
	
	double getTimeToReachMaxHeight();

	void set_AirlineCompany(char *company);
	void setAircraftType(char * aircraftType);
	
	void set_FlightNUmber(int flightNumber);
	void set_DepartureCity(char * DepartureCity);
	void set_DepartureHour(int hour);
	void set_departureMinute(int minute);
	void set_ArrivalCity(char *ArrivalCity);
	void set_Distance(double distance);
	void fillFlightData(FlightDataParser *fdp);
	//from here is new added function for calculation
	double getestimated_Trip_Time_hour();
	int getcurrent_latitude();
	int getcurrent_longitude();
	int getEstimated_arrival_hour();
	int getEstimated_arrival_mins();
	double getDistanceFrom_departure();
	double getDistanceTo_arrival();
	double getCurrent_Altitude();
	double getTime_elapsed_in_Hour();
	int getCurrentSpeed();
	int getCurrentTimeElapsedInHour();
	void setCurrentSpeed();

	void  setEstimated_Trip_Time_hour();
	void  setCurrent_latitude();
	void  setCurrent_longitude();
	
	void setDistanceFrom_departure();
	void setDistanceTo_arrival();
	void setCurrent_Altitude();
	void setTime_elapsed_in_Hour(int currhr,int currmin);


	void setDepCityInfo(City depCity);
	void setArrCityInfo(City arrCity);
	void setAirCraftInfo(Aircraft ac);
	
	void printDepartureFlight(int currhr, int currmin);
	void printArrivalFlight(int currhr, int currmin);
	void printCurrentStatus(int curhr, int curmin);
	void updateFlight(int hour, int minute);
	int compareFlightTime(int curHour, int curMin, int depHour, int depMin);
	


};

#endif