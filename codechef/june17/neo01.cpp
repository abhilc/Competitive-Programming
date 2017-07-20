#include<iostream>
#include<algorithm>
#include<vector>
typedef long long LL;
#define pb push_back

using namespace std;


int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		vector<LL> neg;
		LL p, N, summ = 0, pcount = 0;
		cin >> N;

		for(int i=0;i<N;i++)
		{
			cin >> p;
			if(p < 0)
			{
				neg.pb(abs(p));
			}
			else
			{
				pcount++;
				summ += p;
			}
		}
		sort(neg.begin(), neg.end());

		LL sum = summ;
		LL ans = pcount * summ;

		for(int i=0;i<neg.size();i++)
		{
			if((sum - neg[i])*(pcount+1) > ans)
			{
				ans = (sum - neg[i])*(pcount+1);
				sum -= neg[i];
				pcount++;
			}
			else
			{
				for(int x = i;x<neg.size();x++)
					ans -= neg[x];
				break;
			}
		}
		cout << ans << "\n";
	}
}

