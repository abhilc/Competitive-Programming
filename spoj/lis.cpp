#include<iostream>
using namespace std;

int a[50];


int lis(int n)
{
	int T[n];
	for(int i=0;i<n;i++)
		T[i] = 1;

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j] < a[i])
			{
				if(T[i] < T[j] + 1)
					T[i] = T[j] + 1;
			}
		}
	}
	int max = -1;
	for(int i=0;i<n;i++)
		if(max < T[i])
			max = T[i];
	return max;
}


int main()
{
	int N;
	cin >> N;

	for(int i=0;i<N;i++)
	{
		cin >> a[i];
	}
	cout << lis(N);
}
