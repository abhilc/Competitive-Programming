#include<iostream>
#include<algorithm>
using namespace std;



int main()
{
	int n;
	scanf("%d", &n);
	int p[100001];
	for(int i=0;i<n;i++)
		scanf("%d", &p[i]);

	int q;

	scanf("%d", &q);

	sort(p, p+n);

	for(int i=0;i<q;i++)
	{
		int x;
		bool found = 0;
		scanf("%d", &x);
		int lo = 0, hi = n;

		while(lo < hi)
		{
			int mid = (lo+hi)/2;

			if(p[mid] == x)
			{
				found = 1;
				printf("%d\n", mid+1);
				break;
			}

			if(p[mid] < x)
			{
				lo = mid;
			}
			else
				hi = mid-1;
		}
		if(!found)
		printf("%d\n", lo);
	}
}
		
