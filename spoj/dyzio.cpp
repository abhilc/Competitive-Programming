#include<iostream>
using namespace std;

string str;
int N, cut_no, pos, maxD, ans;

void solve(int depth)
{
	if(str[pos]=='1')cut_no++;

	if(depth > maxD)
	{
		ans = cut_no;
		maxD = depth;
	}
	if(str[pos++]=='1')
	{
		solve(depth+1);
		solve(depth+1);
	}
}



int main()
{
	int t = 10;
	while(t--)
	{
	cin >> N;
	cin >> str;
	maxD = 0;
	pos = 0;
	cut_no = 0;
	ans = 0;
	solve(1);

	cout << ans << "\n";
	}

}



