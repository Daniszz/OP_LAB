#include "RangeRover.h"

RangeRover::RangeRover()
{
    fuelCapacity = 250;
    fuelConsumption = 1.5;
    averageSpeed = 70;
    char masina[] = "RangeRover";
    name = new char[strlen(masina) + 1];
    strcpy(name, masina);
    name[strlen(masina)] = '\0';
}
RangeRover::~RangeRover()
{
    delete name;
}

float RangeRover::GetFuelCapacity() const
{
    return this->fuelCapacity;
}

float RangeRover::GetFuelConsumption() const
{
    return this->fuelConsumption;
}

float RangeRover::GetSpeed(Weather conditions) const
{
    if (conditions == Snow)
        return this->averageSpeed - 10;
    if (conditions == Sunny)
        return this->averageSpeed + 10;
    return this->averageSpeed;
}

char* RangeRover::GetName() const
{
    return this->name;
}

float RangeRover::GetTime(float length, Weather current_conditions) const
{
    return length / GetSpeed(current_conditions);
}