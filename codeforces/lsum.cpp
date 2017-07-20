#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	int l, s;
	string ans = "";
	
	cin >> s;

	while(s > 9)
	{
		ans+='9';
		s-=9;
	}
	ans += std::to_string(s);

	if( l < ans.length())
		cout << -1 << " " << -1;
	else if( l == ans.length())
	{
		std::reverse(ans.begin(), ans.end());
		cout << ans;
		std::reverse(ans.begin(), ans.end());
		cout << ans;
	}
	int n = ans.length();
	else 
	{

		




	cout << ans;

		


		




	
}
