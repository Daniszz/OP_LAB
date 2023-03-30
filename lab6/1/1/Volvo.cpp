#include "Volvo.h"

Volvo::Volvo()
{
    fuelCapacity = 400;
    fuelConsumption = 3;
    averageSpeed = 80;
    char masina[] = "Volvo";
    name = new char[strlen(masina) + 1];
    strcpy(name, masina);
    name[strlen(masina)] = '\0';
}
Volvo::~Volvo()
{
    delete name;
}

float Volvo::GetFuelCapacity() const
{
    return this->fuelCapacity;
}

float Volvo::GetFuelConsumption() const
{
    return this->fuelConsumption;
}

float Volvo::GetSpeed(Weather conditions) const
{
    if (conditions == Snow)
        return this->averageSpeed - 10;
    if (conditions == Sunny)
        return this->averageSpeed + 10;
    return this->averageSpeed;
}

char* Volvo::GetName() const
{
    return this->name;
}

float Volvo::GetTime(float length, Weather current_conditions) const
{
    return length / GetSpeed(current_conditions);
}