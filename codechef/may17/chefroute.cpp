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
		int l = 0;


		while(s[l]=='C')
			l++;
			
		if(l < s.length())
		{
			while(s[l] == 'E')
			{
				l++;
			}

			if(l < s.length())
			{
				while(s[l] == 'S')
					l++;

				if(l < s.length())
				{
					cout << "no\n";
					continue;
				}
				
				else
				{
					cout << "yes\n";
					continue;
				}
			}
			else
			{
				cout << "yes\n";
				continue;
			}
			
		}
		
		else
		{
			cout << "yes\n";
			continue;
		}
	}
}
