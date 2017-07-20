#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
#include<set>
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
using namespace std;
 
const int nmax = 10100001;
set<int> S;
map<int, int> mymap;
int a[50001], N, ans[50001];
vector<int> g[50001];
int u, v;
 
void solve()
{
	for(int i=1;i<=N;i++)
	{
		S.erase(a[i]);
		for(int k=0;k<g[i].size();k++)
		{
			S.erase(a[g[i][k]]);
		}
 
		if(!S.empty())
			ans[i] = *S.rbegin();
		else
			ans[i] = 0;
 
		S.insert(a[i]);
		for(int k=0;k<g[i].size();k++)
			S.insert(a[g[i][k]]);
 
		if(ans[i])
			cout << mymap[ans[i]] << " ";
		else
			cout << 0 << " ";
 
	}
	cout << "\n";
 
}
			
 
 
int main()
{
	int tests;
	cin >> tests;
	while(tests--)
	{
		cin >> N;
		std::fill(a, a+N, 0);
		std::fill(ans, ans+N, 0);
		S.clear();
		mymap.clear();
		for(int i=1;i<N;i++)
			g[i].clear();
		for(int i=1;i<=N;i++)
		{
			cin >> a[i];
			mymap[a[i]] = i;
			S.insert(a[i]);
		}
		for(int i=1;i<N;i++)
		{
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			//cout << g[i].size();
		}
		/*for(int i=1;i<N;i++)
			cout << g[i].size();*/
 
		
 
		solve();
			
	}
}
