
//Flight.cpp 
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/27/2017
//This program is entirely of my work
#include"Flight.h"
//#include"Simulation.h"

Flight :: Flight()  //default constructor
{

}

Flight :: Flight(char company, char aircraftType, int flightNumber, char departureCity, int departHour,
		int departMinute, char arrivalCity, double Distance)
{
		//:m_AirlineCompany(company), m_aircraftType(aircraftType), m_flightNumber(flightNumber),
		//m_departure_City(departureCity), m_depart_Hour(departHour), m_depart_minute(departMinute),
		//m_arrival_City(arrivalCity), m_distance(Distance)
}


Flight :: ~Flight()
{
}

//void Flight :: getCurrentTime()  //need to fix the implemantation
//{
//	time.getStartTime(&m_currentHour, &m_currentMins); //here we need to init flightDataparser to get this function
//}
const char *Flight :: get_AirlineCompany() const
{
	return m_AirlineCompany;
}

 const char *Flight ::  get_Aircraft_Type() const
 {
	 return M_aircraftType;
 }
int    Flight :: get_FlightNumber() const
{
	return m_flightNumber;
}
const char *Flight :: get_DepartureCity() const
{
	return m_departure_City;
}
int    Flight ::  get_DepartureHour() const
{
	return m_depart_Hour;
}
int    Flight :: get_DepartureMinute() const
{
	return m_depart_minute;
}
const char *Flight :: get_ArrivalCity() const
{
	return m_arrival_City;
}
double Flight :: get_Distance() const
{
	return m_distance;
}
void Flight :: set_AirlineCompany(char *company)
{
	strcpy(m_AirlineCompany,company);
}


int Flight ::getCurrentSpeed()
{
	return m_currentSpeed;
}


void Flight :: setCurrentSpeed()
{
	m_currentSpeed = aircraft.getCruise_Speed();
}

void Flight :: setAircraftType(char * aircraftType)
{
	strcpy(M_aircraftType,aircraftType);
}

void Flight :: set_FlightNUmber(int flightNumber)
{
	m_flightNumber = flightNumber;
}
void Flight :: set_DepartureCity(char * DepartureCity)
{
	strcpy(m_departure_City, DepartureCity);
}
void Flight :: set_DepartureHour(int hour)
{
	m_depart_Hour = hour;
}
void Flight :: set_departureMinute(int minute)
{
	m_depart_minute = minute;
}
void Flight :: set_ArrivalCity(char * ArrivalCity)
{
	strcpy(m_arrival_City , ArrivalCity);
}
void Flight :: set_Distance(double Distance)
{
	m_distance = Distance;
}

void Flight:: fillFlightData(FlightDataParser * fdp)
{
	fdp->getFlightData(m_AirlineCompany,M_aircraftType,&m_flightNumber,m_departure_City,&m_depart_Hour,&m_depart_minute,m_arrival_City);
		
}
double Flight :: getestimated_Trip_Time_hour()
{
	return m_estimated_Trip_Time;
}
int Flight :: getcurrent_latitude()
{
	return m_current_latitude;
}
int Flight :: getcurrent_longitude()
{
	return m_current_longitude;
}
int Flight :: getEstimated_arrival_hour()
{
	return m_estimated_arrival_hour;
}
int Flight :: getEstimated_arrival_mins()
{
	return m_estimated_arrival_mins;
}
double Flight :: getDistanceFrom_departure()
{
	return m_distanceFrom_departure;
}
double Flight :: getDistanceTo_arrival()
{
	return m_distanceTo_arrival;
}
double Flight :: getCurrent_Altitude()
{
	return m_current_Altitude;
}
double Flight :: getTime_elapsed_in_Hour()
{
	return m_time_elapsed_in_Hour;
}

//This function is used to set the estimated trip time to the desgnated city
//by gettting the distance and dividing with the speed per hour 
//in that way we get the time in hour and we divide to get hour and mod to get minute and set to variable
void   Flight :: setEstimated_Trip_Time_hour()

