#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	int z, o;
	cin >> z >> o;
	int ones = o, zeros = z;
	bool found = false;


	if(zeros == (ones-1) || (zeros == ones))
	{
		while(zeros==0 || ones==0)
		{
			cout << 1;
			cout << 0;
			ones--;
			zeros--;
		}
		while(zeros > 0)
		{
			cout << 0;
			zeros--;
		}
		while(ones > 0)
		{
			cout << 1;
			ones--;
		}
		return 0;

	}


	else if( ones > zeros)
	{
		ones = o;
		zeros = z;
	

		ones = ceil(ones/3.0);
		if(zeros == ones || zeros-1 == ones)
		{
			found = true;
		}
		if(found)
		{
			zeros = z;
			ones = o;
			while(zeros > 0 && ones > 0)
			{
				ans.append('1');
				ans.append('1');
				ans.append('0');
				zeros--;
				ones-=2;
			}
			while(ones > 0)
			{
				cout << 1;
				ones--;
			}
			return 0;

		}
	}
	

	else if(ones < zeros)
	{
		ones = o;
		zeros = z;
			zeros= ceil(zeros/2.0);
			if(zeros==ones || ones-2==zeros)
			{
				found = true;
			}
	
		if(found)
		{
			zeros = z;
			ones = o;
			while(zeros==0||ones==0)
			{
				ans.append('0');

				zeros--;
				ones--;
			}
			while(zeros > 0)
			{
				cout << 0;
				zeros--;
			}
			while(ones > 0)
			{
				cout << 1;
				ones--;
			}
			return 0;

		}
	}
	cout << -1;
}

	





