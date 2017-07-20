#include<iostream>
#include<queue>
#include<fstream>
#include<vector>
using namespace std;

int n, m, k;

bool visited[2002][2002];

bool isValid(int x, int y)
{
	return (x >=1 && x <= n && y>=1 && y<=m);
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin >> n >> m >> k;



	queue<pair<int, int> > q;
	int u, v;
	int ans[2] = {1, 1};

	for(int i=1;i<=2001;i++)
	{
		for(int j=1;j<=2001;j++)
			visited[i][j] = false;
	}

	for(int i=0;i<k;i++)
	{
		cin >> u >> v;
		visited[u][v] = true;
		q.push({u, v});
	}

	while(!q.empty())
	{
		pair<int, int> vert = q.front();
		q.pop();

		int x[4] = {0, 0, 1, -1};
		int y[4] = {1, -1, 0, 0};

		for(int i=0;i<4;i++)
		{
			int nvertx = vert.first + x[i];
			int nverty = vert.second + y[i];
			//cout << nvertx << " " << nverty << "\n";

			if(isValid(nvertx, nverty) && !visited[nvertx][nverty])
			{
				//cout << "Visiting: " << nvertx << " " << nverty << "\n";
				visited[nvertx][nverty] = true;
				q.push({nvertx, nverty});
				ans[0] = nvertx;
				ans[1] = nverty;
			}
		}
	}

	//cout << ans[0] << " " << ans[1];
	cout << ans[0] << " " << ans[1];
}


