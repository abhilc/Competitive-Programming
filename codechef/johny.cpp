#include<iostream>
#include<algorithm>
using namespace std;



int main()
{
	int tests;
	cin >> tests;
	while(tests--)
	{
		int a[101],N,K,pos, val, ans;
		cin >> N;
		for(int i=1;i<=N;i++){
			cin >> a[i];
		}
		cin >> K;
		val = a[K];
		sort(a+1, a+N+1);
		for(int i=1;i<=N;i++)
		{
			if(a[i]==val)
			{
				ans=i;
				break;
			}
		}
		cout << ans << "\n";
	}
}
