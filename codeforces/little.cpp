#include<iostream>
#include<map>
using namespace std;

map<char, int> mp;

int main()
{
	int k = 0;
	string s;
	cin >> s;

	for(int i=0;i<s.length();i++)
		mp[s[i]]++;

	for(auto it = mp.begin();it!=mp.end();it++)
	{
		if((it->second)%2==1)
			k++;
	}

	if(k==0 || k==1)
	{
		cout << "First\n";
		return 0;
	}

	k%2==1?cout<<"First\n":cout<<"Second\n";
}


	
