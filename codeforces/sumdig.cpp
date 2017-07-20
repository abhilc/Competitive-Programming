#include<iostream>
#include<algorithm>
using namespace std;



int main()
{
	string s;
	cin >> s;

	int zcount = std::count(s.begin(), s.end(), '0');

	cout << s.length() - zcount;

}
