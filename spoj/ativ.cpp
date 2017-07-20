#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>

#define MAX 100003
#define MOD 100000000

using namespace std;
int n;
vector<pair<int,int> > arr ( MAX );
vector<int>::iterator it;
int dp[MAX][2];


void solve()
{
	memset(dp,0,sizeof(dp[0][0] * MAX * 2));
	vector<int> entime;

	dp[0][1] = 1;
	entime.push_back(arr[0].first);
	for(int i=1;i<n;i++)
	{
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		if(dp[i][0] >= MOD) dp[i][0]-=MOD;

		if(arr[i].second < entime[0])
		{
			dp[i][1] = 1;
		}
		else
		{
			 it = upper_bound(entime.begin(), entime.end(), arr[i].second);
			 int diff = it - entime.begin(); --diff;

			 dp[i][1] = 1 + dp[diff][0] + dp[diff][1];
			 if(dp[i][1] >= MOD)
				 dp[i][1] -= MOD;
		}
		entime.push_back(arr[i].first);
	}
	printf("%0.8d\n", (dp[n-1][0] + dp[n-1][1])%MOD);
}


int main()
{
	while(true)
	{
		cin >> n;
		if(n==-1)
			break;
		for(int i=0;i<n;i++)
		{
			cin >> arr[i].second;
			cin >> arr[i].first;
		}
		sort(arr.begin(), arr.begin() + n);

		solve();
	}
}

