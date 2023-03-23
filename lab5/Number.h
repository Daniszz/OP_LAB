#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cstring>
#include <iostream>
class Number

{
    // add data members
  private:
    char* value;
    int base=10;
    static int ConvertTo10(const char* value, int base);
    static char* ConvertFrom10(int value, int base);

  public:
    Number(const char* value, int base); // where base is between 2 and 16
    Number(int value);
    Number(const char* value);
    ~Number();
    // add operators and copy/move constructor
    char& operator[](int);
    friend Number operator+(Number obj1, Number obj2);
    friend Number operator-(Number obj1, Number obj2);
    int operator>(Number obj2);
    int operator>=(Number obj2);
    int operator<(Number obj2);
    int operator<=(Number obj2);
    int operator==(Number obj2);
    void operator+=(Number obj2);

    void operator--();
    void operator--(int);
    void operator=(int nr);
    void operator=(const char* s);
    void operator=(Number obj2);

    void SwitchBase(int newBase);

    void Print();

    int GetDigitsCount(); // returns the number of digits for the current number
    int GetBase();        // returns the current base
};