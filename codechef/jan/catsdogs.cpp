#include<iostream>
using namespace std;



int main()
{
	int T;
	cin >> T;
	while(T--){
		long long c, d, l;
		cin >> c >> d >> l;
		long long tot = 4 * (c + d);
		if(l > tot)
			cout << "no\n";
		else if((2*d)>=c)
		{
			if(l < 4*d || l%4!=0)
				cout << "no\n";
			else if(l%4==0)
				cout << "yes\n";
		}
		else if((2*d)<c)
		{
			if(l < (4*d + (c - 2*d)*4) || l%4!=0)
				cout << "no\n";
			else 
				cout << "yes\n";
		}

	}
}
