#include<iostream>
#include<algorithm>
using namespace std;



int main()
{
	int tests, N;
	cin >> tests;
	while(tests--)
	{
		cin >> N;
		int a[5001];
		for(int i=0;i<N;i++)
		{
			cin >> a[i];

		}
		sort(a, a+N);
		int min_ans = 1000000001;
		for(int i=0;i<N-1;i++)
		{
			if(min_ans > a[i+1]-a[i])
				min_ans = a[i+1]-a[i];

		}
		cout << min_ans << "\n";

	}


}
