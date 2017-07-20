#include<iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;

	string ans;
	int x, y, sum = 0;

	for(int i=0;i<n;i++)
	{
		cin >> x >> y;

		if(abs(sum-y)<=500)
			ans += 'G', sum-=y;
		else
			ans += 'A', sum += x;
	}
	cout << ans << "\n";
}

