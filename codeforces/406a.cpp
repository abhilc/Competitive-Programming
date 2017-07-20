#include<iostream>
using namespace std;



int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	while(b!=d && b < 1e8)
	{
		if(b < d)
			b+=a;
		else
			d+=c;
	}
	if(b<1e8)
	{
		cout << b;
		return 0;
	}
	cout << -1;
}
