

#include <iostream>
#include "NumberList.h"
int main()
{
     NumberList s;
    s.Init();
    s.Add(4);
    s.Add(9);
    s.Add(10);
    s.Add(2);
    s.Sort();
    s.Print();
}


