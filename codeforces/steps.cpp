#include<iostream>
using namespace std;


int main()
{
	long long n, m;
	cin >> n >> m;

	long long startx, starty, dx, dy, p, q;
	cin >> startx >> starty;

	long long v;
	
	cin >> v;
	long long ans = 0;
	long long steps;
	long long conx, cony;

	for(long long i=0;i<v;i++)
	{
		cin >> dx >> dy;
		
		conx = dx > 0 ? n:1;
		cony = dy > 0 ? m:1;
		
		if(dx == 0 && dy == 0)
			continue;

		if(dx == 0)
			steps = (cony - starty)/abs(dy);
		else if(dy == 0)
			steps = (conx - startx)/abs(dx);
		else
		{
			steps = std::min((conx-startx)/dx, (cony-starty)/dy);
		}
		ans += abs(steps);

		if(dx == 0)
			starty += abs(steps)*dy;
		else if(dy == 0)
			startx += abs(steps)*dx;

		else
		{
		

			startx += abs(steps)*dx;
			starty += abs(steps)*dy;
		}

	}

	cout << ans;
}

		


