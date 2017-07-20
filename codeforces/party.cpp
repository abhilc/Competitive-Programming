#include<iostream>
#include<vector>
using namespace std;



int main()
{
	int n,  ans =0, num = 1;
	cin >> n;
	int tree[2011];

	for(int i=1;i<=n;i++)
		cin >> tree[i];
	int j;

	for(int i=1;i<=n;i++)
	{
		j = i;
		num = 1;
		while(tree[j]!=-1)
		{
			j = tree[j];
			num++;
		}
		ans = std::max(ans, num);
	}
	cout << ans;
}
	
