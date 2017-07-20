#include<iostream>
using namespace std;


int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int nu = 6 - max(a, b) + 1;
	int de = 6;
	int hcf = 1;
	for(int i=2;i<=de;i++)
	{
		if(nu%i ==0 && de%i==0)
		{
			hcf = i;
		}
	}

	cout << nu/hcf << "/" << de/hcf;

}
