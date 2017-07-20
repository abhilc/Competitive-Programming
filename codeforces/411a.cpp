#include<iostream>
using namespace std;


int main()
{
	int l, r;
	cin >> l >> r;

	if(l%3==0)
	{
		if(r%3==0)
			cout << 3 << "\n";
		else if(r%2==0)
			cout << 2 << "\n";
		else
			cout << 3 << "\n";

	}
	else
		cout << 2 << "\n";

}
