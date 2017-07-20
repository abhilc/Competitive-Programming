#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	std::ios::sync_with_stdio(false);
	int k;
	string str;
	scanf("%d", &k);
	cin >> str;
	long long ans = 0;
	string orig, rev;

	for(int i=0;i<=str.length()-k;i++)
	{
		rev = str.substr(i, i+k);
		std::reverse(rev.begin(), rev.end());
		orig = str.substr(i, i+k);
		if(orig==rev)
			ans++;
	}
	printf("%lld\n", ans);
}
