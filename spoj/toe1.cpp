#include<iostream>
#include<cstring>
using namespace std;



int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		char m;
		string ip;
		int x = 0, o = 0;
		for(int i=0;i<9;i++)
		{
			cin >> m;
			if(m=='X')
				x++;
			if(m=='O')
				o++;
		}
		if(x>o && x-1==o)
			printf("yes\n");
		else if(x==o)
			printf("yes\n");
		else
			printf("no\n");


	}
}
			
			
