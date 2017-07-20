#include<iostream>
using namespace std;


int main()
{
	char a[11][11];

	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			cin >> a[i][j];

	int c = 0;
	int dot;

	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(a[i][j] == 'K')
			{
				if(j + 5 < 10)
				{
					dot = 0;
					for(int k=j;k<j+5;k++)
					{
						if(a[i][k]=='X')
							c++;
						else if(a[i][k]=='.')
							dot++;
					}
				}
				if((c + dot)==4)
				{
					cout << "YES\n";
					return 0;
				}
				if(i+5<10)
				{
					c = 0;
					dot = 0;
					for(int k=i;k<i+5;k++)
					{
						if(a[k][j]=='X' && a[k][j]!='O')
						{
							c++;
						}
						else if(a[k][j]=='.')
							dot++;
					}
				}
				if(c + dot == 4)
				{
					cout << "YES\n";
					return 0;
				}
				if(i+5 < 10 && j+5 < 10)
				{
					c = 0;
					dot = 0;
					int p = j;
					for(int k=i;k<i+5;k++)
					{
						if(a[k][p] == 'X')
						{
							c++;
							p++;
						}
						else if(a[k][p]=='.')
						{
							dot++;
							p++;
						}
					}
				}
				if(c + dot == 4)
				{
					cout << "YES\n";
					return 0;
				}
			}
		}
	}
	cout << "NO\n";
	return 0;
}


