#pragma comment (linker, "/STACK:1073741824")
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <complex>

using namespace std;

#define SZ(x) (int((x).size()))
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i, a, b) for(int (i) = (a); (i) >= (b); --(i))
#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define REPD(i, n) for (int (i) = (n); (i)--; )
#define FE(i, a) for (int (i) = 0; (i) < (int((a).size())); ++(i))
#define MEM(a, val) memset((a), val, sizeof(a))
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define PB push_back
#define PPB pop_back
#define ALL(c) (c).begin(), (c).end()
#define SQR(a) ((a)*(a))
#define MP(a,b) make_pair((a), (b))
#define XX first
#define YY second
#define GET_RUNTIME_ERROR *(int*)(NULL) = 1

typedef vector<int> vint;
typedef vector<long long> vLL;
typedef double dbl;
typedef long double ldbl;
typedef vector<pair<int, int> > vpii;
typedef long long LL;
typedef pair<int, int> pii;

const int nmax = 100100;


const int N = 100005;
int n, e, deg[N];
vector<pii> edgeList;
bool visited[N];
set<int> adj[N];


void check_connectivity(int v)
{
	visited[v] = 1;
	for(auto e: adj[v])
	{
		int vv = v ^ edgeList[e].first ^ edgeList[e].second;
		if(!visited[vv])
		{
			check_connectivity(vv);
		}
	}
}

void euler_dfs(int v)
{
	while(!adj[v].empty())
	{
		int e = (*adj[v].begin());
		int vv = v ^ edgeList[e].first ^ edgeList[e].second;

		cout << "Edge: " << e << "Start " << v << " Next: " << vv << "\n";

		if(edgeList[e].first != v)
		{
			//cout << edgeList[e].first << " " << v << "\n";
			swap(edgeList[e].first, edgeList[e].second);
		}

		adj[v].erase(adj[v].begin());
		adj[vv].erase(e);

		euler_dfs(vv);
	}
}

int main()
{
	cin >> n >> e;

	int a, b;
	for(int i=0;i<e;i++)
	{
		cin >> a >> b;
		adj[a].insert(i);
		adj[b].insert(i);
		deg[a]++; deg[b]++;
		edgeList.push_back(make_pair(a,b));
	}

	check_connectivity(1);

	for(int i=1;i<=n;i++)
	{
		if(deg[i]%2==1 || !visited[i])
		{
			cout << "NO";
			return 0;
		}
	}

	euler_dfs(1);

	cout << "YES\n";
	for(int i=0;i<e-1;i++)
		cout << edgeList[i].first << " " << edgeList[i].second << "\n";

	cout << edgeList[e-1].first << " " << edgeList[e-1].second;

	return 0;
}
