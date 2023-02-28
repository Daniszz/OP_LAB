
#include "NumberList.cpp"
#include <iostream>
using namespace std;
void NumberList::Init()
{
	count = 0;
}
bool NumberList :: Add(int x)
{
	if (count < 9)
	{
		
		numbers[count] = x;
		count++;
	}else
		return false;
	
}
void NumberList::Sort()
{
	for (int i = 0;i < count;i++)
		for (int j = i+1;j <= count;j++)
			if (numbers[i] > numbers[j])
				swap(numbers[i], numbers[j]);
}
void NumberList::Print()
{
	for (int i = 0;i < count;i++)
		cout << numbers[i] << " ";
}

