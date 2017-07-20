#include<iostream>
using namespace std;




int main()
{
	int L, B;
	int lim = 1, bob = 2;
	int tests;
	cin >> tests;

	while(tests--)
	{
		cin >> L >> B;
		lim = 1;
		bob = 2;

	while(1)
	{
		L -= lim;
		lim += 2;
		B -= bob;
		bob +=2;
		if(L < 0)
		{
			cout << "Bob\n";
			break;
		}
		if(B < 0)
		{
			cout << "Limak\n";
			break;
		}
	}
	}
}

