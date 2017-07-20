#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;


int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int n, d;

		scanf("%d%d", &n, &d);

		vector<int> startDay(n), lectures(n), sadness(n);

		for(int i=0;i<n;i++)
		{
			cin >> startDay[i] >> lectures[i] >> sadness[i];
			startDay[i]--;
		}

		vector<pair<int, int> > persons;

		for(int i=0;i<n;i++)
		{
			persons.push_back(make_pair(sadness[i], i));
		}

		sort(persons.rbegin(), persons.rend());

		vector<int> lectursTaken(n);
		set<int> daySet;

		for(int i=0;i<d;i++)
			daySet.insert(i);

		for(auto it: persons)
		{
			int lec = lectures[it.second];

			for(int i=0;i<lec;i++)
			{
				auto iter = daySet.lower_bound(startDay[it.second]);

				if(iter == daySet.end())
					break;
				else
				{
					lectursTaken[it.second]++;
					daySet.erase(iter);
				}
			}
		}

		long long ans = 0;

		for(int i=0;i<n;i++)
		{
			ans += (lectures[i] - lectursTaken[i]) * (long long) sadness[i];
		}

		cout << ans << "\n";
	}
}

			
