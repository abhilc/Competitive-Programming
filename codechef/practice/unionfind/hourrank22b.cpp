#include<iostream>
typedef long long ll;
#include<algorithm>
#include<vector>
#define ff first
#define ss second
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
using namespace std;


vector<iii> edgeList;
int par[200001];
int sz[200001];

int root(int a)
{
	if(par[a]==a) return a;
	return par[a] = root(par[a]);
}

void unite(int a, int b)
{
	a = root(a), b = root(b);

	if(a==b) return;
	
	if(sz[a] < sz[b]) swap(a, b);
	
	sz[a]+=sz[b];
	
	par[b] = a;
}


int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	int w, a, b;
	int W = 0;

	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d", &a, &b, &w);
		edgeList.push_back(iii(w, ii(a, b)));
	}
	sort(edgeList.begin(), edgeList.end());

	for(int i=1;i<=n;i++)
	{
		sz[i] = 1; par[i] = i;
	}

	ll totcnt = 0;


	for(int i=0;i<m;i++)
	{
		iii edge = edgeList[i];

		int a = edge.ss.ff, b = edge.ss.ss, w = edge.ff;
		if(root(a)==root(b)) continue;
		
		W = max(w, W);
		totcnt += w;


		unite(a, b);
	}

	for(int i=1;i<=n;i++)
	{
		sz[i] = 1; par[i] = i;
	}
	int cnt = 0;

	for(int i = 0;i<m;i++)
	{
		iii edge = edgeList[i];

		int a = edge.ss.ff, b = edge.ss.ss, w = edge.ff;
		if(w < W)
		{
			unite(a, b);
		}
		else
		{
			if(root(a)!=root(b))
			{
				cnt++;
			}
		}
	}

	cout << totcnt - W << " " << cnt << "\n";
}

				


