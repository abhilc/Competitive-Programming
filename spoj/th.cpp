#include<iostream>
using namespace std;

int steps = 0;

int rec(int n, int src, int dst, int tmp)
{
	if(n > 0 )
	{
		rec(n-1, src, tmp, dst);
		steps++;
		rec(n-1, tmp, dst, src);
	}

	return steps;

	
}


int main()
{
	int n;
	cin >> n;
	cout << rec(n, 1, 2, 3);
}
