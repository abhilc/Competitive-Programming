#include<iostream>
using namespace std;



int main()
{
	int l, n, q, tests, g;
	cin >> tests;
	while(tests--){
		cin >> g;
		while(g--){
			cin >> l >> n >> q;
			if(n%2==1)
			{
				if(l==q)
					cout << (n/2) << "\n";
				else
					cout << (n/2) + 1 << "\n";
			}
			else
				cout << (n/2) << "\n";
		}
	}
}



