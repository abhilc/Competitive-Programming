#include<iostream>
#define MOD 2370823708
using namespace std;



int main()
{
	long long m, n, k, p, ans = 1;
	scanf("%lld %lld %lld", &m, &n, &k);
	p = n - k;
	for(long long i=0;i<n-p;i++)
	{
		ans = ans * (7-p);
		while(ans > MOD)
			ans-=MOD;
		p++;
	}
	//ans = ((ans%MOD) * (m%MOD));
	printf("%lld\n", ans%MOD);
}
	
