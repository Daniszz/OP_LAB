#include "Fiat.h"

Fiat::Fiat()
{
    fuelCapacity = 250;
    fuelConsumption = 1.5;
    averageSpeed = 70;
    char masina[] = "Fiat";
    name = new char[strlen(masina) + 1];
    strcpy(name, masina);
    name[strlen(masina)] = '\0';
}
Fiat::~Fiat()
{
    delete name;
}

float Fiat::GetFuelCapacity() const
{
    return this->fuelCapacity;
}

float Fiat::GetFuelConsumption() const
{
    return this->fuelConsumption;
}

float Fiat::GetSpeed(Weather conditions) const
{
    if (conditions == Snow)
        return this->averageSpeed - 10;
    if (conditions == Sunny)
        return this->averageSpeed + 10;
    return this->averageSpeed;
}

char* Fiat::GetName() const
{
    return this->name;
}

float Fiat::GetTime(float length, Weather current_conditions) const
{
    return length / GetSpeed(current_conditions);
}