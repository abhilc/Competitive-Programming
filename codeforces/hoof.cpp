#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	long long a[4];
	for(int i=0;i<4;i++)
		cin >> a[i];

	sort(a, a+4);
	
	int ans=0;
	for(int i=0;i<3;i++)
	{
		if(a[i]==a[i+1])
			ans++;
	}
	printf("%d", ans);
}
