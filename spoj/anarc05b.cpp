#include<iostream>
using namespace std;

long long suma = 0, sumb = 0, ans = 0;


int main()
{
	int a[10001] = {0}, b[10001] = {0}, n, m, i, j;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(i=0;i<m;i++)
	{
		scanf("%d", &b[i]);
	}

	i = 0, j=0;
	while(i<n && j<m)
	{
		if(a[i] != b[j])
		{
			suma += a[i];
			sumb += b[j];
			i++;j++;
		}
		else
		{
			ans+=std::max(suma, sumb) + a[i];
			i++;
			j++;
		}
	}
	if(i != n)
	{
		for(int k=i;k<n-1;k++)
		{
			if(a[k] > 0)
				suma += a[k];
		}
	}
	if(j!=m)
	{
		for(int k=j;k<m;k++)
		{
			if(b[j] > 0)
				sumb += b[j];

		}
	}
	ans += std::max(suma, sumb);
	cout << ans << "\n";


}

