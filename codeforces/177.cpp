#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	int n, m, d;
	cin >> n >> m >> d;
	int mat[n+1][m+1], b[n*m+5];
	int k = 0;


	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> mat[i][j];
			b[k++] = mat[i][j];
		}
	}
	
	sort(b, b+k);
	int med = b[k/2];
	long long ans = 0;
	int prev = b[0]%d;
	for(int i=1;i<k;i++)
	{
		if(b[i]%d!=prev)
		{
			puts("-1\n");
			return 0;
		}
	}

	for(int i=0;i<k;i++)
	{
		ans += abs((b[i]-med)/d);
	}
	cout << ans << "\n";


}

	
