#include<iostream>
#include<set>
using namespace std;


int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		set<string> s;
		string word;
		for(int i=0;i<8;i++)
		{
			cin >> word;
			s.insert(word);
		}
		s.size()<=6?cout<<"similar\n":cout<<"dissimilar\n";
	}
}
