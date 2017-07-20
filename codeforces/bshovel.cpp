#include<iostream>
using namespace std;



int main()
{
	int k, r;
	scanf("%d %d", &k, &r);
	int dig = k%10;
	int ndig = dig;

	int ans = 1, i=2;
	while(1)
	{
		if(ndig%10==r || ndig%10==0)
			break;

		ndig = dig*i;
		ans++;
		i++;
	}
	printf("%d", ans);
}
		
