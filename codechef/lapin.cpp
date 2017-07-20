#include<iostream>
using namespace std;



int main()
{
	string s;
	bool flag;
	int tests;
	cin >> tests;
	while(tests--)
	{
	flag=0;
	int a[123] = {0};
	cin >> s;
	for(int i=0;i<s.length();i++)
	{
		a[s[i]-'0']++;
	}
	
	if(s.length()%2==1)
		a[s[s.length()/2]-'0'] = 0;
	for(int i=0;i<s.length();i++)
	{
		if(a[s[i]-'0']%2==1){
			flag=1;
			break;
		}
		else{
			flag=0;
		}
			
	}
	flag==1?cout<<"NO\n":cout<<"YES\n";
	}
}
	
