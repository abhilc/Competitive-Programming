#include<iostream>
#include<vector>
#define MOD 1000000007
#define maxn 100005
typedef long long LL;
#include<algorithm>
using namespace std;

int bsearch(LL arr[], LL key, int sz)
{
	int lo = 0, hi = sz;
	while(lo < hi)
	{
		int mid = (lo + hi)/2;
		if(key >= arr[mid])
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}


	


void solve()
{
	int p, q, r;
	scanf("%d%d%d", &p, &q, &r);

	//vector<int> X, Y, Z;
	LL X[maxn], Y[maxn], Z[maxn];
	int x;

	for(int i=0;i<p;i++)
	{
		scanf("%lld",&X[i]);

	}

	for(int j=0;j<q;j++)
	{
		scanf("%lld", &Y[j]);

	}

	for(int k=0;k<r;k++)
	{
		scanf("%lld", &Z[k]);
	}
	sort(X, X+p);
	sort(Z, Z+r);

	//Cal prefix sums
	
	LL pref_sumX[maxn], pref_sumZ[maxn];

	pref_sumX[0] = X[0];
	pref_sumZ[0] = Z[0];

	for(int i=1;i<p;i++)
		pref_sumX[i] = pref_sumX[i-1] + X[i];

	for(int j=1;j<r;j++)
		pref_sumZ[j] = pref_sumZ[j-1] + Z[j];

	LL temp = 0, summ = 0;
	int hx, hz;

	for(int i=0;i<q;i++)
	{
		hx = bsearch(X, Y[i], p);
		hz = bsearch(Z, Y[i], r);
		if(hx==0 || hz==0)
		{
			summ+=0;
			continue;
		}

		temp = (((hx * Y[i])%MOD + (pref_sumX[hx-1])%MOD)%MOD * (((hz * Y[i])%MOD + (pref_sumZ[hz-1])%MOD)%MOD))%MOD;
		summ += temp % MOD;
	}
	//cout << summ%MOD << "\n";
	printf("%lld\n", summ%MOD);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
		solve();
}


