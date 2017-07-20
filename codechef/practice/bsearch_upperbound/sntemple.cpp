#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;



int main()
{
	int tests;
	scanf("%d", &tests);

	while(tests--)
	{
		int N;
		scanf("%d", &N);
		ll res = 1e18;
		vector<ll> a(N+1);
		ll sum = 0;
		
		for(int i=1;i<=N;i++)
		{
			scanf("%lld", &a[i]);
			sum += a[i];
		}

		ll lo = 1;
		ll hi = N;

		while(lo <= hi)
		{
		ll m = (lo + hi)/2;
		ll len = 2 * m - 1;

		if(len > N)
		{
			hi = m - 1;
		}
		else
		{
			vector<bool> L(N+1);
			vector<bool> R(N+1);

			ll k = 0;
			for(int i=1;i<=N;i++)
			{
				if(a[i]>=k+1)
				{
					k++;
					if(k==m)
					{
						L[i] = true;
						k--;
					}
				}
				else
					k = a[i];
			}
			
			k = 0;
			for(int i=N;i>=0;--i)
			{
				if(a[i] >= k+1)
				{
					k++;
					if(k==m)
					{
						R[i] = true;
						k--;
					}
				}
				else
				{
					k = a[i];
				}
			}
			bool found = 0;
			for(int i=1;i<N;i++)
			{
				if(L[i] && R[i])
				{
					found = true;
					break;
				}
			}
			if(found)
			{
				lo = m + 1;
				ll cost = sum - (m * (m+1) - m);
				res = std::min(res, cost);
			}
			else
			{
				hi = m - 1;
			}
		}
		}
		printf("%lld\n", res);
	}
}
		


