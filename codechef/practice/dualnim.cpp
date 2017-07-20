#include<iostream>
#include<cstring>
using namespace std;

int a[501];

int main()
{
	int tests;
	cin >> tests;

	while(tests--)
	{
		int N;
		cin >> N;
		memset(a, 0, sizeof(a));
		int ans = 0;
		for(int i=0;i<N;i++)
		{
			scanf("%d", &a[i]);
			ans ^= a[i];
		}
		bool winning = 1;

		if(ans != 0)
		{
			if(N%2==1)
				winning = 0;
		}
		
		puts(winning?"First":"Second");

	}
}
		





