#include<iostream>
using namespace std;



int main()
{
	string s;
	float rot, sht;
	
	cin >> s;
	int n = s.length();
	int w = 0, b = 0;

	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
			w++;
	}
	rot = (float)w/n;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='0' && s[i+1]=='0')
			b++;
	}
	if(s[0]=='0' &&s[n-1]=='0')
		b++;
	sht = (float)b/w;
	if(rot == sht)
		printf("EQUAL\n");
	else if(rot > sht)
		printf("ROTATE\n");
	else
		printf("SHOOT\n");
}


	
