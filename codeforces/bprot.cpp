#include<iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;

	string s;
	cin >> s;
	string ans;

	int z = 0, c=0;
	bool seen = false;
	int scount = 0;


	for(int i=;i<s.length();i++)
	{
		if(s[i]=='1')
		{
			c++;

		}
		else if(s[i]=='0' && scount%2==0)
		{
			scount++;
			if(c>0)
				ans += std::to_string(c);
			c = 0;
			
		}
		else if(s[i]=='0' && scount%2==1)
		{
			ans += '0';
			scount++;
		}
	}
	if(c > 0)
		ans += std::to_string(c);
	cout << ans << "\n";
}

