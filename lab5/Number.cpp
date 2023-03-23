#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
#include <cstring>

int Number::ConvertTo10(const char* value, int base)
{
    int power = 1;
    int v = 0;
    for (int i = strlen(value) - 1; i >= 0; i--)
    {
        int c;
        if (value[i] >= 'A' && value[i] <= 'F')
            c = value[i] - 'A' + 10;
        else
            c = value[i] - '0';
        v = v + c * power;
        power = power * base;
    }
    return v;
}

char* Number::ConvertFrom10(int value, int base)
{
    int length = 0, v = value;
    while (v != 0)
    {
        printf("%d %d", v, base);
        v = v / base;
        length++;
    }
    int l = length;
    char* c = new char[length + 1];
    length--;
    do
    {
        int a = (value % base);
        if (a >= 10)
            c[length] = a + 'A' - 10;
        else
            c[length] = a + '0';
        value = value / base;
        length--;
    } while (length >= 0);
    c[l] = '\0';
    return c;
}

Number::Number(const char* value, int base)
{
    this->base = base;
    this->value = new char[100];
    strcpy(this->value, value);
}
Number::Number(int value)
{
    this->base = 10;
    strcpy(this->value, ConvertFrom10(value, this->base));
}

Number::Number(const char* value)
{
    strcpy(this->value, value);
}

Number::~Number()
{
    delete this->value;
}

char& Number::operator[](int index)
{
    return this->value[index];
}
Number operator+(Number obj1, Number obj2)
{
    int result = Number::ConvertTo10(obj1.value, obj1.base) + Number::ConvertTo10(obj2.value, obj2.base);
    return Number(Number::ConvertFrom10(result, obj1.base));
}

Number operator-(Number obj1, Number obj2)
{
    int result = Number::ConvertTo10(obj1.value, obj1.base) - Number::ConvertTo10(obj2.value, obj2.base);
    return Number(Number::ConvertFrom10(result, obj1.base));
}

int Number::operator>(Number obj2)
{
    return Number::ConvertTo10(value, base) > Number::ConvertTo10(obj2.value, obj2.base);
}

int Number::operator>=(Number obj2)
{
    return Number::ConvertTo10(value, base) >= Number::ConvertTo10(obj2.value, obj2.base);
}

int Number::operator<(Number obj2)
{
    return Number::ConvertTo10(value, base) < Number::ConvertTo10(obj2.value, obj2.base);
}

int Number::operator<=(Number obj2)
{
    return Number::ConvertTo10(value, base) <= Number::ConvertTo10(obj2.value, obj2.base);
}

int Number::operator==(Number obj2)
{
    return strcmp(value, obj2.value) == 0;
}

void Number::operator+=(Number obj2)
{
    int result = Number::ConvertTo10(value, base) + Number::ConvertTo10(obj2.value, obj2.base);
    char* new_value = Number::ConvertFrom10(result, base);
    delete[] value;
    value = new_value;
}




void Number::operator--()
{
    int result = Number::ConvertTo10(value, base) - 1;
    delete[] value;
    value = Number::ConvertFrom10(result, base);
}

void Number::operator--(int)
{
    int result = Number::ConvertTo10(value, base) - 1;
    delete[] value;
    value = Number::ConvertFrom10(result, base);
}

void Number::operator=(int nr)
{
    char* new_value = Number::ConvertFrom10(nr, base);
    delete[] value;
    value = new_value;
}

void Number::operator=(const char* s)
{
    delete[] value;
    value = new char[strlen(s) + 1];
    strcpy(value, s);
}

void Number::operator=(Number obj2)
{
    delete[] value;
    value = new char[strlen(obj2.value) + 1];
    strcpy(value, obj2.value);
}
void Number::Print()
{
    std::cout << this->value << '\n';
}

int Number::GetDigitsCount()
{
    int length = strlen(this->value);
    if (value[0] == '-')
        return length - 1;
    return length;
}
int Number::GetBase()
{
    return this->base;
}