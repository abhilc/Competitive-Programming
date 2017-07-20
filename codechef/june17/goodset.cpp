#include<iostream>
using namespace std;


int main()
{
	int tests;
	cin >> tests;

	while(tests--)
	{
		int n;
		cin >> n;
		int p=1;
		for(int i=0;i<n;i++)
		{
			cout << p << " ";
			p+=2;
		}
		cout << "\n";
	}
}

