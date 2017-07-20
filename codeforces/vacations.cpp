#include<iostream>
using namespace std;



int main()
{
	int n, rest = 0, rest1 = 0, rest2 = 0, val, i;
	cin >> n;
	int a[101];
	for(i=0;i<n;i++)
	{
		cin >> a[i];
		if(a[i]==0)
		{
			rest++;
		}
	}
	i = 0;
	while(a[i]!=0)
	{
		i++;
	}
	if(i>=n)
	{
		cout << rest;
		return 0;
	}
		
	if(a[i]==1)
	{
		val = 1;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]!=0)
			{
				val ^= a[j];
				if(val==0)
				rest++;
			}
		}
	}
	else if(a[i]==2)
	{
		val = 2;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]!=0)
			{
				val^=a[j];
				if(val==0)
					rest++;
			}
		}
	}
	else
	{
		val = 1;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]!=0)
			{
			val^=a[j];
			if(val==0)
				rest1++;
			}
		}
		val = 2;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]!=0)
			{
			val^=a[j];
			if(val==0)
				rest2++;
			}
		}
		rest += std::min(rest1, rest2);
	}
	cout << rest << "\n";
}


