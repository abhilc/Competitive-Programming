#include<iostream>
#include<algorithm>
using namespace std;



int main()
{
	int xs, ys;
	string s;

	cin >> s;


	xs = count(s.begin(), s.end(), 'x');
	ys = count(s.begin(), s.end(), 'y');


	if(xs > ys)
	{
		for(int i=0;i<(xs-ys);i++)
			cout << 'x';
	}
	else
	{
		for(int i=0;i<(ys-xs);i++)
			cout << 'y';
	}


}
