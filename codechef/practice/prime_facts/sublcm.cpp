#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define assn(n,a,b) assert(n<=b && n>=a)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define pdn(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%d",&n)
#define pn printf("\n")
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define MOD 1000000007
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}

VI fac[1000009];
int arr[1000009],dp[1000009]={},last[1000009]={};
char str[1000009];
int primes[100009],cnt=0;

void pre()
{
	int n = 10000;
	for(int i=2;i*i<=n;i++)
	{
		if(str[i]==0)
			for(int j=i;j*i<=n;j++)
				str[i*j] = 1;
	}
	for(int i=2;i<=n;i++)
		if(str[i]==0) primes[cnt] = i,cnt++;
}

int main()
{
	pre();
	int i, j, k;
	//Calc prime factors for each number
	
	for(int i=2;i<=1000000;i++)
	{
		j = i;
		for(int k = 0;primes[k]*primes[k]<=j;k++)
		{
			if(j%primes[k] == 0)
			{
				fac[i].pb(primes[k]);
				while(j%primes[k]==0) j/=primes[k];
			}
		}
	
	if(j>=2)
		fac[i].pb(j);
	}

	int t;
	cin >> t;
	
	while(t--)
	{
		memset(dp, -1, sizeof(dp));
		memset(last, -1, sizeof(last));

		int n, i, j, maxi, ans = -1;
		sd(n);

		for(i = 1;i<=n;i++)
			sd(arr[i]);

		dp[1] = 1;

		vector<int>::iterator it;

		for(it = fac[arr[1]].begin();it!=fac[arr[1]].end();++it)
			last[*it] = 1;

		for(i = 2;i<=n;i++)
		{
			maxi = dp[i-1];
			for(it = fac[arr[i]].begin();it!=fac[arr[i]].end();++it)
			{
				maxi = max(maxi, last[*it] + 1);
				last[*it] = i;
			}
			dp[i] = maxi;
		}

		for(int i = 1; i<=n; i++)
			ans = max(ans, i-dp[i]+1);
		if(ans==1) printf("-1\n");
		else
			printf("%d\n", ans);

	}
}


