#include<cstdio>
#include<vector>
#include<string>
#include<iostream>


using namespace std;

int main()
{
	int m;
	scanf("%d", &m);
	string s;
	vector<vector<int> >frnd(m, vector<int>(m));
	vector<int>graph[2001];
	for(int i=0;i<m;i++)
	{
		cin >> s;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]=='1')
			{
				frnd[i][j] = 1;
				frnd[j][i] = 1;
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	int count = 0;
	vector<vector<int> >mark(m, vector<int>(m));
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(frnd[i][j]==0 && i!=j && mark[i][j]==0)
			{
				for(int k=0;k<graph[j].size();k++)
				{
					if(frnd[i][graph[j][k]]==1)
					{
						mark[i][j] = 1;
						count++;
						break;
					}
				}
			}
		}
	}
	printf("%d\n", count);
	return 0;
}

