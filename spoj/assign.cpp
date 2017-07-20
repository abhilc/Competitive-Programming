#include<iostream>
#define ison(x, i) (((x) >> (i)) & 1)
using namespace std;

int n, j;
long long dp[1<<20];
int a[20][20];


void solve()
{
	scanf("%d", &n);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d", &a[i][j]);
		}

	dp[0] = 1;

	for(int i=1;i<(1<<n);i++)
	{
		j = 0;
		dp[i] = 0;
		for(int k=0;k<n;k++)
			j += ison(i, k);

		for(int k=0;k<n;k++)
			if(a[j-1][k] && ison(i,k)){
				dp[i] = dp[i] + dp[i & ~(1<<k)];
			}
	}

	cout << dp[(1<<n)-1] << "\n";
}


int main()
{
	int tests;
	scanf("%d", &tests);
	while(tests--)
	{
		solve();
	}
}
