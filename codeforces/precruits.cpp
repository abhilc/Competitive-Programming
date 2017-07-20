#include<iostream>
using namespace std;






int main()
{
	int n, ans = 0, c =0;
	scanf("%d", &n);
	int p =0, k;
	for(int i=0;i<n;i++)
	{
		scanf("%d", &k);
		if(k<0)
		{
			c++;
			if(p < c)
			{
				ans++;
				c--;
			}
			else 
			{
				p = p-c;
				c = 0;
			}
		}
		else
		{
			p+=k;
		}
	}
	printf("%d", ans);

}
