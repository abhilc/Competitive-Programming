#include<iostream>
using namespace std;



int main()
{
	string s, res;
	cin >> s;

	int i=0, resi = 0;
	cout << s[i] << s[i+1];
	i+=2;

	while(i < s.length())
	{
		if(s[i] == s[i-1])
		{
			i++;
			continue;
		}
		else
		{
			cout << s[i];
			i++;
		}
	}

}
				


	
