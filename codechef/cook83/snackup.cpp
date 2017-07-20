#include<iostream>
using namespace std;


int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		int j = 1;
		int p = n;
		cout << 2 << "\n";
		int c = 0;
		while(p--)
		{
			c++;
			if(c==3)
				break;
			cout << n << "\n";
			j = 1;
		
			while(j!=n+1)
			{
				cout << j;
				for(int i=1;i<=n;i++)
				{
					cout << " " << i;
				}
				j++;
				cout << "\n";
			}
			
		}
	}
}

