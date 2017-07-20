#include<iostream>
#include<cmath>
typedef long long ll;
using namespace std;

int a, b;
ll money;

ll spend(int w)
{
	return floor((w * a)/b);
}

int main()
{
	int n;
	cin >> n >> a >> b;
	int tokens[n+1];

	for(int i=0;i<n;i++)
	{
		cin >> tokens[i];
	}

	ll lo, hi;
	ll max_money;


	for(int i=0;i<n;i++)
	{
		lo = 0;
		hi = tokens[i];
		max_money = floor(hi*a/b);

		while(lo < hi)
		{
			ll mid = (lo + hi)/2;
			money = spend(mid);

			if(money < max_money)
			{
				lo = mid + 1;
			}
			else
			{
				hi = mid;
			}
		}
		cout << tokens[i] - lo << " ";
	}
}

	



