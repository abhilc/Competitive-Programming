#include<iostream>
using namespace std;



int main()
{
	int r, c;
	char Pcolor;

	char gp[101][101];

	cin >> r >> c >> Pcolor;

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin >> gp[i][j];
		}
	}

	int sr, sc, lr, lc;
	bool found = 0;

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(gp[i][j]==Pcolor)
			{
				sr = i;
				sc = j;
				found = 1;
				break;
			}
		}
		if(found)
			break;
	}

	found = 0;

	for(int i=r-1;i>=0;i--)
	{
		for(int j=c-1;j>=0;j--)
		{
			if(gp[i][j]==Pcolor)
			{
				lr = i;
				lc = j;
				found = 1;
				break;
			}
		}
		if(found)
			break;

	}


	char prev = '*';
	int count = 0;

	if(sr-1>=0)
	{
		for(int i=sc;i<=lc;i++)
		{
			if(gp[sr-1][i]!='.' && gp[sr-1][i]!=prev)
			{
				count++;
				prev = gp[sr-1][i];
			}
		}
	}

	prev = '*';

	if(lr+1<r)
	{
		for(int i=sc;i<=lc;i++)
		{
			if(gp[lr+1][i]!='.' && gp[lr+1][i]!=prev)
			{
				count++;
				prev = gp[sr+1][i];
			}
		}
	}

	prev = '*';

	if(sc-1>=0)
	{
		for(int i=sr;i<=lr;i++)
		{
			if(gp[i][sc-1]!='.' && gp[i][sc-1]!=prev)
			{
				count++;
				prev = gp[i][sc-1];
			}
		}
	}

	prev = '*';

	if(lc+1<c)
	{
		for(int i=sr;i<=lr;i++)
		{
			if(gp[i][lc+1]!='.' && gp[i][lc+1]!=prev)
			{
				count++;
				prev = gp[i][lc+1];
			}
		}
	}

	cout << count << "\n";
}

	


	
			
