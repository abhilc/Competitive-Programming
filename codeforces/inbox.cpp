#include<iostream>
using namespace std;


int main()
{
	int n, k, i , j;
	int a[1000001];

	cin >> n >> k;

	long long l = 0;

	for(i=0;i<n;i++)
	{
		cin >> a[i];
		if(i < k)
			l += a[i];
	}

	long long m = l;
	
	for(i=k;i<n;i++)
	{
		l += a[i] - a[i-k];
		if(l < m)
		{
			m = l;
			j = i - k + 1;
		}
	}
	cout << j + 1 << "\n";
}
