#include<iostream>
#include<map>
typedef std::pair<int, int> pii;
using namespace std;

map<int, pii> prop[1000001];

void solve()
{
	int n, q;
	scanf("%d%d", &n, &q);

	int id, attr, val, prio;

	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d", &id, &attr, &val, &prio);

		if(prop[id].find(attr) == prop[id].end())
			prop[id][attr] = pii(val, prio);
		else
		{
			int curr_prio = prop[id][attr].second;
			if(curr_prio <= prio)
				prop[id][attr] = pii(val, prio);
		}
	}

	for(int i=0;i<q;i++)
	{
		int id, attr;
		scanf("%d%d", &id, &attr);
		printf("%d\n", prop[id][attr].first);
	}
}

int main()
{
	solve();
}

