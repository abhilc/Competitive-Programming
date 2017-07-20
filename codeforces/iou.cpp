#include<iostream>
using namespace std;


int main()
{
	int a, b, m, n, c, r = 0;
	cin >> n >> c;
	int d[101];
	while(c--)
	{
		cin >> a >> b >> m;
		d[a] -= m;
		d[b] += m;
	}
	for(;n;n--)
		r += d[n]>0?d[n]:0;
	cout << r;
}
