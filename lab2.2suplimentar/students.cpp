#include "Students.h"
#include <iostream>
#include <string.h>
using namespace std;
void Students::SetName(const char* val)
{
	Names = val;
};
const char* Students::GetName()
{
	return Names;
}
void Students::SetGradeM(float val)
{
	GradeM = val;
};
void Students::SetGradeE(float val)
{
	GradeE = val;
};
void Students::SetGradeH(float val)
{
	GradeH = val;
};
float Students::GetGradeM()
{
	return GradeM;
};
float Students::GetGradeE()
{
	return GradeE;
};
float Students::GetGradeH()
{
	return GradeH;
};
float Students::GetAvg()
{
	float media = this->GetGradeM() + this->GetGradeE() + this->GetGradeH();
	media = media / 3;
	return media;
};

void Grupe::sort()
{
	
	for (int i = 0;i < n - 1;i++)
		for (int j = i + 1;j < n;j++)
			if (arr[i].GetAvg() > arr[j].GetAvg())
				swap(arr[i], arr[j]);
};

void Grupe::show()
{
	for (int i = 0; i < n; i++)
		cout << arr[i].GetName() << "\n";
};




int CmpName(Students a, Students b)
{
	int i = 0;
	const char* x = a.GetName(), *y = b.GetName();
	while (x[i] != NULL && y[i] != NULL)
	{
		i++;
	}
	if (x[i] != NULL && y[i] == NULL)
		return 1;
	if (x[i] != NULL && y[i] == NULL)
		return -1;
	i = 0;
	while (x[i] != NULL && y[i] != NULL)
	{
		if (x[i] > y[i])
			return 1;
		if (x[i] < y[i])
			return -1;
		i++;
	}
	return -1;
}
int CmpGradeM(Students a, Students b)
{
	if (a.GetGradeM() > b.GetGradeM())
		return 1;
	else
		return -1;
}
int CmpGradeE(Students a, Students b)
{
	if (a.GetGradeE() > b.GetGradeE())
		return 1;
	else
		return -1;
}
int CmpGradeH(Students a, Students b)
{
	if (a.GetGradeH() > b.GetGradeH())
		return 1;
	else
		return -1;
}
int CmpAvg(Students a, Students b)
{
	if (a.GetAvg() > b.GetAvg())
		return 1;
	else
		return -1;
}