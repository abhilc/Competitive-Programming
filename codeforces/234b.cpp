#include<iostream>
#include<set>
using namespace std;



int main()
{
	char mat[1001][1001];
	int n, m;
	set<int> S;

	cin >> n >> m;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> mat[i][j];
		}
	}
	int min = 999999999;
	int posg, posc;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mat[i][j]=='G')
			{
				posg = j;
			}
			if(mat[i][j] == 'S')
			{
				posc = j;
			}
		}
		if(posg == posc)
			continue;
		else if(posg > posc)
		{
			cout << -1;
			return 0;
		}
		else 
		{
			S.insert(posc - posg);
		}
	}

	cout << S.size();





}
