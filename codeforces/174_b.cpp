#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;


int main()
{
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;

	int i = count(s.begin(), s.end(), 'I');
	if(i>1)
	{
		cout << 0;
		return 0;
	}
	if(i==1)
	{
		cout << 1;
		return 0;
	}
	int a = count(s.begin(), s.end(), 'A');
	cout << a;
}
	


	
