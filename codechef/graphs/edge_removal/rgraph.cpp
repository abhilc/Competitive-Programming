#include<iostream>
#include<set>
using namespace std;

const int nax = 105;
int in[nax][nax];


void solve()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> in[i][j];

	set<int> vertices;
	for(int i=0;i<n;i++)
		vertices.insert(i);

	while(!vertices.empty())
	{
		if(vertices.size()==1)
		{
			cout << 0 << "\n";
			return;
		}

		bool removed = false;
		for(int x: vertices)
		{
			set<int> values;
			for(int y: vertices)
			       	if(y!=x)
				values.insert(in[x][y]);
			if(values.size()==1)
			{
				vertices.erase(x);
				removed = true;
				break;
			}
		}
		if(!removed) break;
	}
	printf("%d\n", (int) vertices.size());
}


int main()
{
	int T;
	cin >> T;
	while(T--)
		solve();
}

