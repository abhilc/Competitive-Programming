#include<iostream>
using namespace std;



int main()
{
	int n1, n2, n3, p, q, r;
	long long a[500001] = {0};
	//cin >> n1 >> n2 >> n3;
	scanf("%d %d %d", &n1, &n2, &n3);
	for(int i=0;i<n1 + n2 + n3;i++)
	{
		scanf("%d", &p);
		a[p]++;
	}
	int c = 0;
	for(int i=0;i<50000;i++)
	{
		if(a[i]>1)
		{
			c++;
		}
	}
	cout << c << "\n";
	for(int i=0;i<5000001;i++)
	{
		if(a[i]>1)
		{
			cout << i << "\n";
		}
	}
}
