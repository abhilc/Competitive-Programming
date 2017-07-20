#include<iostream>
using namespace std;


int main()
{
	int tests;
	cin >> tests;
	while(tests--)
	{
		int N, X, a[101], sum=0;
		bool flag = 0;
		cin >> N >> X;
		for(int i=0;i<N;i++)
		{
			cin >> a[i];
			sum+=a[i];
		}
		int rem = sum % X;
		if(rem > 0){
			for(int i=0;i<N;i++)
			{
				if(a[i]<=rem){
					flag = 1;
					break;
				}
				
			}
		}
		flag==1?cout<<"-1\n":cout<<sum/X<<"\n";
	}
}
