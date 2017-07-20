#include<iostream>
#include<cstring>
using namespace std;

int hashit[26];


int main()
{
	memset(hashit, 0, sizeof(hashit));
	string s;
	cin >> s;

	int missing = 0;

	for(int i=0;i<s.length()-26;i++)
	{
		for(int j=i;j<i+26;j++)
		{
			if(i!=0)
			{
				hashit[i-1]--;
				hashit[i+26]++
			}
			hashit[i]++;
		}
	}
	bool possible = 0;
	for(int i=0;i<s.length()-26;i++)
	{
		for(int j=i;j<i+26;j++)
		{
			if(s[i]=='?')
			{
				missing++;
				if(hashit[i]==0)
					req++;
			}
		}
		if(req <= missing)
		{


}

