#include<iostream>
#include<cmath>
using namespace std;

int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
int lucky[1001];

int factor(int n)
{
	int i = 0;
	int rt = sqrt(n);
	int c = 0;
	for(int i=0;primes[i]<=rt;i++)
	{
		if(n % primes[i] == 0)
		{
			c++;
			while(n%primes[i]==0)
			{
				n/=primes[i];
			}
		}
	}
	if(n > 1) c++;
	return c;
}


void calc()
{
	int k = 1;
	for(int n = 30;n<2665;n++)
	{
		if(factor(n) >= 3)
		{
			lucky[k++] = n;
		}
	}
}


int main()
{
	int tc;
	cin >> tc;
	calc();

	while(tc--)
	{
		int n;
		cin >> n;
		cout << lucky[n] << "\n";
	}
}


