#include "Bmw.h"

Bmw::Bmw()
{
    fuelCapacity = 200;
    fuelConsumption = 2;
    averageSpeed = 50;
    char masina[] = "Bmw";
    name = new char[strlen(masina) + 1];
    strcpy(name, masina);
    name[strlen(masina)] = '\0';
}
Bmw::~Bmw()
{
    delete name;
}

float Bmw::GetFuelCapacity() const
{
    return this->fuelCapacity;
}

float Bmw::GetFuelConsumption() const
{
    return this->fuelConsumption;
}

float Bmw::GetSpeed(Weather conditions) const
{
    if (conditions == Snow)
        return this->averageSpeed - 10;
    if (conditions == Sunny)
        return this->averageSpeed + 10;
    return this->averageSpeed;
}

char* Bmw::GetName() const
{
    return this->name;
}

float Bmw::GetTime(float length, Weather current_conditions) const
{
    return length / GetSpeed(current_conditions);
}