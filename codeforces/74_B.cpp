#include<iostream>
using namespace std;



int main()
{
	int ans = -999999999;
	int n, a[1001];
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		cin >> a[i];

	for(int i=0;i<n;i++)
	{
		int pick = a[i];
		int c = 1;
		
		for(int j=i-1;j>=0;j--)
		{
			if(a[j]<=pick)
			{
				c++;
				pick = a[j];
			}
			else
				break;
		}
		pick = a[i];
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<=pick)
			{
				c++;
				pick = a[j];
			}
			else
				break;
		}
		ans = max(ans, c);
	}
	cout << ans;
}
