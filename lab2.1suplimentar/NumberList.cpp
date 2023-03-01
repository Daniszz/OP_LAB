#include "NumberList.h"
#include <iostream>
using namespace std;
void NumberList::Init()
{
	count = 0;
	numbers = new int[256];
}
void NumberList::Add(int x)
{
	count++;
	if (count > 256)
		this->More();
	numbers[count - 1] = x;
}
void NumberList::Sort()
{
	

	for (int i = 0;i < count - 1;i++)
		for (int j = i + 1;j < count;j++)
			if (numbers[i] > numbers[j])
				swap(numbers[i], numbers[j]);
}
void NumberList::Print()
{
	for (int i = 0; i < count; i++)
		cout << numbers[i] << " ";
}

void NumberList::More()
{
	int* a = new int[this->count - 1 + 256], * b = this->numbers;
	for (int i = 0; i < this->count - 1; i++)
		a[i] = b[i];
	delete b;
	this->numbers = a;
}