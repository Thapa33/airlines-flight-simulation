//SingleEnginePlaneFactory.cpp 
//Name: Sher Thapa
//Programming assignment 2 of aircraftSimulation
//Date: 11/27/2017
//This program is entirely of my work

#include"SingleEnginePlaneFactory.h"

SingleEnginePlaneFactory :: SingleEnginePlaneFactory()
{

}

SingleEnginePlaneFactory :: ~SingleEnginePlaneFactory()
{

}
int SingleEnginePlaneFactory ::  getInstanceNUmber()
{
	return instanceNumber;
}
SingleEnginePlaneFactory * SingleEnginePlaneFactory :: getInstance()
{
	static int counter = 1;
	static SingleEnginePlaneFactory *theInstance = NULL;
	if(theInstance == NULL)
	{
		theInstance = new SingleEnginePlaneFactory();
		theInstance->instanceNumber = counter;
	}
	 return theInstance;
}

Aircraft * SingleEnginePlaneFactory:: getAircraft()
{
	return new SingleEnginePlane();
}