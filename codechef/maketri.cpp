#include<iostream>
#include<algorithm>
typedef long long LL;
#define MIN(a, b) (LL)a<(LL)b?(LL)a:(LL)b
using namespace std;



int main()
{
	long long N, L, R, a[1000001], sbig, big, j, ans=0, p;
	scanf("%lld %lld %lld", &N, &L, &R);
	big = -1;
	sbig = -1;
	long long min = (1<<30);
	long long smin = min;
	for(long long i=0;i<N;i++)
	{
		scanf("%lld", &a[i]);
		if(big<a[i])
		{
			sbig = big;
			big = a[i];
		}
		else if(a[i] > sbig)
			sbig = a[i];

	}
	std::sort(a, a+N);
	LL minDiff = a[1]-a[0];
	for (int i = 2 ; i < N ; i++) 
	{
    		minDiff = std::min(minDiff, (a[i]-a[i-1]));

	}

	long long sum = big+sbig;//, diff = smin-min;
	//cout << minDiff << " " << sum;
	for(long long i=L;i<=R;i++)
	{
		if(i>minDiff && i<sum)
			ans++;
	}
	printf("%lld\n", ans);
	//cout << ans << " ";
}
