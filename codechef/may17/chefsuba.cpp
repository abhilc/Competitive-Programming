#include<iostream>
using namespace std;

int tree[4 * 10000001 + 10];
int dp[ 2* 10000001 + 10];
int arr[ 2 * 10000001 + 10];

void build(int node, int start, int end)
{
	if(start==end)
	{
		tree[node] = dp[start];
	}
	else
	{
		int mid = (start + end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = std::max(tree[2*node], tree[2*node+1]);
	}
}

int query(int node, int start, int end, int l, int r)
{
	if(end < l || r < start)
		return -1;
	if(l<=start && end<=r)
		return tree[node];
	
	
		int mid = (start + end)/2;
		int p1 = query(2*node, start, mid, l, r);
		int p2 = query(2*node+1,  mid+1, end, l, r);
		return std::max(p1, p2);
	
}


int main()
{
	int n, k, q;
	cin >> n >> k >> q;

	for(int i=1;i<=n;i++)
	{
		cin >> arr[i + n];
		arr[i] = arr[i + n];
	}



	dp[0] = 0;

	for(int i=1;i<=k;i++)
	{
		dp[i] = dp[i-1] + arr[i];
	}

	for(int i=k+1;i<=2*n;i++)
	{
		dp[i] = dp[i-1] + arr[i] - arr[i-k];
	}

	/*for(int i=1;i<=10;i++)
		cout << dp[i] << " ";
	cout << "\n";*/


	

	string s;
	cin >> s;

	build(1, 1, 2*n);



	int pos = n + 1;
	int l, r;

	for(int i=0;i<s.length();i++)
	{
		if(s[i] == '?')
		{
			l = pos + k - 1;
			r = l + n - k;

			cout << query(1, 1, 2*n, l, r) << "\n";
		}
		else if(s[i] == '!')
		{
			pos--;
			if(pos == 0)
				pos = n + 1;
		}
	}
}

	





