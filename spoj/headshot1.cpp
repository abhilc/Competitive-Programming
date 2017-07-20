#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char a[150];
    int i,n,w=0,b=0;
    float rot,sht;
    scanf("%s",a);
    n = strlen(a);
    for(i=0;i<n;i++)
    {
        if(a[i]=='0')
            w++;


    }
    rot = (float)w/n;
    cout << rot << "\n";
    for(i=0;i<n-1;i++)
    {
        if(a[i]=='0' && a[i+1]=='0')
            b++;
    }
    if(a[0]=='0' && a[n-1]=='0')
        b++;
    sht = (float)b/w;
    cout << sht << "\n";

    if(rot == sht)
        printf("EQUAL\n");
    else if(rot>sht)
        printf("ROTATE\n");
    else
        printf("SHOOT\n");
    return 0;
}
