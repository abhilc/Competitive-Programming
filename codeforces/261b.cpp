#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	long long n;
	cin >> n;
	long long a[200001];
	bool eq = 1;
	cin >> a[0];
	for(int i=1;i<n;i++)
	{
		cin >> a[i];
		if(a[i]!=a[i-1])
			eq = 0;
	}

	sort(a, a+n);
	int f = a[0], s = a[n-1];
	long long c1 = 0, c2 = 0;
	for(int i=0;i<n-1;i++)
	{
		if(a[i]==f)
		{
			c1++;
		}
		else
			break;
	}
	for(int i=n-1;i>0;i--)
	{
		if(a[i]==s)
			c2++;
		else
			break;
	}
	long long p, val;
	if(n%2==1)
	{
		p = (n-1)/2;
		val = n;
	}
	else
	{
		p = n/2;
		val = n-1;
	}


	eq==1?cout<<0 << " " << (val*p) <<"\n":cout << a[n-1] - a[0] << " " << c1*c2 << "\n";
}
