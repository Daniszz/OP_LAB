

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
void revers(char a[250])
{
    char aux;
    for (int i = 0;i <= strlen(a) / 2-1;i++)
    {
        aux = a[i];
        a[i] = a[strlen(a) - i-1];
        a[strlen(a) - i-1] = aux;
    } 
}

int main()
{
    
    FILE* p;
    char c[1000],s[1000], aux[1000];

    bool rez;
    rez = fopen_s(&p,"Text.txt","r");
    if (rez != 0)
        printf("Nu");
    fgets(s, 250, p);
    s[strlen(s) - 1] = NULL;
    while (fgets(c, 250, p) != NULL)
    {
        int carry = 0,sum,i;
        if(c[strlen(c) - 1] == '\n')
        c[strlen(c) - 1] = NULL;
        if (strlen(s) < strlen(c))
        {
            strcpy(aux, s);
            strcpy(s, c);
            strcpy(c, aux);
       }
        revers(s);
        revers(c);
        cout << s << endl << c << endl;
        for (i = 0; i < strlen(c) || i < strlen(s); i++) {
            sum = (i < strlen(s) ? s[i] - '0' : 0) + (i < strlen(c) ? c[i] - '0' : 0) + carry;
            s[i] = sum % 10 + '0';
            carry = sum / 10;
        }

        if (carry)
            s[i++] = carry + '0';
        revers(s);
      
    }
    cout << s;
    return 0;

}