#include<iostream>
#include<cmath>
#include<set>
using namespace std;



int main()
{
	int n;
	scanf("%d", &n);

	int a[n+1], i, p;
	multiset<int> S;
	int l = 0;
	int mx = -1;

	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
		S.insert(a[i]);

		while(abs(*S.rbegin() - *S.begin())>1)
			S.erase(S.lower_bound(a[l++]));

		mx = max(mx, i-l+1);
		
	}
	cout << mx << "\n";
}
	
