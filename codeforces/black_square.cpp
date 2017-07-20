#include<iostream>
using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;

	char mat[101][101];

	int l = 1001, r = -1001, u = 1001, d = -1001;
	int bcount = 0;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> mat[i][j];

			if(mat[i][j]=='B')
			{
				l = min(l, j);
				r = max(r, j);
				u = min(u, i);
				d = max(d, i);
				bcount++;
			}
		}
	}

	int max_length = std::max(r - l + 1, d - u + 1);
	
	int ans = max_length * max_length;

	if(bcount == 0)
	{
		cout << 1 << "\n";
		return 0;
	}

	if(max_length <= n && max_length <= m)
		cout << ans - bcount << "\n";
	else
		cout << -1 << "\n";



}
	
