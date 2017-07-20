#include<iostream>
using namespace std;


int main()
{
	string s;
	cin >> s;

	int ans = 0;
	
	for(int i=0;i<s.length()-1;i++)
	{
		if(s[i] != s[i+1])
			ans++;
	}
	if(s[s.length()-1]=='1')
		ans++;

	cout << ans << "\n";
}



