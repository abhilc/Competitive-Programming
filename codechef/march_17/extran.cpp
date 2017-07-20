#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;


int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		ll n, a[100001];
		scanf("%lld", &n);
		for(ll i=0;i<n;i++)
		{
			scanf("%lld", &a[i]);
		}
		std::sort(a, a+n);
		if(abs(a[1]-a[0]) > 1)
		{
			printf("%lld\n", a[0]);
			continue;
		}
		else if(abs(a[n-1]-a[n-2]) > 1)
		{
			printf("%lld\n", a[n-1]);
			continue;
		}
		else
		{
			for(ll i=1;i<n;i++)
			{
				if(a[i]-a[i-1]==0)
				{
					printf("%lld\n", a[i]);
					break;
				}
			}
		}
		
	}
}
		

