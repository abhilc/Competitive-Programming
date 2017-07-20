#include<iostream>
#include<queue>
using namespace std;


int main()
{
	int a[100001], n, k, p, max;
	cin >> n >> k >> p;
	max = -999;
	int cnt = 0;
	int p;
	deque<int> q;

	for(int i=1;i<=n;i++)
	{
		cin >> p;
		q.push_back(p);
	}
	char ch;


	while(p--)
	{
		cin >> ch;
		if(ch == '?')
		{
			for(int i=0;i<q.size();i++)
			{
				if(i<k)
				{
					cnt+=q[i];
				}
				else
				{
					cnt+=q[i];
					ans = cnt;
					cnt -= q[i-k];
				}
			}
		}
	}
}







