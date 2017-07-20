#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	int rmp[1234 + 1];
	int cmp[5678 + 1];

	int x, y;
	char c;

	for(int i=0;i<1234;i++)
		rmp[i] = i;
	for(int j=0;j<5678;j++)
		cmp[j] = j;

	while(cin >> c)
	{

	if(c == 'R')
	{
		cin >> x >> y;
		swap(rmp[x-1], rmp[y-1]);
	}
	if(c == 'C')
	{
		cin >> x >> y;
		swap(cmp[x-1], cmp[y-1]);
	}
	if(c == 'Q')
	{
		cin >> x >> y;
		cout << (rmp[x-1])*5678 + cmp[y-1]+1 << "\n";
		
	}
	int elem;
	if(c == 'W')
	{

		cin >> elem;
		x = (elem-1)/5678;
		y = (elem-1)%5678;
		for(int i=0;i<1234;i++)
			if(rmp[i]==x)
				printf("%d ", i+1);
		for(int i=0;i<5678;i++)
			if(cmp[i]==y)
				printf("%d\n", i+1);
	}
	}
}





		
