#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn = 100005;
int n, x, y;
int a[maxn], b[maxn];


void Work()
{
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		sum += a[i];
		b[i] -= a[i];
	}
	std::sort(b, b+n, std::greater<int>());

	for(int i=0; n - i > x || (i < y && b[i] >= 0); ++i)
	{
		sum += b[i];
	}
	cout << sum << "\n";

}


int main()
{
	int cases = 1;
	while(cases--)
	{
		cin >> n >> x >> y;
		for(int i=0;i<n;i++)
			cin >> a[i];
		for(int i=0;i<n;i++)
			cin >> b[i];
		Work();
	}
	return 0;
}
