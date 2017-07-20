#include<iostream>
using namespace std;


int main()
{
	int a[51];
	int n, k;
	cin >> n >> k;

	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	int val = a[k-1];

	int ans = 0;

	for(int i=0;i<n;i++)
	{
		if(a[i] >= val && a[i] > 0)
			ans++;
	}

	cout << ans << "\n";
}
