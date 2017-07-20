#include<iostream>
#include<set>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n+1];

	for(int i=0;i<n;i++)
		cin >> a[i];

	int prev = a[1] - a[0];

	for(int i=2;i<n;i++)
	{
		if(a[i]-a[i-1] > 0)
		{
			if(prev <= 0)
			{
				printf("NO\n");
				return 0;
			}
		}
		else if(a[i]-a[i-1] < 0)
		{
			if(prev > 0)
				prev = -1;
		}
		else if(a[i]-a[i-1]==0)
		{
			if(prev < 0)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
}


