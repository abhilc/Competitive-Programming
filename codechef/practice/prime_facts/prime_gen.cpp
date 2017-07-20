#include<iostream>
#define maxn 10005
using namespace std;


bool isPrime[maxn] = {0};

void sieve(int n)
{
	isPrime[0] = isPrime[1] = 1;
	for(int i=2;i*i<=n;i++)
	{
		if(!isPrime[i])
		{
			for(int j = i*2; j<=n; j+=i)
			{
				isPrime[j] = 1;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	sieve(n);

	for(int i=0;i<=n;i++)
	{
		if(!isPrime[i])
			cout << i << "\n";
	}
}

