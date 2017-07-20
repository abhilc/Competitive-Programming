#include<iostream>
#include<map>

typedef std::pair<int, int> pi;
#define mp make_pair
#define ff first
#define ss second
using namespace std;



int main()
{
	int tests;
	cin >> tests;

	while(tests--)
	{
		map<pi, int> mymap;
		int N, D, T, L, S;

		cin >> N >> D;

		for(int i=0;i<N;i++)
		{
			cin >> T >> L >> S;
			mymap[mp(T, L)] = S;
		}


		/*for(auto it=mymap.rbegin();it!=mymap.rend();it++)
		{
			cout << it->second << "\n";
		}*/

		long long tot_sadness = 0;
		int given = 0, has_days;

		for(auto it=mymap.begin();it!=mymap.end();it++)
		{
			pi prof = it->first;
			has_days = ((D - prof.ff) + 1) - given;


			if(has_days < prof.ss){
				tot_sadness = tot_sadness + (prof.ss - has_days)*it->second;
			}
				given = D - prof.ss;

		}
		cout << tot_sadness << "\n";



	}
}
