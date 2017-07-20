#include<iostream>
using namespace std;

int mat[501][501], r, c;
int dp[501][501];


int solve()
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
				dp[i][j] = 0;
		}
	}
	for(int i=1;i<r;i++)
	{
		for(int j=1;j<c;j++)
		{
			dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]) + mat[i][j];
			if(dp[i][j] < 0 && (i<r-1 && j<c-1))
				dp[i][j] = -1e9;
		}
	}
	cout << dp[r-1][c-1] << " ";
	return dp[r-1][c-1];
}


int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> r >> c;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			{
				
				cin >> mat[i][j];
			}
		int ans = solve();
		if(ans > 0)
			cout << 1 << "\n";
		else 
			cout << 1 + ans << "\n";
	}

}
