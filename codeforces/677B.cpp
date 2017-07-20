#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;

int main()
{
	ll n, h, k, a[100001], i = 0;
	cin >> n >> h >> k;

	for(i=0;i<n;i++)
	{
		cin >> a[i];
	}

	ll ans = 0, rem = a[0];
	
	for(i = 1;i<n;i++)
	{
		ans += (rem/k);
		rem = rem%k;
		
		if(rem + a[i] <= h)
		{
			rem += a[i];
		}
		else
		{
			ans++;
			rem = a[i];
		}
	}
	while(rem > 0 && rem > k)
	{
		ans += rem/k;
		rem = rem%k;
	}
	if(rem > 0)
		ans++;
	cout << ans << "\n";
}


