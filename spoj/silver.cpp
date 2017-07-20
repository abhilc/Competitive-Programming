#include<iostream>
#include<cstdio>
#include<cmath>




int main()
{
	int n;
	while(1)
	{
		scanf("%d", &n);
		if(n==0)
			break;
		int c = 0;
		while(n!=1)
		{
			n/=2;
			c++;
		}
		printf("%d\n", c);
	}
}
