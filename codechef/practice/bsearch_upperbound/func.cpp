#include<iostream>
#include<cmath>
#include<vector>
#define LLD long long
#define MOD 1000000007
LLD INF;
using namespace std;

LLD A[10004];
LLD C[10004];
int N;

vector<LLD> V[1000001];

void gen()
{
	for(int i=3;i<=1000000;++i)
	{
		V[i].push_back(0);
		V[i].push_back(1);
	}
	for(LLD i=2LL;i<=1000000LL;++i)
	{
		int pos = 3;
		LLD k = i*i*i;
		while(1)
		{
			V[pos].push_back(k);
			if(k>=(INF/(double)i))
				break;
			k = k*i;
			pos++;
		}
	}
}


LLD root(LLD a, LLD b)
{
	if(a==1)
		return b;
	if(a==2)
		return (LLD)sqrt(b);

	
	LLD lo = 0, hi = V[a].size()-1, mid, ans = 1;

	while(lo <= hi)
	{
		LLD mid = (lo + hi)/2LL;
		
		if(V[a][mid] > b)
			hi = mid - 1;
		else
		{
			ans = mid;
			lo = mid + 1;
		}
	}
	return ans;
}

LLD val(LLD x)
{
	LLD res = 0;
	for(int i=1;i<=N;i++)
	{
		LLD k = root(i, x);
		if(k==1)
		{
			res += C[i-1];
			res %= MOD;
			return res;
		}
		k = k % MOD;
		res += (k * A[i-1])%MOD;
		res %= MOD;
	}
	return res;
}

void solve()
{
	INF = 1000000001;
	INF = INF * INF;
	gen();
	int t, Q;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d%d", &N, &Q);
		for(int i=0;i<N;i++)
		{
			scanf("%lld", &A[i]);
			A[i] = (A[i]+MOD)%MOD;
		}

		C[N-1] = A[N-1];
		for(int i=N-2;i>=0;i--)
		{
			C[i] = (C[i+1] + A[i])%MOD;
		}

		for(int i=0;i<Q;i++)
		{
			LLD x;
			scanf("%lld", &x);
			printf("%lld ", val(x));
		}
		printf("\n");
	}
}


int main()
{
	solve();
	return 0;
}






