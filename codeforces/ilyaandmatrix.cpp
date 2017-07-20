#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int a[2000001];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a, a+n);

	long long ans = 0;
	for(int i=0;i<n;i++)
	{
		ans += a[i];
		if((i + 1)%4==0)
		{
			ans += a[i];
		}
	}
	cout << ans;
}
			
