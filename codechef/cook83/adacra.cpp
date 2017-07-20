#include<iostream>
using namespace std;


int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		string s;
		cin >> s;
		int segu = 0, segd = 0;
		char prev = 'X';
		for(int i=0;i<s.length();i++)
		{
			if(prev!=s[i])
			{
				if(s[i]=='D')
				{
					segd++;
					prev = 'D';
				}
				else
				{
					segu++;
					prev = 'U';
				}
			}
		}
		cout << std::min(segd, segu) << "\n";
	}
}
