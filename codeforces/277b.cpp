#include<iostream>
using namespace std;


int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int a[101][101], b[101][101];


	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d", &a[i][j]);
			b[i][j] = 1;
		}
	}

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]==0)
			{
				for(int k=0;k<n;k++)
				{
					b[i][k] = 0;
				}
				for(int k=0;k<m;k++)
				{
					b[k][j] = 0;
				}
			}
		}
	}

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			int t = 0;

			for(int k=0;k<m;k++)
				t |= b[k][j];
			for(int k=0;k<n;k++)
				t |= b[i][k];
			
			if(t != a[i][j])
			{
				puts("NO\n");
				return 0;
			}
		}
	}
	puts("YES\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
}


