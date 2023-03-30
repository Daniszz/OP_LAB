#include "Seat.h"

Seat::Seat()
{
    fuelCapacity = 250;
    fuelConsumption = 1.5;
    averageSpeed = 70;
    char masina[] = "Seat";
    name = new char[strlen(masina) + 1];
    strcpy(name, masina);
    name[strlen(masina)] = '\0';
}
Seat::~Seat()
{
    delete name;
}

float Seat::GetFuelCapacity() const
{
    return this->fuelCapacity;
}

float Seat::GetFuelConsumption() const
{
    return this->fuelConsumption;
}

float Seat::GetSpeed(Weather conditions) const
{
    if (conditions == Snow)
        return this->averageSpeed - 10;
    if (conditions == Sunny)
        return this->averageSpeed + 10;
    return this->averageSpeed;
}

char* Seat::GetName() const
{
    return this->name;
}

float Seat::GetTime(float length, Weather current_conditions) const
{
    return length / GetSpeed(current_conditions);
}