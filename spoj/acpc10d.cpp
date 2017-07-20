#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define N 13
#define INF 1000000001
int arr[13][13];
typedef std::pair<int, int> ii;
std::vector<ii> adjList[13];
std::vector<int> dist(N, INF);

using namespace std;



void buildGraph()
{
	int conns[13][13], i, j;
	conns[1][2] = 1;
	conns[1][5] = 1;
	conns[1][4] = 1;
	conns[2][3] = 1;
	conns[2][4] = 1;
	conns[2][5] = 1;
	conns[3][6] = 1;
	conns[3][5] = 1;
	conns[4][5] = 1;
	conns[4][7] = 1;
	conns[4][8] = 1;
	conns[5][8] = 1;
	conns[5][7] = 1;
	conns[5][9] = 1;
	conns[6][9] = 1;
	conns[6][8] = 1;
	conns[7][8] = 1;
	conns[7][10] = 1;
	conns[7][11] = 1;
	conns[8][10] = 1;
	conns[8][11] = 1;
	conns[8][12] = 1;
	conns[9][12] = 1;
	conns[9][11] = 1;
	conns[10][11] = 1;
	conns[11][12] = 1;

	for(i=1;i<=4;i++)
	{
		for(j=1;j<=3;j++)
		{
			if(conns[i][j])
			{
				adjList[i].push_back(make_pair(j, arr[i][j]));
			}
		}
	}
}


void solve()
{
	priority_queue< ii, std::vector<ii>, greater<ii>  >  pq;
	int s = 2;
	dist[s] = 0;
	pq.push(make_pair(0, s));

	while(!pq.empty())
	{
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		for(int j=0;j<adjList[u].size();j++)
		{
			ii v = adjList[u][j];
			if(d > dist[u]) continue;

			if(dist[u] + v.second < dist[v.first])
			{
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
}


int main()
{
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=3;j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	buildGraph();
	solve();
	cout << dist[11] << "\n";
}
