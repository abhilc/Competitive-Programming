#include<iostream>
using namespace std;


int main()
{
	int tests;
	cin >> tests;

	while(tests--)
	{
		string s;
		cin >> s;
		char prev='X';
		long long totsigns = 0, nog=0, nol=0, nopairs=0, noeq=0;

		for(int i=0;i<s.length();i++)
		{
			if(prev=='X' && s[i]!='=')
				prev=s[i];

			else if(s[i]=='>')
			{
				if(prev=='<')
				{
					nopairs++;
					prev='>';
				}
				nog++;
			}
			else if(s[i]=='<')
			{
				if(prev=='>')
				{
					nopairs++;
					prev='<';
				}
				nol++;
			}
			else 
				noeq++;
		}
	}
}


