#include<iostream>
using namespace std;



int main()
{
	long long m, l, r;
	string s;
	cin >> s;
	long long k=0, a[100005];

	for(int i=s.length()-2;i>=0;i--)
	{
		a[i] = a[i+1]+(s[i]==s[i+1]);
	}

	
	int q;

	cin >> q;
	while(q--)
	{
		cin >> l >> r;
		cout << a[l-1]-a[r-1]<< "\n";
	}

}

