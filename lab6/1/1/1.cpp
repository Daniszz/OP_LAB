// 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"
#include "Circuit.h"
#include "Bmw.h"
#include "Volvo.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"
using namespace std;
int main()

{

	Circuit c;

	c.SetLength(100);

	c.SetWeather(Weather::Rain);
	
		c.AddCar(new Volvo());
		c.AddCar(new Fiat());
		c.AddCar(new RangeRover());


	c.AddCar(new Bmw());

	c.AddCar(new Seat());
	c.Race();
	c.ShowFinalRanks();
	c.ShowWhoDidNotFinish();

	return 0;

}