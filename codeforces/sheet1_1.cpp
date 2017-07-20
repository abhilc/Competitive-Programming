#include<iostream>
using namespace std;




int main()
{
	int n, h;
	scanf("%d %d", &n, &h);

	int sum = 0, k;
	for(int i=0;i<n;i++)
	{
		scanf("%d", &k);
		if(k>h)
			sum+=2;
		else
			sum+=1;
	}
	printf("%d", sum);
}
