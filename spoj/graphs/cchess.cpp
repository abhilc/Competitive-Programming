#include<iostream>
#include<vector>
#include<queue>
#define max_x 8
#define max_y 8
#define INF 1000000000
using namespace std;

bool visited[8][8];
int dist, nx, ny;
int x1,y1,dx,dy;
int mat[8][8];

int bfs(int sx, int sy)
{
	visited[sx][sy] = 1;
	std::queue<pair<int, int> > q;

	q.push(make_pair(sx, sy));

	while(!q.empty())
	{
		pair<int, int> v = q.front();
		q.pop();
		int mx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
		int my[8] = {2, -2, 2, -2, 1, -1, 1, -1};
		for(int i=0;i<8;i++)
		{
			nx = v.first + mx[i];
			ny = v.second + my[i];
			if(mat[nx][ny] > (mat[v.first][v.second] + (v.first*nx) + (v.second*ny)) && nx < 8 && nx >= 0 && ny < 8 && ny >= 0)
			{
				mat[nx][ny] = mat[v.first][v.second] + (v.first*nx + v.second*ny);
				visited[nx][ny] = 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	return mat[dx][dy]==INF?-1:mat[dx][dy];
}


int main()
{
	while(scanf("%d %d %d %d", &x1, &y1, &dx, &dy) != EOF)
	{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			mat[i][j] = INF;
		}
	}
	mat[x1][y1] = 0;
	printf("%d\n", bfs(x1, y1));
	}
}
	
		

