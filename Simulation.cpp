//Simulation.cpp 
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/27/2017
//This program is entirely of my work

#include"Simulation.h"

Simulation::Simulation(){

}
Simulation::~Simulation() {
}
void Simulation :: readFile() {
	string line;
	string filename;
	cout<<"Please Enter the File: ";
	cin>> filename;
	ifstream infile(filename);

	if (infile.is_open()) 
	{
	int line_number = 1;
	while(getline(infile,line))
	{

		if(line_number==1)
			setCityFile(line);  //put into m_city_file;
		else
			setAircraftFile((char*)line.c_str()); //put into m_aircraft_file;

		line_number++;		
		
	}
	infile.close();
}


}

string Simulation :: getCityFile(){
	return m_CityFileName;
}
string Simulation :: getFlightFile(){
	return m_FlightFileName;
}
void Simulation :: setCityFile(string cityFile){
	m_CityFileName = new char[20];
	strcpy(m_CityFileName, (char*)cityFile.c_str()); //conver the string to char and copy
}
void Simulation :: setAircraftFile(string aircraftFile){
	m_FlightFileName = new char[20];
	strcpy(m_FlightFileName, (char*)aircraftFile.c_str()); //convert the string to char and copy

}

int  Simulation :: getCityCoutn(){
	return m_CityCount;
}
int  Simulation :: getFlightCountBusiness() {
	return m_flightCount_Business;
}

int Simulation :: getFlightCountPassenger() {
	return m_flightCount_Passenger;

}

int Simulation :: getFlightCountSingle(){
	return m_flightCount_Single;
}

int Simulation :: getFlightNumber() {
	return m_flightNum;
}

int Simulation ::  getCurrentHour()
{
	return m_currentHour;
}
int Simulation ::  getCurrentminute()
{
	return m_currentMinute;
}
void Simulation :: setCurrentHour(int ch)
{
	m_currentHour = ch;
}
void Simulation :: setCurrentMinute(int min)
{
	m_currentMinute = min;
}

int    Simulation :: getRunSpeed()  //ask the user to input the timer for simulation
{
	return m_runSpeed;
}

char Simulation :: getCitySymobl()
{
	return **m_symbol;
}
void Simulation :: setCitySymbol(char  *symbol)
{
	strcpy(*m_symbol, symbol); 
}
double Simulation :: getDistanceTable()
{
	return *m_distanceTable;
}
void Simulation :: setDistanceTable(double distance)
{
	*m_distanceTable = distance;
}
//int Simulation :: getNUmCity()
//{
//	return numCity;
//}
//void Simulation :: setNumCity()
//	{
//		numCity = cdp.getCityCount();
//	}
//
//int  Simulation :: getnumFlight()
//{
//	return numFlight;
//}
//void Simulation ::  setNumFlight()
//{
//
//	numFlight = fdp.getFlightCount();
//}


vector<City> Simulation:: getListOfCities()
{
	return listofCities;
}

vector<Flight> Simulation:: getListOfFlight()
{
	return listOfFlight;
}

vector<Aircraft> Simulation :: getListOfAircraft()
{
	return listofAircraft;
}


City Simulation::findDepCityInfo(Flight f)
		{
			for(int i =0; i < m_CityCount; i++)
			{
				if(strcmp(listofCities[i].getSymbol(),f.get_DepartureCity()) == 0)
				{
					return listofCities[i];
				}
			}
		}
City Simulation::findArrCityInfo(Flight f)
		{
			for(int i =0; i < m_CityCount; i++)
			{
				if(strcmp(listofCities[i].getSymbol(), f.get_ArrivalCity()) == 0)
				{
					return listofCities[i];
				}
			}
		}
Aircraft Simulation::findAirCraftInfo(Flight f)
		{
			for(int i =0; i < m_CityCount; i++)
			{
				if(strcmp(listofAircraft[i].getPlaneMake(),f.get_Aircraft_Type()) == 0)
				{
					return listofAircraft[i];
				}
			}
		}

//This function is used to find the index of the city symbol
int Simulation ::  findCtySymbolIndex(const char *dep_citySym)
{
	//cdp.getCitySymbolsArray(&m_symbol);
	int numSymbol = m_CityCount;
	int depIndex = 0;

		for(int i = 0; i < numSymbol; i++)
	{
		//if("HSV" = m_symbol[i]) // == "HSV";
		if(strcmp(m_symbol[i], dep_citySym)==0)
			return i;		
	}
	

}

//Function for updating the time
void Simulation ::  updateCurrentTime(int startHr, int startMin)
{
		m_currentMinute += 5;
	//m_currentHour = startHr;
	//m_currentMinute = startMin;
	
	if(m_currentMinute == 60)
	{
		++m_currentHour;
		m_currentMinute = 0;
	}
}

