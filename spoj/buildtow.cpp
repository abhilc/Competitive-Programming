#include<iostream>
using namespace std;


long long fib(long long n)
{
	long long prev = 1, curr = 0, next, ans = 0;

	for(long long i=1;i<=n;i++)
	{
		next = prev + curr;
		prev = curr;
		curr = next;

		ans += (curr % 1000000007 * curr % 1000000007)%1000000007;

	}
	return ans - 1;
}



int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long p;
		cin >> p;
		cout << fib(p + 1) << "\n";
	}
}


