#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
typedef std::pair<int,int> ii;
typedef std::vector<ii> vii;
using namespace std;


int C, R;
char grid[1005][1005];
int mxwt[1005][1005];
bool visited[1005][1005];

bool isValid(int x, int y)
{
	return x>=0 && x<R && y>=0 && y<C && grid[x][y]=='.';
}	



void bfs(int x, int y)
{
	queue<pair<pair<int, int>, int> > q;
        q.push({{x, y}, 0});
	visited[x][y] = true;
	mxwt[x][y] = 0;
	while(!q.empty())
	{
		pair<pair<int, int>, int> root = q.front();
		//int x = root.first.first, y = root.second.second, wt = root.second;
		pair<int, int> node = root.first;
		int x = node.first, y = node.second, wt = root.second;

		int dx[4] = {0, 0, 1, -1};
		int dy[4] = {1, -1, 0, 0};

		for(int i=0;i<4;i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(isValid(nx, ny))
			{
				if(!visited[nx][ny])
				{
					visited[nx][ny] = true;
					q.push({{nx, ny}, wt+1});
				}
			}
		}
		mxwt[x][y] = wt;
		q.pop();
	}
}

int main()
{
	int tests;
	scanf("%d", &tests);
	while(tests--)
	{
	scanf("%d%d", &C, &R);
	int sx=-1, sy=-1;

	memset(visited, 0, sizeof(visited));
	memset(mxwt, 0, sizeof(mxwt));

	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			cin >> grid[i][j];
			if(grid[i][j]=='.')
			{
				sx = i;
				sy = j;
			}
		}
	}
	if(sx==-1 && sy==-1)
	{
		cout << "Maximum rope length is 0." << "\n";
		continue;
	}
	
	bfs(sx, sy);
	int maxRoot = 0, mx=0, my=0;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(maxRoot < mxwt[i][j])
			{
				maxRoot = mxwt[i][j];
				mx = i;
				my = j;
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	memset(mxwt, 0, sizeof(mxwt));
	bfs(mx, my);
	maxRoot = 0;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(maxRoot < mxwt[i][j])
				maxRoot = mxwt[i][j];
		}
	}
	cout << "Maximum rope length is " << maxRoot << ".\n";
	}
}



