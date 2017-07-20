#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main()
{
	int N, a[101];
	cin >> N;
	for(int i=1;i<=N;i++)
		cin >> a[i];

	vector<int> cntj, cntk;

	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			for(int k=1;k<=N;k++)
			{
				cntk.push_back((a[i]*a[j]) + a[k]);
				if(a[i]!=0)
					cntj.push_back(a[i]*(a[j] + a[k]));
			}
		}
	}
	int lo = 0;
	int hi = cntj.size() - 1;
	sort(cntj.begin(), cntj.end());
	int ans = 0;


	for(int i=0;i<cntk.size();i++)
	{
		int key = cntk[i];
		ans += std::upper_bound(cntj.begin(), cntj.end(), key) - std::lower_bound(cntj.begin(), cntj.end(), key);
	}

	cout << ans << "\n";
}
