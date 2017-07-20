#include<iostream>
#include<vector>
#include<queue>
#define max_x 8
#define max_y 8
#define INF 1000000000
using namespace std;

bool visited[8][8];
int dist, nx, ny;
int m,n,xd,yd,T;
int mat[101][101];
int cost[101][101];

int bfs(int sx, int sy)
{
	visited[sx][sy] = 1;
	std::queue<pair<int, int> > q;

	q.push(make_pair(sx, sy));

	while(!q.empty())
	{
		pair<int, int> v = q.front();
		q.pop();
		int mx[4] = {1, -1, 0, 0};
		int my[4] = {0, 0, 1, -1};
		for(int i=0;i<4;i++)
		{
			nx = v.first + mx[i];
			ny = v.second + my[i];
			if(mat[nx][ny] > (mat[v.first][v.second] + cost[nx][ny]) && nx>=0 && nx<m && ny>=0 && ny<n)
			{
				mat[nx][ny] = mat[v.first][v.second] + cost[nx][ny];
			//	cout << mat[nx][ny] << "\n";
				q.push(make_pair(nx, ny));
			}
		}
	}
	return mat[xd-1][yd-1];
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &m, &n);
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d", &cost[i][j]);
				
			}
		}
		scanf("%d %d %d", &xd, &yd, &T);

		for(int i=0;i<101;i++)
			for(int j=0;j<101;j++)
				mat[i][j] = INF;

		mat[0][0] = cost[0][0];
		
		//cout << bfs(0, 0);

		int val = bfs(0, 0);
		val > T?printf("NO\n"):printf("YES\n%d\n", T-val);
	}
}
			
