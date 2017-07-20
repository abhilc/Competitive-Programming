#include<iostream>
using namespace std;


int main()
{
	int a, n, k, j;
	cin >> a >> n >> k;
	int i = n+1;
	while(k--)
	{
		j = a%i;
		cout << j << " ";
		a = a/i;
	}
}
