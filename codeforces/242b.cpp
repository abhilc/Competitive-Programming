#include<iostream>
#include<map>
#include<cmath>
using namespace std;



int main()
{
	int n, s, t, x, y;
	scanf("%d %d", &n, &s);

	map<int, int> c;
	bool success = 0;

	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d", &x, &y, &t);
		c[x*x + y*y] += t;
	}

	for(auto p: c)
	{
		if((s += p.second)>=1000000)
		{
			printf("%f", sqrt(p.first));
			return 0;
		}
	}
	cout << -1;
}
