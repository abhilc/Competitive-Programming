#include<iostream>
using namespace std;



long long gcd(long long a, long long b)
{
     return b ? gcd(b, a % b) : a;    
}



int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	long long x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if(x1 < 0)
		x1 = -x1;
	if(x2 < 0)
		x2 = -x2;
	if(y1 < 0)
		y1 = -y1;
	if(y2 < 0)
		y2 = -y2;

	long long g1 = gcd(x1, y1);
	long long g2 = gcd(x2, y2);

	while( g1 > 0 && g1 < g2)
		g1 = g1*2;

	g1==g2?printf("YES\n"):printf("NO\n");
	}
}

