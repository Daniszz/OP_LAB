#include <iostream>
#include "students.h"
#include <string.h>
using namespace std;
int main()
{
    Students Andrei, Razvan;
    Andrei.SetName("Andrei");
    Andrei.SetGradeM(4.5);
    Andrei.SetGradeE(6);
    Andrei.SetGradeH(7.3);
    Razvan.SetName("Razvan");
    Razvan.SetGradeE(7);
    Razvan.SetGradeM(8.6);
    Razvan.SetGradeH(9);
    cout << CmpName(Andrei, Razvan) << endl;
    cout << CmpGradeM(Andrei, Razvan) << endl;
    cout << CmpGradeE(Andrei, Razvan) << endl;
    cout << CmpGradeH(Andrei, Razvan) << endl;
    cout << CmpAvg(Andrei,Razvan) << endl;
    Grupe A2;
    A2.arr[0] = Andrei;
    A2.arr[0] = Razvan;
    A2.sort();
    A2.show();
    return 0;
}
