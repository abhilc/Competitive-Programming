#include<iostream>
using namespace std;

int ans = 0;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string s;
		cin >> s;
		
		ans += (s[1]=='+')?1:-1;

	}
	cout << ans << "\n";
}
