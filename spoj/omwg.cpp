#include<iostream>
using namespace std;

int main()
{
	int tests;
	scanf("%d", &tests);

	while(tests--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		int ans = (n-1)*m + (m-1)*n;
		printf("%d\n", ans);
	}
}
