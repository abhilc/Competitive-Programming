#include<iostream>
#include<algorithm>
using namespace std;



int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		long long a[20001];
		cin >> n >> k;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}
		sort(a, a+n);
		long long mindiff = a[k-1] - a[0];
		for(int i=1;i<n-k+1;i++)
		{
			mindiff = min(mindiff, (a[i+(k-1)] - a[i]));
		}
		cout << mindiff << "\n";
	}
}
