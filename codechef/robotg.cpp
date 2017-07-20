#include<iostream>
using namespace std;



int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int r, c;
		string s;
		scanf("%d %d", &r, &c);
		cin >> s;
		int nr, nc;
		bool success;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				int p = i;
				int q = j;
				success = 1;
				nr = 0, nc=0;
				for(int k=0;k<s.length();k++)
				{
					if(s[k]=='L')
					{
						nc = --q;
					}
					else if(s[k]=='R')
					{
						nc = ++q;
					}
					else if(s[k]=='U')
					{
						nr = --p;
					}
					else if(s[k]=='D')
					{
						nr = ++p;
					}
					if(nr < 0 || nr >= r || nc < 0 || nc >= c)
					{
						success = 0;
						break;
					}
				}
				if(success)
				{
					cout << "safe\n";
					break;
				}
			}
			if(success)
				break;
		}
		if(!success)
			cout << "unsafe\n";
	}
}


