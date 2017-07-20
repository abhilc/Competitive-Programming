#include<iostream>
#include<algorithm>
#include<cstring>
#include<sstream>
typedef long long LL;
#include<vector>
#define MOD 1000000007
using namespace std;

int toint(const string &s) { stringstream ss; ss << s; int x; ss >> x; return x; }

LL dp[1025][109] = {};
int p;
vector<int> arr[109];
int N;

LL rec(int mask, int shirt)
{
    if(shirt==101)
    {
        if(mask==(p))return dp[mask][shirt]=1ll;
        else return dp[mask][shirt]=0ll;
    }
    if(dp[mask][shirt]!=-1)return dp[mask][shirt];
    LL ans=0;
    ans += rec(mask,shirt+1);
    int n=arr[shirt].size(),i;
    for(i=0; i<n; i++)
    {
        if((mask)&(1<<arr[shirt][i]))continue;
        ans += rec((mask)|(1<<arr[shirt][i]),shirt+1);
        if(ans>=MOD)ans-=MOD;
    }
    return dp[mask][shirt]=ans;
}



int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		memset(dp, -1, sizeof(dp));
		int n, i, j;
		string ss, temp;
		cin >> n;
		getchar();
		for(int i=0;i<=100;i++)
			arr[i].clear();
		for(i = 0;i<n;i++)
		{
			getline(cin, ss);
			stringstream s (ss);
			while(s >> temp)
				arr[toint(temp)].push_back(i);
		}
		for(i = 0;i<100;i++)
			sort(arr[i].begin(), arr[i].end());
		p = (1<<n)-1;
		cout << rec(0, 1) << endl;
	}
	return 0;

}
