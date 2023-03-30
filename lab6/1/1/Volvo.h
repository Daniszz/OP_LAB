#pragma once
#include "Car.h"

class Volvo : public Car
{
   
public:
    Volvo();
    ~Volvo();

    float GetFuelCapacity() const override;
    float GetFuelConsumption() const override;
    float GetSpeed(Weather conditions) const override;
    char* GetName() const override;
    float GetTime(float length, Weather current_conditions) const override;
};