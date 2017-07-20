#include<iostream>
typedef long long LL;
#include<algorithm>
using namespace std;



int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int k, wt[11], cost[11];
		int n;
		scanf("%d%d", &n, &k);


		for(int i=0;i<n;i++)
		{
			cin >> cost[i];
			cin >> wt[i];
		}

		LL maxi = -1;

		for(int i=0;i<(1<<n);i++)
		{
			LL tct = 0;
			LL twt = 0;
			for(int j=0;j<n;j++)
			{
				if(i & (1<<j))
				{
					twt += wt[j];
					tct += cost[j];
				}
			}
			if(tct <= k)
				maxi = std::max(maxi, twt);
		}	
		cout << maxi << "\n";
	}
}

