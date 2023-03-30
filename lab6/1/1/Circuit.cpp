#include "Circuit.h"
using namespace std;
Circuit::Circuit()
{
   
    count = 0;
    length = 0;
    this->weather = Unknown;
    for (int i = 0; i < 10; i++)
        ranks[i].scor = -1;
}
void Circuit::SetLength(float new_lenght)
{
    this->length = new_lenght;
  
}

void Circuit::SetWeather(Weather new_weather)
{
    this->weather = new_weather;
    
}
void Circuit::AddCar(Car* x)
{
   
    if (count < 10)
    {
        cars[count++] = x;
 
  
    }
 
}

void Circuit::Race()
{
    for (int i = 0; i < count; i++)
    {   if(cars[i]->GetFuelCapacity()>length * cars[i]->GetFuelConsumption())
        ranks[i].scor = cars[i]->GetTime(length, weather);
        ranks[i].nume = cars[i]->GetName();
        
    }
}
void Circuit::ShowFinalRanks()
{
   for(int i=0;i<count-1;i++)
       for(int j=i+1;j<count;j++)
           if (ranks[i].scor > ranks[j].scor)
           {
               
               swap(ranks[i], ranks[j]);
           }
   for (int i = 0;i < count;i++)
       if (ranks[i].scor != -1)
           cout << ranks[i].nume << endl;
          
}
void Circuit::ShowWhoDidNotFinish()
{
    for (int i = 0;i < count;i++)
        if (ranks[i].scor == -1)
            cout << ranks[i].nume << " nu a terminat" << endl;
           
            }