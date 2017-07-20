#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
	int n, k, l, r, sa, sk;

	cin >> n >> k >> l >> r >> sa >> sk;
	vector<int> ans(n);
	int ns = (sa-sk);

	for(int i=0;i<k;i++)
	{
		ans[i] = sk/k;
		if(sk%k!=0) ans[i]++, sk--;
	}
	if(n!=k)
	{
		for(int i=k;i<n;i++)
		{
			ans[i] = ns/(n-k);
			if(ns%(n-k)!=0) ns--, ans[i]++;
		}
	}
	random_shuffle(ans.begin(), ans.end());

	for(int i=0;i<ans.size();i++)
		cout << ans[i] << " ";



}
