#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;

vector<vector<int> > gp(100005);

bool visited[100005];

void dfs(int u)
{
	if(visited[u])
		return;
	visited[u] = true;

	for(vector<int>::iterator it = gp[u].begin();it!=gp[u].end();it++)
		if(!visited[*it])
			dfs(*it);
}


int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int v, e, ans = 0, p, q;
		memset(visited, 0, sizeof(visited));



		scanf("%d", &v);
		scanf("%d", &e);

		for(int i=0;i<v;i++)
			gp[i].clear();
		for(int i=0;i<e;i++)
		{
			scanf("%d %d", &p, &q);
			gp[p].push_back(q);
			gp[q].push_back(p);
		}

		for(int i=0;i<v;i++)
		{
			if(!visited[i])
			{
				ans++;
				dfs(i);
			}
		}
		printf("%d\n", ans);
	}
}
		


