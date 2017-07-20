#include<iostream>
using namespace std;


int tree[3 * 100001];
int arr[100001];


void build(int node, int start, int end)
{
	if(start == end)
	{
		tree[node] = arr[start];
	}
	else
	{
		int mid = (start + end)/2;
		build(node*2, start, mid);
		build(node*2+1, mid+1, end);

		tree[node] = std::max(tree[2*node], tree[2*node+1]);
	}
}


int query(int node, int start, int end, int l, int r)
{
	if(end < l || start > r)
		return -1;

	if(l<=start && end <= r)
		return tree[node];

	int mid = (start + end)/2;
	int p1 = query(2*node, start, mid, l, r);
	int p2 = query(2*node+1, mid+1, end, l, r);

	return std::max(p1, p2);
}


int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	build(1, 0, n-1);
	int k;
	cin >> k;

	for(int i=0;i<n-k+1;i++)
		cout << query(1, 0, n-1, i, i+k-1) << " ";
}


