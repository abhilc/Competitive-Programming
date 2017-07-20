#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;



int main()
{
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;

	int A = 0, D = 0;

	for(int i=0;i<n;i++)
	{
		A += s[i]=='A';
		D += s[i]=='D';
	}


	if(A == D)
	{
		printf("Friendship");
		return 0;
	}
	
	A>D?printf("Anton"):printf("Danik");
}
