// NumberList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "NumberList.h"

int main()
{
	NumberList p;
	p.Init();
	
	for(int i=15;i>=1;i--)
		p.Add(i);
	//p.Sort();
	//p.Print();
}

