#include<iostream>
bool prime[1000000001];
using namespace std;


void sieve()
{
	for(int i=2;i<=1000000000;i++)
	{
		if(prime[i])
		{
			for(int j=2*i;j*j<1000000000;j+=i)
			{
				prime[j] = false;
			}
		}
	}
}



int main()
{
	int n, a, b;
	scanf("%d", &n);
	prime[0] = prime[1] = false;
	for(int i=2;i<=1000000000;i++)
		prime[i] = true;
	sieve();

	while(n--)
	{
		scanf("%d %d", &a, &b);
		for(int i=a;i<=b;i++)
		{
			if(prime[i])
				printf("%d\n", a);
		}
	}
}

