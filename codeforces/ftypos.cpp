#include<iostream>
using namespace std;



int main()
{
	string s;
	cin >> s;
	int i = 0;
	string res="";
	if(s.length() < 2)
	{
		cout << s;
		return 0;
	}
	res+=s[0];
	res+=s[1];
	long long ch = 2;
	


	while(ch < s.length())
	{
		if((res[res.length()-1] == s[ch]) && res[res.length()-1]==res[res.length()-2])
			ch++;
		else if(res[res.length()-1] == s[ch] && res[res.length()-2]==res[res.length()-3])
			ch++;
		else
		{
			res+=s[ch];
			ch++;
		}
	}
	cout << res;

}
		

	

	
