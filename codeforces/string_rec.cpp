#include<iostream>
#include<set>
using namespace std;
const int N=3e6 + 20;

int t, i, k, l, x;
char a[N];
set<int> s;
string ans;

int main()
{
	for(i=0;i<N;i++) ans+='#', s.insert(i);

	scanf("%d", &t);

	while(t--)
	{
		scanf("%s%d", a, &k);
		l = strlen(a);

		for(i=0;i<k;i++)
		{
			scanf("%d", &x);
			x--;

			auto it = s.lower_bound(x);
			s.erase(it);

			for(auto ite=s.begin();it!=s.end();++it)
				cout << ' ' << *it << "\n";
		}
	}
}
