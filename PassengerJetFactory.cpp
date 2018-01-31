//PassengerJetFactory.cpp 
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/27/2017
//This program is entirely of my work

#include"PassengerJetFactory.h"
#include "PassengerJet.h"


PassengerJetFactory :: PassengerJetFactory()
{

}
PassengerJetFactory :: ~PassengerJetFactory()
{

}
int PassengerJetFactory:: getInstanceNumber()
{
	return instanceNumber;
}

PassengerJetFactory * PassengerJetFactory :: getInstance()
{
	static int counter=1;
	static PassengerJetFactory *theInstance = NULL;
	if(theInstance == NULL)
	{
		theInstance = new PassengerJetFactory();
		theInstance->instanceNumber = counter;
	}
	return theInstance;
}

Aircraft *PassengerJetFactory  :: getAircraft()
{
	return new PassengerJet();
}