void Simulation :: initializatation() {
	FlightDataParser *fdp = FlightDataParser :: getInstance();
	CityDataParser *cdp = CityDataParser :: getInstance();
	fdp->InitFlightData(m_FlightFileName);
	cdp->InitCityData(m_CityFileName);
	m_CityCount = cdp->getCityCount();
	m_flightCount_Business = fdp->getAircraftCount(BUSINESSJET);
	m_flightCount_Passenger = fdp->getAircraftCount(PASSENGERJET);
	m_flightCount_Single = fdp->getAircraftCount(SINGLEENGINE);
	m_flightNum = fdp->getFlightCount();

	// get the simulation start time from the file 

	fdp->getStartTime(&m_start_hour, &m_start_minute);
	m_currentHour = m_start_hour;
	m_currentMinute = m_start_minute;
	
	
	//setNumCity();  //called this function to set the number of city
	//setNumFlight(); // call this function to set the flight number

	
	int citycount = m_CityCount;
	while(citycount != 0)
	{
		City city;
		city.fillCityData(cdp);
		listofCities.push_back(city);
		citycount --;
	}
	
	while (m_flightCount_Business != 0) {
		BusinessJet bus;
		bus.createAircraft();
		listofAircraft.push_back(bus);

		
		m_flightCount_Business --;	
	}
	while(m_flightCount_Passenger != 0) {
		PassengerJet pass;
		pass.createAircraft();
		listofAircraft.push_back(pass);
		m_flightCount_Passenger --;
		
	}
	while(m_flightCount_Single != 0) {
		SingleEnginePlane single;
		single.createAircraft();
		listofAircraft.push_back(single);
		m_flightCount_Single --;
	}

	
	//City symbol store in the double array

	cdp->getCitySymbolsArray(&m_symbol); 
	//The below commented code is to check if it prints the city symbol
		/*int index = 0;
	while (m_symbol[index] != NULL)
	{
	cout << m_symbol[index] << "\n";
		index ++;
	}*/
	cdp->getDistTable(&m_distanceTable);
	
	for(int i=0; i< m_flightNum; i++)
	{		
		Flight f ;
		f.fillFlightData(fdp);
		int deptCityindx = findCtySymbolIndex(f.get_DepartureCity());
		int arriCityIndx = findCtySymbolIndex(f.get_ArrivalCity());
		double dist = m_distanceTable[(deptCityindx * m_CityCount) + arriCityIndx];
		f.set_Distance(dist);
		City depCity = findDepCityInfo(f);
		City arrCity = findArrCityInfo(f);
		Aircraft ac = findAirCraftInfo(f);
		f.setDepCityInfo(depCity);
		f.setArrCityInfo(arrCity);
		f.setAirCraftInfo(ac);
		f.setEstimated_Trip_Time_hour(); //we have sotred flags inside this function in flight.cpp
		listOfFlight.push_back(f);
	
	}
		
}


void Simulation :: printTest()
{
	cout<<m_CityFileName<<endl;
	cout<<m_FlightFileName<<endl;
	cout<<m_CityCount<<endl;
	cout<<m_flightCount_Business<<endl;
	cout<<m_flightCount_Passenger<<endl;
	cout<<m_flightCount_Single<<endl;
	cout<<m_flightNum<<endl;
	
	
	
}

void Simulation :: RunSimulation(){
	
{ 

	readFile(); //call this function to read file from the user input 
	initializatation(); //    //This function initialized the data from the data parser
	cout<<"\nAt what speed do you want to run Simulation. Ex: (1x, 2x, 3x ).\n";
	cout<<"\tPlease inter 1, 2, or 3 for speed\n";
	cin>>m_runSpeed;
	cout <<"\n*************Simulation Starting at : "<< m_start_hour << ": " << m_start_minute << "*********\n\n";
	
	struct _timeb   tStruct;
    double   thisTime;
    double   outputTime;
    bool    done = false;  // while loop flag


struct _timeb
     {
     int   dstflag;   // holds a non-zero value if daylight saving time is in effect
     long  millitm;   // time in milliseconds since the last one-second hack
     long  time;      // time in seconds since 00:00:00 1/1/1970
     long  timezone;  // difference in minutes moving west from UTC
     };

 _ftime(&tStruct);	// Get start time
    thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
	outputTime = thisTime + 5.0/m_runSpeed; // Set next 5 second interval time
	
	 int counter = 0; 
    while(!done)     // Start an eternal loop
    {
	
        _ftime(&tStruct);    // Get the current time
        thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
        // Check for 5 second interval to print status to screen
        if(thisTime >= outputTime)
        {
        // Call functions to perform actions at 5 second intervals
		outputTime += 5.0/m_runSpeed; // Set time for next 5 second interval
		updateCurrentTime(m_start_hour,m_start_minute);

		print();  //This function prints the current time of the simulation 
		
		//update the flight 
		for(int i = 0; i< m_flightNum ; i++)
		{
			listOfFlight[i].updateFlight(m_currentHour, m_currentMinute);			
		}
				
        }
		
		if( m_currentHour== 15 && m_currentMinute == 55)
			break;        
   }   
}
}


void Simulation ::  print() // print function to check the files in m_city and m_air
{
	cout<<"=================================================================\n";
	cout<<"Flight Simulation Report on all Flight Enroutues.\n";
	cout<<"=================================================\n";
	cout<<"Current Clock: "<<getCurrentHour()<<":"<<getCurrentminute()<<endl;
	cout<<"=================================================================\n\n";

}
