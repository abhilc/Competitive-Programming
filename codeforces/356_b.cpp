#include<iostream>
using namespace std;


int main()
{
	int n, curr;
	scanf("%d %d", &n, &curr);

	int a[101];
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &a[i]);
	}

	int ans = 0;
	if(a[curr]==1)
		ans++;

	for(int dist=1;dist<n;dist++)
	{
		int rcity = curr + dist;
		int lcity = curr - dist;

		if(lcity>0 && rcity<=n)
		{
			if(a[lcity]== 1 && a[rcity]==1)
			{
				ans+=2;
			}
		}
		else if(lcity <= 0 && rcity <= n)
		{
			if(a[rcity]==1)
			{
				ans+=1;
			}
		}
		else if(lcity >0 && rcity >n)
		{
			if(a[lcity]==1)
				ans+=1;
		}
	}
	cout << ans;
}

				
