#include<iostream>
using namespace std;



int main()
{
	int w, h;
	cin >> w >> h;

	long long ans = 0;
	for(int i=0;i<w-1;i++)
	{
		ans += h/2;
	}

	cout << ans << "\n";
}
