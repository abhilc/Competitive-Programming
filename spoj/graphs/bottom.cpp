#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

#define MAXN 5001

using namespace std;

vector<int> graph[MAXN + 1], graphT[MAXN + 1], sorted, ans[MAXN+1];
bool visited[MAXN + 1];
int comp[MAXN + 1], outdeg[MAXN + 1], indeg[MAXN+1], indeg1[MAXN+1], sol[MAXN+1];


void dfs1(int S)
{
	visited[S] = true;
	//cout << "Visited: " << S;
	for(int j=0;j<graph[S].size();j++)
	{
		//cout << "in here!!\n";
		if(!visited[graph[S][j]])
		{
			dfs1(graph[S][j]);
		}
	}
//	cout << "PUSHING " << S <<" to stack\n";
	sorted.push_back(S);
}

void dfs2(int S, int c)
{

	visited[S] = false;
	comp[S] = c;
	ans[c].push_back(S);
	for(int j=0;j<graphT[S].size();j++)
	{
		if(visited[graphT[S][j]])
		{
			dfs2(graphT[S][j], c);

		}
	}
}



int main()
{
	int v, e, p, q;
	bool flag = 0;
	while(1)
	{

		scanf("%d", &v);
		if(v!=0)
			scanf("%d", &e);
		else
			break;

		for(int i=0;i<5001;i++)
		{
			graph[i].clear();
			graphT[i].clear();
			visited[i] = 0;
			sol[i] = 0;
			sorted.clear();
		}

		for(int i=1;i<=e;i++)
		{
			scanf("%d %d", &p, &q);
			graph[p].push_back(q);
			graphT[q].push_back(p);
		}
		int compon=0;

		for(int i=1;i<=v;i++)
		{
			if(!visited[i])
			{
				dfs1(i);
			}
		}


		for(int i=sorted.size()-1;i >= 0;--i)
		{
			if(visited[sorted[i]])
			{
				dfs2(sorted[i], compon++);
				sol[compon-1] = true;
			}
		}
		for(int i=1;i<=v;i++)
		{
			for(int j=0;j<graph[i].size();j++)
			{
				if(comp[i] != comp[graph[i][j]])
				{
					sol[comp[i]] = false;
					break;
				}
			}
		}
		for(int i=1;i<=v;i++)
		{
			if(sol[comp[i]])
				printf("%d ", i);
		}	

		printf("\n");
	}
}


