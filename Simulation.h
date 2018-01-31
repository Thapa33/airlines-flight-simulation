//Simulation.h
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/25/2017
//This program is entirely of my work
#ifndef SIMULATION_H
#define SIMULATION_H
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<sys/types.h>
#include<sys/timeb.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include"FlightDataParser.h"
#include"CityDataParser.h"
#include"BusinessJetFactory.h"
#include"PassengerJetFactory.h"
#include"SingleEnginePlaneFactory.h"
#include"Aircraft.h"
#include"BusinessJet.h"
#include"SingleEnginePlane.h"
#include"PassengerJet.h"
#include"Flight.h"
#include"City.h"
using namespace std;




class Simulation
{
private:
	
	char * m_FlightFileName;
	char * m_CityFileName;
	int m_CityCount;
	int m_flightCount_Business;
	int m_flightCount_Passenger;
	int m_flightCount_Single;
	int m_flightNum;
	vector<Aircraft > listofAircraft;
	vector<Flight> listOfFlight;
	vector<City> listofCities;

	//FlightDataParser fdp;
	//CityDataParser cdp;
	int m_runSpeed;
	int m_start_hour;
	int m_start_minute;
	char  ** m_symbol;  //list of symbol for citites
	double *m_distanceTable;	

	int m_currentHour;
	int m_currentMinute;
	
	//int numCity; //number of city in the simulation
	//int numFlight; //number of flight in the simulation

public:
	Simulation();
	~Simulation();
	void initializatation();

	void readFile();
	void RunSimulation();
	string getCityFile();
	string getFlightFile();
	void setCityFile(string cityFile);
	void setAircraftFile(string aircraftFile);
	int getCityCoutn();
	int getFlightCountBusiness();
	int getFlightCountPassenger();
	int getFlightCountSingle();
	
	int getFlightNumber();
	

	vector<City> getListOfCities();
	vector<Flight> getListOfFlight();
	vector<Aircraft > getListOfAircraft();

	void printTest();

	
	int getRunSpeed();  //ask the user to input the timer for simulation
	
	char getCitySymobl(); 
	//int getNUmCity();  //number of city
	//void setNumCity();
	//int getnumFlight();
	void setNumFlight();
	double getDistanceTable();
	void setDistanceTable(double distance);
	void setCitySymbol(char  *symbol);
	
	int getCurrentHour();
	int getCurrentminute();
	void setCurrentHour(int ch);
	void setCurrentMinute(int min);	
	
	int findCtySymbolIndex(char const *dep_citySym);

	City findDepCityInfo(Flight f);
	City  findArrCityInfo(Flight f);
	Aircraft  findAirCraftInfo(Flight f);
		
	void updateCurrentTime (int startHr, int startMin);

	void print();
	

};

#endif