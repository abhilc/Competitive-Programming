#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int a[501][501], n, width = 0, ones = 0;
		scanf("%d", &n);

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d", &a[i][j]);
				if(a[i][j]==1)
				{
					ones++;
				}
			}
		}

		int count[2*n], tcount = n;

		count[0] = n;
		if(ones <= n)
		{
			printf("%d\n", width);
			continue;
		}
		else
		{
			for(int i=1;i<n;i++)
			{
				width++;
				
				count[i] = (n-i) * 2;
				tcount += count[i];
				if(ones <= tcount)
				{
					printf("%d\n", width);
					break;
				}
			}
		}
	}
}



		
