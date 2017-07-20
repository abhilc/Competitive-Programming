#include<iostream>
#include<vector>
using namespace std;

vector<int> a[2505];

void solve()
{
	int c[2505];
	int p, q;


	int N, K;
	scanf("%d%d", &N, &K);
	for(int i = 0; i <= 2502; ++i){
         a[i].clear();
         a[i].resize(0);
      }

	for(int i=0;i<N;i++)
	{
		cin >> p;
		for(int j=0;j<p;j++)
		{
			cin >> q;
			a[i].push_back(q);
		}
	}
	int res1 = 0;

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<2505;j++)
		{
			c[j] = 0;
		}

		for(int l=0;l<a[i].size();l++)
		{
			c[a[i][l]] = 1;
		}

		for(int j = i+1;j<N;j++)
		{
			int c1 = a[i].size();
			for(int l=0;l<a[j].size();l++)
			{
				if(c[a[j][l]]==0)
					c1++;
			}
		if(c1 != K)
			res1++;
		}
	}
	int res = ((N*(N-1))/2) - res1;
	printf("%d\n", res);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		solve();
	}
		
}


