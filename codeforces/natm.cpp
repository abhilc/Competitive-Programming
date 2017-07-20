#include<iostream>
using namespace std;



int main()
{
	string s;
	cin >> s;
	int from = 0, to, ans = 0, dist;
	for(int i=0;i<s.length();i++)
	{
		to = s[i] - 97;
		dist = abs(from - to);
		ans += std::min(abs(dist), abs(dist - 26));
		from = to;
	}
	cout << ans;

}
