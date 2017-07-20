#include<cstdio>
#include<iostream>
using namespace std;



int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	while(1)
	{
		if(a==0 && b==0 && c==0)
			break;
		if(a+c==2*b || (a==0||b==0||c==0))
			cout << "AP " << (a) + 3*((c)-(b)) << "\n";
			
		else
			cout << "GP " << (c) * ((c)/(b)) << "\n";

		cin >> a >> b >> c;
	}
}
