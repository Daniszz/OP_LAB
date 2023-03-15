#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <cstdarg>
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

Sort::Sort(int nr_elements, int min, int max) : nr_of_elem(nr_elements)
{
    srand(time(NULL));
    this->v = new int[nr_elements];
    for (int i = 0;i < nr_elements;i++)
    {
        v[i] = rand() % (max - min) + min;
    }
}

Sort::Sort(const Sort& other) : Sort(other.v, other.nr_of_elem)
{

}

Sort::Sort(int a[], int nr_elements) : nr_of_elem(nr_elements)
{
    this->v = new int[nr_elements];
    for (int i = 0; i < nr_elements; i++)
        v[i] = a[i];
}

Sort::Sort(int count, ...) : nr_of_elem(count)
{
    this->v = new int[count];
    va_list arg;
    va_start(arg, count);
    for (int i = 0;i < count;i++)
        v[i] = va_arg(arg, int);
    va_end(arg);
}

Sort::Sort(char* string)
{
    int i = 0, n = 0;
    while (string[i] != '\0')
    {
        if (string[i] == ',')
            n++;
        i++;
    }
    n++;
    this->v = new int[n];
    i = 0;
    char* p = strtok(string, ",");
    while (p != nullptr)
    {
        int nr = 0, j = 0;
        while (p[j] != '\0')
        {
            nr = nr * 10 + (p[j] - 48);
            j++;
        }
        v[i++] = nr;
        p = strtok(NULL, ",");
    }
    this->nr_of_elem = i;
}

Sort::~Sort()
{
    delete this->v;
}
void Sort::InsertSort(bool ascendent)
{
    for (int i = 1; i < nr_of_elem; i++)
    {
        int j = i - 1;
        int temp = v[i];
        if (ascendent == true)
        {
            while (j >= 0 && v[j] > temp)
            {
                v[j + 1] = v[j];
                j = j - 1;
            }
            if (v[j + 1] != temp)
                v[j + 1] = temp;
        }
        else {
            while (j >= 0 && v[j] < temp)
            {
                v[j + 1] = v[j];
                j = j - 1;
            }
            if (v[j + 1] != temp)
                v[j + 1] = temp;
        }

    }
}

void Sort::BubbleSort(bool ascendent)
{
    int last = nr_of_elem - 1;
    while (last > 0)
    {
        int nr = last - 1;
        last = 0;
        for (int i = 0;i <= nr;i++)
            if (ascendent == true)
            {
                if (v[i] > v[i + 1])
                {
                    int aux = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = aux;
                    last = i;
                }
            }
            else
                if (v[i] < v[i + 1])
                {
                    int aux = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = aux;
                    last = i;
                }
    }
}

void Sort::QuickSort(bool ascendent, int first, int last)
{
    if (ascendent == true)
    {
        if (first < last) {

            int pivot = v[last];
            int i = (first - 1);
            for (int j = first;j <= last - 1;j++)
                if ((v[j] < pivot)) //and ascendent==false) || !(v[j]<pivot and ascendent==true)) 
                {
                    i++;
                    swap(v[i], v[j]);
                }
            swap(v[i + 1], v[last]);
            int pi = i + 1;
            QuickSort(ascendent, first, pi - 1);
            QuickSort(ascendent, pi + 1, last);
        }
    }
    else
    {
        if (first < last) {

            int pivot = v[last];
            int i = (first - 1);
            for (int j = first;j <= last - 1;j++)
                if ((v[j] > pivot)) //and ascendent==false) //|| !(v[j]<pivot and ascendent==true)) {
                {
                    i++;
                    swap(v[i], v[j]);
                }
            swap(v[i + 1], v[last]);
            int pi = i + 1;
            QuickSort(ascendent, first, pi - 1);
            QuickSort(ascendent, pi + 1, last);
        }
    }
}

void Sort::StalinSort(bool ascendent)
{
    if (ascendent == true)
    {
        for (int i = 0;i < nr_of_elem - 1;i++)
        {
            if (v[i + 1] <= v[i])

            {
                for (int j = i + 1;j < nr_of_elem;j++)
                    v[j] = v[j + 1];
                nr_of_elem--;
                i--;
            }
        }
    }
    else
    {
        for (int i = 0;i < nr_of_elem - 1;i++)
        {
            if (v[i + 1] >= v[i])

            {
                for (int j = i + 1;j < nr_of_elem;j++)
                    v[j] = v[j + 1];
                nr_of_elem--;
                i--;
            }
        }
    }
}

void Sort::BogoSort(bool ascendent)
{
    int a,b,sortat=1;
    srand(time(NULL));
    if (ascendent == true)
    {
        while (sortat)
        {
            swap(v[rand() % nr_of_elem], v[rand() % nr_of_elem]);
            a = nr_of_elem;
            b = 0;
            while (a > 1)
                if (v[a] >= v[a - 1])
                    b = 1;
            if (b == 0)
                sortat = 0;
        }

    }
    else
    { 
        while (sortat)
        {
            swap(v[rand() % nr_of_elem], v[rand() % nr_of_elem]);
            a = nr_of_elem;
            b = 0;
            while (a > 1)
                if (v[a] <= v[a - 1])
                    b = 1;
            if (b == 0)
                sortat = 0;
        }
    }
}
void Sort::BogoSort(bool ascendent)
{
    int a,b,sortat=1;
    srand(time(NULL));
    if (ascendent == true)
    {
        while (sortat)
        {
            swap(v[rand() % nr_of_elem], v[rand() % nr_of_elem]);
            a = nr_of_elem;
            b = 0;
            while (a > 1)
                if (v[a] >= v[a - 1])
                    b = 1;
            if (b == 0)
                sortat = 0;
        }

    }
    else
    { 
        while (sortat)
        {
            swap(v[rand() % nr_of_elem], v[rand() % nr_of_elem]);
            a = nr_of_elem;
            b = 0;
            while (a > 1)
                if (v[a] <= v[a - 1])
                    b = 1;
            if (b == 0)
                sortat = 0;
        }
    }
}
void Sort::Print()
{
    for (int i = 0;i < nr_of_elem;i++)
        cout << v[i] << " ";
    cout << '\n';
}

int Sort::GetElementsCount()
{
    return nr_of_elem;
}

int Sort::GetElementFromIndex(int index)
{
    if (index >= nr_of_elem)
        return -1;
    return v[index];
}
