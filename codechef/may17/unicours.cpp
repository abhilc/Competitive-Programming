#include<iostream>
using namespace std;



int main()
{
	int tests;
	cin >> tests;
	while(tests--)
	{
	int n, a[100001];
	cin >> n;
	int max = -999;

	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(max < a[i])
			max = a[i];
	}
	cout << n - max << "\n";
	}
}


