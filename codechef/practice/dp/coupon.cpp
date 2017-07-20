#include<iostream>
#include<algorithm>
#include<cmath>
#define INF 1000000000
#include<vector>
typedef long long int LL;
using namespace std;

vector<vector<LL> > dp, cost, disc;


int main()
{
	int tests;
	scanf("%d", &tests);

	while(tests--)
	{
		int n, m;
		scanf("%d%d", &n, &m);

		dp.clear();
		cost.clear();
		disc.clear();

		dp.resize(n);
		cost.resize(n);
		disc.resize(n);

		for(int i=0;i<n;i++)
		{
			dp[i].resize(m);
			cost[i].resize(m);
			disc[i].resize(m);
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%lld", &cost[i][j]);
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%lld", &disc[i][j]);
			}
		}

		//dp[i][j] = total cost if ith item is bought in the jth shop
		

		LL prev = (LL)INF*INF, prev2;

		for(int i=0;i<m;i++)
		{
			dp[0][i] = cost[0][i];
			prev = min(prev, dp[0][i]);
		}

		for(int i=1;i<n;i++)
		{
			prev2 = (LL)INF*INF;
			for(int j=0;j<m;j++)
			{
				LL d = max(0LL, cost[i][j] - disc[i-1][j]);

				dp[i][j] = std::min(dp[i-1][j] + d, prev + cost[i][j]);

				prev2 = std::min(prev2, dp[i][j]);
			}
			prev = prev2;
		}
		
		LL res = (LL)INF*INF;
		for(int i=0;i<m;i++)
		{
			res = std::min(res, dp[n-1][i]);
		}
		cout << res << "\n";
	}
}






