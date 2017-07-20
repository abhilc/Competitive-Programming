#include<iostream>
using namespace std;



int main()
{
	int n;
	scanf("%d", &n);
	int sum = 0, a[n+1];
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	int ans = 0;

	for(int i=0; i<n;i++)
	{
		if((sum - a[i])%2==0)
			ans++;
	}
	printf("%d", ans);
}
