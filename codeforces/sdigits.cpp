#include<iostream>
#include<algorithm>
using namespace std;



int main()
{
	string s;
	cin >> s;
	int ones = count(s.begin(), s.end(), '1'), twos = count(s.begin(), s.end(), '2');
	int threes = count(s.begin(), s.end(), '3');
	int fours = count(s.begin(), s.end(), '4');
	int fives = count(s.begin(), s.end(), '5');
	int six = count(s.begin(), s.end(), '6');
	int seven = count(s.begin(), s.end(), '7');
	int eight = count(s.begin(), s.end(), '8');
	int nine = count(s.begin(), s.end(), '9');
	int zeroes = count(s.begin(), s.end(), '0');

	int c = 0;

	if(ones > 0)
	{
		if(ones > 9)
			c+=2;
		else
			c+=1;
	}
	if(twos > 0)
	{
		if(twos > 4)
			c+=2;
		else
			c+=1;
	}
	if(threes > 0)
	{
		if(threes > 3)
			c+=2;
		else
			c+=1;
	}
	if(fours > 0)
	{
		if(fours > 2)
			c+=2;
		else
			c+=1;
	}
	if(fives > 0)
	{
		if(fives > 1)
			c+=2;
		else
			c+=1;
	}
	if(six > 0)
	{
		if(six > 1)
			c+=2;
		else
			c+=1;
	}
	if(seven > 0)
	{
		if(seven > 1)
			c+=2;
		else
			c+=1;
	}
	if(eight > 0)
	{
		if(eight > 1)
			c+=2;
		else
			c+=1;
	}
	if(nine > 0)
	{
		if(nine > 1)
			c+=2;
		else
			c+=1;
	}

	cout << c << "\n";
}
	

	
