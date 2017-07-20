#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;




int main()
{
	int tests;
	cin >> tests;
	
	while(tests--)
	{
		ll n, a[500001], b[500001];
		vector<int> p;

		cin >> n;
		
		for(ll i=1;i<=2*n;i++)
		{
			cin >> a[i];
		}

		sort(a+1, a+(2*n+1));

		for(ll i=1;i<=n;i++)
		{
			b[i] = std::max(a[i], a[(2*n+1)-i]);

		}

		for(ll i=1;i<=n;i++)
		{
			p.push_back(a[i]);
			p.push_back(a[(2*n+1)-i]);
		}


		sort(b+1, b+n+1);


		cout << b[n/2+1] << "\n";

		for(ll i=0;i<p.size();i++)
			cout << p[i] << " ";

		cout << "\n";
	}
}
