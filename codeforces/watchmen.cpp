#include<iostream>
#include<map>
using namespace std;

map<pair<int, int>, int> mp;
map<int, int> mx, my;


int main()
{
	int n;
	cin >> n;
	int a, b;
	long long cnt = 0;
	for(int i=0;i<n;i++)
	{
		cin >> a >> b;
		cnt += mx[a] + my[b] - mp[make_pair(a, b)],mx[a]++,my[b]++,mp[make_pair(a, b)]++;
	}
	cout << cnt;
}
