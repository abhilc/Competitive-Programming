#include<iostream>
#include<algorithm>
using namespace std;



int main()
{
	int n;
	cin >> n;

	int sum = 0, a[1000001];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}

	sort(a, a+n);
	int diff;

	for(int i=0;i<n;i++)
	{
		if( i!=0 && a[i]-a[i-1]>0)
		{
			diff = a[i] - a[i-1];
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i!=0)
		{
			if(a[i]-a[i-1]==diff || a[i]-a[i-1]==0)
				;
			else
			{
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n";




}


	
