#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
typedef std::deque<int> Q;
typedef std::pair<Q, Q> ii;


using namespace std;

std::map< ii , bool> mymap;

Q q1, q2;
int c = 0;


int dfs(ii node)
{
	c++;

	Q q1 = node.first;
	Q q2 = node.second;

	if(!q1.empty() && !q2.empty())
	{
		int q1top = q1.front();
		q1.pop_front();
		int q2top = q2.front();
		q2.pop_front();
		
		if(q1top > q2top)
		{
			q1.push_back(q2top);
			q1.push_back(q1top);


			if(q2.empty())
			{
				cout << c << " " << 1;
				return 0;
			}

			

			ii node = make_pair(q1, q2);
			
			if(!mymap[node])
			{
				mymap[node] = true;
				dfs(node);
			}
			else 
			{
				cout << -1;
				return 0;
			}
		}

		else if(q2top > q1top)
		{
			q2.push_back(q1top);
			q2.push_back(q2top);
			
			if(q1.empty())
			{
				cout << c << " " << 2;
				return 0;
			}

			ii node = make_pair(q1, q2);
			if(!mymap[node])
			{
				mymap[node] = true;
				dfs(node);
			}
			else
			{
				cout << -1;
				return 0;
			}
		}
	}

	return 0;
	/*if(q1.empty())
	{
		cout << c-1 << " " << 2 << " ";
		return;
	}
	if(q2.empty())
	{
		cout << c-1 << " " << 1;
		return;
	}*/
}
	

int main()
{

	int n, k1, k2, u, v;

	cin >> n;
	cin >> k1;

	for(int i=0;i<k1;i++)
	{
		cin >> u;
		q1.push_back(u);
	}
	cin >> k2;

	for(int i=0;i<k2;i++)
	{
		cin >> v;
		q2.push_back(v);
	}

	ii node = make_pair(q1, q2);
	mymap[node] = true;
	dfs(node);


	
}
