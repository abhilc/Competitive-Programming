#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;

	int a[m + 1];

	for(int i=0;i<m;i++)
	{
		cin >> a[i];
	}

	sort(a, a+m);

	int ans = 1000000001;

	for(int i=0;i<=m-n;i++)
	{
		if(a[i+n-1]-a[i] < ans)
			ans = a[i+n-1] - a[i];
	}

	cout << ans << "\n";
}
