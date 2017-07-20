#include<iostream>
using namespace std;


int main()
{
	int n, s, t;
	cin >> n >> s >> t;
	int p[100001];

	for(int i=0;i<n;i++)
		cin >> p[i];

	int c = 0;
	bool success = 0;

	if(p[s-1]==t)
	{
		cout << 0;
		return 0;
	}

	for(int i=s-1;;i++)
	{

		if(p[i]==t)
		{
			success = 1;
			break;
		}
		else if(p[i]==s)
		{
			break;
		}
		c++;
	}
	if(success)
		cout << c + 1;
	else
		cout << -1;

}
		
