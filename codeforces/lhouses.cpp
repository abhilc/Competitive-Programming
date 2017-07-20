#include<iostream>
#include<algorithm>
using namespace std;




int main()
{
	int n, maxh = -999999;
	int a[100001], ans[100001];

	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];

	for(int i=n-1;i>=0;i--)
	{
		if(maxh < a[i])
		{
			maxh = a[i];
		}
		if(maxh != a[i])
		ans[i] = max(0, maxh+1-a[i]);
	}

	for(int i=0;i<n;i++)
	{
		cout << ans[i] << " ";
	}


}

