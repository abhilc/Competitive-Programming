#include<iostream>
using namespace std;


int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;

	int i=0, j=0;
	while(i < s1.length() && j < s2.length())
	{
		if(s1[i]==s2[j])
		{
			i++;
			j++;
		}
		else
			j++;
	}
	printf("%d", i+1);
}
