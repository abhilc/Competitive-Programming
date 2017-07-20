#include<iostream>
using namespace std;


int main()
{
	int n, a, b;

	int g[200005];

	cin >> n >> a >> b;

	for(int i=0;i<n;i++)
	{
		cin >> g[i];
	}

	int ans = 0;
	int totb = 2 * b;

	for(int i=0;i<n;i++)
	{
		if(g[i]==1)
		{
			if(a > 0)
				a--;
			else if(b > 0)
			{
				b--;
				totb-=1;
			}
			else if(totb > 0)
				totb--;
			else
				ans++;
		}
		else 
		{
			if(b > 0)
			{
				b--;
				totb-=2;
			}
			else
			{
				ans += 2;
			}
		}
	}
	cout << ans << "\n";
}
			
