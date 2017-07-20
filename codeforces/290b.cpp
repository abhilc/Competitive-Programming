#include<iostream>
#include<cstring>
using namespace std;

string board[51];
bool visited[51][51];

int fx[4] = {0, 0, 1, -1};
int fy[4] = {1, -1, 0, 0};
int n, m;

bool findcycle = 0;

void dfs(int x, int y, int fromx, int fromy, char needcolor)
{
	if(x<0 || x>=n || y<0 || y>=m || board[x][y] != needcolor)
		return;

	if(visited[x][y])
	{
		findcycle = true;
		return;
	}

	visited[x][y] = true;

	for(int i=0;i<4;i++)
	{
		int nextx = x + fx[i];
		int nexty = y + fy[i];

		if(nextx == fromx && nexty == fromy)
			continue;

		dfs(nextx, nexty, x, y, needcolor);
	}
}



int main()
{
	cin >> n >> m;

	for(int i=0;i<n;i++)
		cin >> board[i];

	memset(visited, false, sizeof(visited));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!visited[i][j])
				dfs(i, j, -1, -1, board[i][j]);
		}
	}

	cout << (findcycle?"Yes":"No") << endl;
	return 0;
}

