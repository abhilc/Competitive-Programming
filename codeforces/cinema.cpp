#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;

int a, s;

int main()
{
	map<int, int> mp;
	vector<pair<long, long> > v1(200001, std::make_pair(0, 0));
	int n, m;
	cin >> n;
	int p;
	for(int sc=1;sc<=n;sc++)
	{
		cin >> p;
		mp[p]++;

	}
	cin >> m;
	for(int i=0;i<m;i++)
	{
		cin >> a >> s;
		v1.pb({a, s});
	}
	int idx = -1;
	int val = -999;

	


	

}





