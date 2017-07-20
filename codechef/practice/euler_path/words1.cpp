#include<iostream>
#include<vector>
using namespace std;

vector<int>  ind[100001];
vector<int> adj[100001];
int in[30], out[30];
bool g[100001];


void dfs(int curr)
{
	int k;
	for(k = 0;k<adj[curr].size();k++)
	{
		if(g[ind[curr][k]]==false)
		{
			g[ind[curr][k]] = true;
			dfs(adj[curr][k]);
		}
	}
};

string s;



int main()
{
	int T;
	scanf("%d", &T);
	int i, id, n;

	while(T--)
	{
		int n;
		scanf("%d", &n);
		
		for(i=0;i<n;i++)
		{
			cin >> s;
			adj[s[0] - 'a'].push_back(s[s.length()-1]-'a');
			ind[s[0] - 'a'].push_back(i);
			in[s[s.length()-1]-'a']++;
			out[s[0]-'a']++;

		}
			
		for(i=0;i<26;i++)
		{
			if(in[i]!=out[i] && out[i] > in[i])
			{
				dfs(i);
				break;
			}
			else if(out[i] > 0)
			{
				id = i;
			}
		}
		if(i==26)
		{
			dfs(id);
		}

		for(i=0;i<n;i++)
		{
			if(g[i]==false)
				break;
		}
		if(i < n)
			cout << "The door cannot be opened.\n";
		else
		{
			int cnt = 0, flag = 0;
			for(i=0;i<26;i++)
			{
				if(in[i]!=out[i])
				{
					if(out[i]==in[i]-1 || out[i]==in[i]+1)
						cnt++;
					else
						flag = 1;
				}
			}
			if(flag)
				cout << "The door cannot be opened.\n";
			else
			{
				if(cnt==0||cnt==2)
					cout << "Ordering is possible.\n";
				else
					cout << "The door cannot be opened.\n";
			}
		}
		for(i=0;i<n;i++)
			g[i] = false;
		for(i=0;i<26;i++)
		{
			adj[i].clear();
			ind[i].clear();
			in[i] = 0;
			out[i] = 0;
		}
	}
	return 0;
}

