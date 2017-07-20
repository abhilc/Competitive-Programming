#include<iostream>
using namespace std;


int main()
{
	string s;
	cin >> s;
	int idx = 0;
	int ans = 0;
	int mark = 0;
	int n = s.length();
	s = " " + s;
	n++;

	for(int i=0;i<n;i++)
	{
		if(s.substr(i, 4)=="bear")
		{
			ans += ((i-mark) * (n - (i+2) - 1));
			mark = i;
		}
	}
	cout << ans;
}

		

