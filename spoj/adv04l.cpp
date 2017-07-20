#include<iostream>
using namespace std;



int main()
{
	unsigned long long a[90];
	a[1] = 0;
	a[2] = 1;
	for(int i=3;i<=80;i++)
	{
		a[i] = a[i-1] + a[i-2];
	}
	long long t;
	cin >> t;
	while(t--)
	{
		unsigned long long n, ans=0;
		cin >> n;
		while(n>0)
		{
			for(int i=1;i<=80;i++)
			{
				if(a[i] > n)
				{
					ans+=a[i];
					n-=a[i-1];
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
