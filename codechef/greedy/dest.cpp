#include<iostream>
#include<algorithm>
using namespace std;

int a[1000001];

int main()
{
	int n, k;
	cin >> n >> k;


	for(int i=0;i<n;i++)
		cin >> a[i];

	sort(a, a+n);

	int ans = 0;

	for(int i=n-1;i>=0;i-=k)
		ans += (a[i]-1)*2;

	cout << ans << "\n";

}

