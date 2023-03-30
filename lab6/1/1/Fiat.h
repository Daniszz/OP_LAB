#pragma once
#include "Car.h"

class Fiat : public Car
{

public:
    Fiat();
    ~Fiat();

    float GetFuelCapacity() const override;
    float GetFuelConsumption() const override;
    float GetSpeed(Weather conditions) const override;
    char* GetName() const override;
    float GetTime(float length, Weather current_conditions) const override;
};
