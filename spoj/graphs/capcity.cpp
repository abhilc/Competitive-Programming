#include<iostream>
#include<algorithm>
#include<vector>

#define MAXN 200000

using namespace std;

vector<int> graph[MAXN + 1], graphT[MAXN + 1], sol;
bool visited[MAXN + 1];
int comp[MAXN + 1], in[MAXN + 1];



void dfs1(int S)
{
	visited[S] = true;
	for(int j=0;j<(int)graph[S].size();j++)
	{
		if(!visited[graph[S][j]])
			dfs1(graph[S][j]);
	}
	sol.push_back(S);
}


void dfs2(int S, int c)
{
	visited[S] = 0;
	comp[S] = c;
	for(int j=0;j<(int)graphT[S].size();j++)
		if(visited[graphT[S][j]])
			dfs2(graphT[S][j], c);
}


int main()
{
	int t, N, j, compon, M, u, count, lim, v, i;
	scanf("%d %d", &N, &M);
	for(i = 1;i<=N;i++)
	{
		visited[i] = false;
		graph[i].clear();
		graphT[i].clear();
		in[i] = 0;
	}
	for(i=1;i<=M;i++)
	{
		scanf("%d %d", &u, &v);
		graph[v].push_back(u);
		graphT[u].push_back(v);
	}

	for(i=1;i<=N;i++)
	{
		if(!visited[i])
			dfs1(i);
	}

	compon = 0;
	
	for(i = sol.size() - 1; i>=0; --i)
	{
		if(visited[sol[i]])
		dfs2(sol[i], compon++);
	}
	lim  = compon;

	for(i=1;i<=N;i++)
	{
		for(int j=0;j<graph[i].size();j++)
		{
			if(comp[i] != comp[graph[i][j]])
				in[comp[graph[i][j]]] += 1;
		}
	}
	count = 0;
	for(i=0;i<lim;i++)
	{
		if(in[i] == 0)
			count++;
	}
	if(count > 1)
		printf("0\n");

	else
	{
		count = 0;
		for(i=1;i<=N;i++)
		{
			if(in[comp[i]] == 0)
				++count;
		}
		printf("%d\n", count);
		for(i=1;i<=N;i++)
		{
			if(in[comp[i]]==0)
				printf("%d ", i);
		}
		printf("\n");
	}
}


