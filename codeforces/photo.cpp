#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;

int main()
{
	long long n, m, sl, sh;
	cin >> n >> m;
	cin >> sl >> sh;
	vector<pair<long long, long long> > ansarr;
	vector<int> an;
	int cl, ch;

	for(int i=0;i<n;i++)
	{
		cin >> cl >> ch;
		ansarr.push_back({(cl*sl + ch*sh), i});
	}
	sort(ansarr.begin(), ansarr.end());
	ll ans = 0;

	for(int i=0;i<ansarr.size();i++)
	{
		pair<ll, ll> val = ansarr[i];
		
		if(val.first <= m)
		{
			m -= val.first;
			ans++;
			an.push_back(val.second + 1);
		}
	}

	cout << ans << "\n";
	for(int i=0;i<an.size();i++)
	{
		cout << an[i] << " ";
	}
}



