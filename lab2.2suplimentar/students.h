

class Students
{
private:
	const char* Names;
	float GradeM, GradeE, GradeH;
public:
	void SetName(const char* val);
	const char* GetName();

	void SetGradeM(float val);
	void SetGradeE(float val);
	void SetGradeH(float val);

	float GetGradeM();
	float GetGradeE();
	float GetGradeH();

	float GetAvg();
};
int CmpName(Students a, Students b);
int CmpGradeM(Students a, Students b);
int CmpGradeE(Students a, Students b);
int CmpGradeH(Students a, Students b);
int CmpAvg(Students a, Students b);

class Grupe
{
public:
	Students arr[256];
	int n;
	void sort();
	void show();
};

