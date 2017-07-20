#include<iostream>
#include<cmath>
#define MOD 1000000007
using namespace std;


int main()
{
	int n;
	scanf("%d", &n);
	long long res = 1, sub = 1;
	for(int i=0;i<n;i++)
	{
		res = (res * pow(3, 3));
		while(res >= MOD)
			res-=MOD;
		sub = (sub%MOD * 7)%MOD;
		while(sub>=MOD)
			sub-=MOD;
	}
	res = res - sub;
	cout << res << "\n";
}



