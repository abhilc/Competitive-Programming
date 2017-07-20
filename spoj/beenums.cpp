#include<iostream>
using namespace std;



int main()
{
	int n;
	while(1)
	{
		scanf("%d", &n);
		if(n==-1)
			break;
		(n%6==1)?printf("Y\n"):printf("N\n");
	}
}
