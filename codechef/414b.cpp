#include<iostream>
#define MOD 1000000007
using namespace std;
const int maxi = 2001;

int dp[maxi][maxi];


int main()
{
	int n, k;

	cin >> n >> k;

	for(int i=1;i<=n;i++)
	{
		dp[1][i] = 1;
	}

	for(int i=2;i<=n;i++)
	{
		for(int j=i;j<=n;j+=i)
		{
			dp[i][j] += dp[i-1][j];
			dp[i][j] = dp[i][j]%MOD;
		}
	}

	long long ans = 0;

	for(int i=1;i<=n;i++)
	{
		ans = (ans + dp[k][i]) % MOD;
	}

	cout << ans << "\n";
}
	
	
