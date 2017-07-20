#include<iostream>
using namespace std;


int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		double r, b, p, bt;
		cin >> r >> b >> p;

		bt = (r+b)-p;

		double pr = r/(b+r), pb = b/(r+b);

		printf("%.10lf\n", p*pr + (bt)*pb);

	}
}
