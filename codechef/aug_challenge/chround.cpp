#include<iostream>
#include<stack>
using namespace std;




int main()
{
	int tests, a[1000001], startIdx, oldIdx, newIdx;
	cin >> tests;
	while(tests--)
	{
		int N, jump=0, ans=0, start;
		bool visited[100001];
		cin >> N;
		stack<int> s;
		for(int i=0;i<N;i++)
		{
			cin >> a[i];
			visited[i] = 0;
		}
		for(int i=0;i<N;i++)
		{
			if(!visited[i])
				s.push(i);
			else
				continue;
			start = s.top();
			s.pop();
			visited[start] = 1;
			jump = (start + a[start] + 1)%N;
			if(!visited[jump])
			{
				visited[jump] = 1;
				ans++;

			}
			else
			{
				if(jump==start)
					ans+=1;

			}
			

		}
		cout << ans << "\n";

	}
	

}
