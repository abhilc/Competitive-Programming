#include<iostream>
using namespace std;



int main()
{
	int n;

	scanf("%d", &n);
	int host[n+1], guest[n+1];

	for(int i=0;i<n;i++)
	{
		scanf("%d %d", &host[i], &guest[i]);
	}
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(host[i]==guest[j])
				ans++;
			if(guest[i]==host[j])
				ans++;
		}
	}
	printf("%d", ans);
}
	
