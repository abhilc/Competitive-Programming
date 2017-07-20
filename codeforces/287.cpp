#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	int r, x1, y1, x2, y2;
	cin >> r >> x1 >> y1 >> x2 >> y2;

	double d = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
	cout << ceil(d/(2*r)) << "\n";
	
}