{
	//both distance and cruise speed is miles in hour 
	//int d = get_Distance(); 
	descendingMinute = 0;
	m_estimated_Trip_Time  =   get_Distance()/aircraft.getCruise_Speed();
	//return m_estimated_Trip_Time;
	
	m_estimated_arrival_hour = 0;
	m_estimated_arrival_mins = 0;
	int hour = ((int)(m_estimated_Trip_Time * 100))/100 ;
	int min = ((int)(m_estimated_Trip_Time * 100) % 100)/100.0 * 60 ;
	m_estimated_arrival_hour =   m_depart_Hour + hour;
	m_estimated_arrival_mins = m_depart_minute + min;
	if( m_estimated_arrival_mins >= 60)
	{
		++m_estimated_arrival_hour;
		m_estimated_arrival_mins  = 0;
	}
	
		flightNumber = true;  //for all the flights to print departure flight twice
	takeFlight = false;  //for all the flights to to prevent printing arrival before departure
	//This variable is to calculate the time to reach to its altitude and push into the vector of flight class.
	timeToReachMaximumHeight = aircraft.getCruise_Altutude() * 1.0/ aircraft.getRateOfClimb();  
}
void  Flight :: setCurrent_latitude()
{
	//current latitude = depCityLati + ( destiLatitu - depCityLati) * ( elapsed time / tripTime)
	m_current_latitude = dep_city.getLatitude() + (arr_city.getLatitude() -
		dep_city.getLatitude()) * m_time_elapsed_in_Hour/m_estimated_Trip_Time;
}
void  Flight :: setCurrent_longitude()
{
	//current longitude = deparCitylong + ( DestinationCityLong - departCitylong) * (elapsedTIme /TripTime);
	m_current_longitude = dep_city.getLongitude() + (arr_city.getLongitude() -
		dep_city.getLongitude()) * m_time_elapsed_in_Hour/m_estimated_Trip_Time;

}
//This function sets the distance from the deparute 
void Flight :: setDistanceFrom_departure()
{
	m_distanceFrom_departure = (m_time_elapsed_in_Hour / m_estimated_Trip_Time) * (double)(m_distance);
}
//This function sets the distance to the arrival city by subtractin distance 
//travelled form the total distance between the cities.
void Flight :: setDistanceTo_arrival()
{
	m_distanceTo_arrival = (double)(m_distance) - m_distanceFrom_departure;

}

int Flight :: getCurrentTimeElapsedInHour() //This function is to get the time to reach the current altitude
{
	return m_time_elapsed_in_Hour;
}

double Flight :: getTimeToReachMaxHeight()
{
	return timeToReachMaximumHeight;
}

//This function will be used to set the altitude of the aricraft
//here we will call the time elasped from the departure time until now and we will multiply with the 
//rate of climb of the aircraft to get the altitude.
//If the current altitude reaches the cruise altitude the we will set the current altitude to cruise altitude
//we calculate the time to reach the cruise altitude and when the time to reach the altitude is less than the 
//time to reach the destination then we will deduct the altitude of the plane.
void Flight :: setCurrent_Altitude()
{
	int minute = 60 * getTime_elapsed_in_Hour(); // need to conver to minute 

	m_current_Altitude = minute * aircraft.getRateOfClimb();
	
	/*double remtime = (getestimated_trip_time_hour() - gettime_elapsed_in_hour() ) * 60;

	if(timetoreachmaximumheight > remtime)
	{
		m_current_altitude -= remtime * aircraft.getrateofclimb();
		descendingminute += 5;
		
	}*/
	if(m_current_Altitude >= aircraft.getCruise_Altutude()) //stop there 
	{
		m_current_Altitude = aircraft.getCruise_Altutude();
	}
	
	double estimateRemTime = (getestimated_Trip_Time_hour() - getTime_elapsed_in_Hour() ) * 60;
	if( estimateRemTime < timeToReachMaximumHeight )
	{
		descendingMinute += 5;
		m_current_Altitude = aircraft.getCruise_Altutude() - descendingMinute * aircraft.getRateOfClimb();
		
	}
}
//This function will be used to calculate the elapsed time in hour
//We will get the departure hour and minute and compare the departure time to the current time
//we will subtract the the departure time form the current time and get the time elasped
void Flight :: setTime_elapsed_in_Hour(int currhr,int currmin)
{
	int  hour = 0.0;
	int minute = 0.0;
	 hour = get_DepartureHour();
	 minute = get_DepartureMinute();

	 if(hour == currhr && currmin >= minute)
		 m_time_elapsed_in_Hour = ((double)(currmin - minute)) / 60.0; // to conver to hour / 60	 
	 if(currhr > hour && currmin < minute)
		 m_time_elapsed_in_Hour = (currhr-1 - hour) + (currmin+60 - minute)/60.0; // to conver to hour / 60
	 if(currhr> hour && currmin > minute)
		 m_time_elapsed_in_Hour = (currhr- hour) + (currmin - minute)/60.0; // to conver to hour / 60
	
}
//since we cannot call the simulation here so we will pass the city into the function and
//call the function in simulation to get the object of the city and aircraft
//and we will push the info into the vector of flight with respective flight and city info to the flight
	void Flight :: setDepCityInfo(City depCity)
	{
		dep_city = depCity;
	}
	void Flight :: setArrCityInfo(City arrCity)
	{
		arr_city = arrCity;

	}
	void Flight :: setAirCraftInfo(Aircraft ac)
	{
		aircraft = ac;
	}

