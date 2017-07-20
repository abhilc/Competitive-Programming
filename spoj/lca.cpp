#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int L[1005];
vector<int> tree[1005];
int parent[1005];
int N, p;
int P[1005];

void dfs(int node, int nr)
{
	int k = node;

	if(L[node] < nr)
		P[node] = 1;
	else if((nr != 0) && !(L[node] % nr))
		P[node] = parent[node];
	else
		P[node] = P[parent[node]];

	//For each son k of node
	
	
	for(int i=0;i<tree[node].size();i++)
		
		dfs(tree[k][i], nr);
}


int LCA(int x, int y)
{
	while(P[x]!=P[y])
	{
		if(L[x] > L[y])
			x = P[x];
		else
			y = P[y];
	}

	while(x != y)
	{
		if(L[x] > L[y])
			x = parent[x];
		else
			y = parent[y];
	}
	return x;
}


int main()
{
	int tests;
	cin >> tests;
	int l = 0;

	while(tests--)
	{
		l++;
		memset(parent, 0, sizeof(parent));
		memset(P, 0, sizeof(P));
		memset(L, 0, sizeof(L));
		for(int i=0;i<1005;i++)
			tree[i].clear();

		int ch;
		cin >> N;
		L[1] = 0;
		//parent[1] = 0;
		for(int i=1;i<=N;i++) parent[i] = i;
		for(int i=1;i<=N;i++)
		{
			cin >> ch;

			for(int j=1;j<=ch;j++)
			{
				
				cin >> p;
				parent[p] = i;
				tree[i].push_back(p);
				L[p] = L[i] + 1;
			}
		}
		dfs(1, sqrt(log(N)));
		int q;
		cin >> q;
		int x, y;

		bool flag = 0;

		while(q--)
		{
			cin >> x >> y;
			if(!flag)
			{
				cout << "Case " << l << ":" << "\n";
				flag = 1;
			}
			cout << LCA(x, y) << "\n";
		}
		
		
	}
}
