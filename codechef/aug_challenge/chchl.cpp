#include<iostream>
using namespace std;

int main()
{
	int tests;
	int tCuts, m,n;
	cin >> tests;
	while(tests--)
	{
		cin >> m >> n;
		tCuts = (m%10)*(n%10);
		tCuts = (tCuts%10) - 1;
		
		(tCuts%2==1)?cout<<"Yes\n":cout<<"No\n";
	}
}
