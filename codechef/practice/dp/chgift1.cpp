#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	int tests;
	scanf("%d", &tests);

	while(tests--)
	{

	int N;
	cin >> N;
	int a[N + 1];
	for(int i=0;i<N;i++)
	{
		cin >> a[i];
	}
	sort(a, a+N);

	int dp[N+1];

	dp[0] = a[0];

	for(int i=1;i<N;i++)
	{
		dp[i] = std::min(std::min(dp[i-1]*a[i], dp[i-1]-a[i]), dp[i-1]+a[i]);
	}
	
	cout << dp[N-1] << "\n";
}
}
