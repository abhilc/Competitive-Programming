#include<iostream>
typedef long long LL;
using namespace std;


int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		LL u, v, n;
		cin >> u >> v;
		n = u + v + 1;
		LL val1 = -1, val2 = -1;
		if(n % 2 == 1)
			val1 = (n - 1)/2;
		else
			val2 = n / 2;

		if(val1 == -1)
			cout << (n - 1) * val2 + 1 + u << "\n";
		else
			cout << n * val1 + 1 + u << "\n";


	}
}
		

