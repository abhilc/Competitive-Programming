#include<iostream>
using namespace std;



int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, a[20001],b[20001], i, j, sum1=0, sum2=0;
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d", &a[i]);

		for(int j=0;j<n;j++)
			scanf("%d", &b[j]);

		for(int i=0;i<n;i+=2)
		{
			sum1+=a[i];
		}
		for(int i=1;i<n;i+=2)
		{
			sum1+=b[i];
		}
		for(int i=0;i<n;i+=2)
		{
			sum2+=b[i];
		}
		for(int i=1;i<n;i+=2)
		{
			sum2+=a[i];
		}
		printf("%d\n", std::min(sum1, sum2));


	}
}

