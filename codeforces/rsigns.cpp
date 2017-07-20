#include<iostream>
#include<algorithm>
using namespace std;




int main()
{
	long long n, k, a[100001];
	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}

	int m = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i] < 0)
		{
			a[i] = -1 * a[i];
			m++;
		}
		if(m == k)
			break;
	}
	sort(a, a+n);
	if(m < k)
	{
		if((k-m)%2==1)
		{
				a[0] = -1 * a[0];
		}

	}
	long long sum = 0;
	for(int i=0;i<n;i++)
		sum += a[i];

	cout << sum << "\n";
}


