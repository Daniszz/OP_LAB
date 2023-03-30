#pragma once
#include "Car.h"
#include "Volvo.h"
class Circuit
{
    Car* cars[10];
    float length;
    Weather weather;
    int count;
    struct {
        float scor;
        char* nume;
    }ranks[10];
public:
    Circuit();
    ~Circuit() {};

    void SetLength(float new_length);
    void SetWeather(Weather new_weather);
    void AddCar(Car* x);
    
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};