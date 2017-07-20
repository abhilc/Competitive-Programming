#include<iostream>
#include<cmath>
#include<algorithm>
typedef long long ll;
using namespace std;


ll h[100001], r[100001], L, W;
int N;

bool can_cut(ll ti)
{
	ll total_cut = 0;
	ll ht;
	for(int i=0;i<N;i++)
	{
		if(h[i]+r[i]*ti >= L)
		{
			total_cut += h[i]+r[i]*ti;
			if(total_cut >= W)
				return true;
		}
	}
	return false;
}

int main()
{
	cin >> N >> W >> L;
	
	for(int i=0;i<N;i++)
		scanf("%lld%lld", &h[i], &r[i]);

	ll tl = -1, tr = 10^18+11;

	while(tr-tl>1)
	{
		ll tm = (tr + tl)/2;
		if(can_cut(tm))
			tr = tm;
		else
			tl = tm;
	}

	cout << tr << "\n";
}

	
	

