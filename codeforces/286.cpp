#include<iostream>
#include<cstring>
#include<vector>
typedef long long ll;
typedef std::pair<int, int> pi;
using namespace std;

vector<pi> gp[105];
bool visited[5001];
ll res = 0;

bool dfs(int s, int col, int dst)
{
	visited[s] = 1;


	if(s == dst)
	{
		return 1;
	}
	
	for(int i=0;i<gp[s].size();i++)
	{
		if(!visited[gp[s][i].first] && gp[s][i].second == col)
		{
			visited[gp[s][i].first] = 1;
			if(dfs(gp[s][i].first, col, dst))
				return true;
		}
	}
	return false;
}

int main()
{
	int n, m, q;
	cin >> n >> m;
	
	int x, y, c;
	while(m--)
	{
		cin >> x >> y >> c;
		gp[x].push_back(make_pair(y, c));
		gp[y].push_back(make_pair(x, c));
	}
	cin >> q;
	int s, d;

	while(q--)
	{
		res = 0;
		cin >> s >> d;

		
		for(int i=1;i<=100;i++)
		{
			memset(visited, 0, sizeof(visited));
			if(dfs(s, i, d))
				res++;
		}
		cout << res << "\n";
	}
}