//This function will compare the current time that is passed from the simulation as a parameter 
// and the flight departure and arrival time
// if the condition met it will return the value and this value will be used to 
// print the appropriate report on the flight
int Flight:: compareFlightTime(int curHour, int curMin, int depHour, int depMin)
{
	if(curHour < depHour)
		return -1;
	else if(curHour > depHour)
		return 1;
	//else
	//{
		else if(curMin < depMin)
			return -1;
		else if(curMin > depMin)
			return 1;
		else
			return 0;
	//}
}

//This function is for updating the flight and call the print report when its flight time for departure or arrival
//we pass the current hour and minute as an parameter 
//This function will be called on the simulation and the current time will be comapred with the time of the flight 
//to departure of land. If the the time matches it will call the appropriate function to print message.
//This function also sets the flag so the flight will not be departed or landed twice. or the flight which has not been 
//departed will also not be landed.
void Flight ::  updateFlight(int curhour, int curminute)
	{		
		int comparetimeresult = compareFlightTime(curhour, curminute, get_DepartureHour(), get_DepartureMinute());
		int comparetimeresultarr = compareFlightTime(curhour, curminute, getEstimated_arrival_hour(),getEstimated_arrival_mins());

		if(comparetimeresult == 1 || comparetimeresult == 0)
		{
			if (flightNumber == true)  //all the filght are set false in initialization set true when depart
			{
			printDepartureFlight(curhour,curminute);
			flightNumber = false;  // set it false again once it departs 
			takeFlight = true;   // all the flight are set false in initialization. once depart set it to true and only true flag can show the arrival report 
			setCurrentSpeed();
			m_current_Altitude = 0;
			m_distance --;
			}
		}

		
		 if(comparetimeresultarr == 1 || comparetimeresultarr == 0)
		{
			
			if(takeFlight == true) {  // if only flight is true then print arrival once it is false don't print

			printArrivalFlight(curhour,curminute);
			takeFlight = false;  // once the flight lands set it to false again
			m_currentSpeed = 0;
			m_current_Altitude = 0;
			}
		}
		
		 if(comparetimeresult == 1  && comparetimeresultarr == -1)
			{
			setTime_elapsed_in_Hour(curhour, curminute);
			setDistanceFrom_departure();
			setDistanceTo_arrival();
		    setCurrent_Altitude();
		    setCurrent_latitude();
			setCurrent_longitude();
			
			printCurrentStatus(curhour, curminute);
			}		
	}
	
void Flight ::  printDepartureFlight(int currhr, int currmin)
	{
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout<<"Now Departing: "<<get_AirlineCompany()<<" Flight "<< get_FlightNumber() <<", " << get_Aircraft_Type() <<endl;
		cout<<"\tFrom "<< dep_city.getCity()<<", " << dep_city.getState()<< endl;
		cout<<"\tenroute to "<< arr_city.getCity() <<", "<<arr_city.getState()<< endl;
		cout <<"Estimated time of Arrival: "<<getEstimated_arrival_hour() <<":"<<getEstimated_arrival_mins() <<endl;
		cout<<"Current clock time: " <<currhr <<":"<<currmin << endl;
		cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
		
	}
void Flight :: printArrivalFlight(int currhr, int currmin)
{
	    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout<<"Now Arriving: "<<get_AirlineCompany()<<" Flight "<< get_FlightNumber() <<", " << get_Aircraft_Type() <<endl;
		cout<<"\tAt "<< arr_city.getCity() <<", "<< arr_city.getState() <<endl;
		cout<<"\t\tFrom "<< dep_city.getCity() <<", "<< dep_city.getState() <<endl;
		cout<<"Current clock time: " <<currhr <<":"<<currmin << endl;
		cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
}

void Flight :: printCurrentStatus(int curhr, int curmin)
{
	cout <<"Current ClockTime: "<<curhr <<": "<< curmin<<endl<<endl;
	cout<<get_AirlineCompany() <<" FLight "<<get_FlightNumber() <<" - "<<get_Aircraft_Type() <<endl;
	cout<<"Departed: "<<get_DepartureCity()<<"( "<< dep_city.getLatitude()<<","<<dep_city.getLongitude()<<" ) at " <<get_DepartureHour()<<": "<<get_DepartureMinute() <<endl;
	cout<<"Arrives: "<<get_ArrivalCity() <<"( "<< arr_city.getLatitude()<<","<<arr_city.getLongitude()<<" ) at " <<getEstimated_arrival_hour()<<":"<<getEstimated_arrival_mins()<<endl;
	cout <<"Current Location : "<<"( "<<getcurrent_latitude()<< ","<<getcurrent_longitude() <<")" <<endl;
	cout <<getDistanceFrom_departure() <<" from "<<get_DepartureCity() << " and "<<getDistanceTo_arrival() <<" To "<<get_ArrivalCity()<<endl;
	cout<<"Current Speed : "<<getCurrentSpeed() << endl;
	cout<<"Current Altitude: "<<getCurrent_Altitude()<<endl;
}