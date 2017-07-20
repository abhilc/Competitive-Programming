#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		int b;
		cin >> n >> b;
		long long res;

		if(b >= (n/2))
		{
			cout << n - b << "\n";
			continue;
		}
		else
		{
			res = (n/2) * (n/2);
		}

		cout << res/b << "\n";
	}
		
}
