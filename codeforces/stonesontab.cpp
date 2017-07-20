#include<iostream>
using namespace std;



int main()
{
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;

	int i = 1, ans = 0;
	char picked = s[0];
	while(i < n)
	{
		ans+=s[i]==picked;
		picked = s[i]!=picked?s[i]:picked;
		i++;
	}
	printf("%d", ans);
}
		
		
