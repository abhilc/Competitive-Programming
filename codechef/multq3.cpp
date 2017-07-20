#include<iostream>
#define N 100005
using namespace std;

int tree[ 3 * N + 1 ];
int a[N];
int p[ 3 * N + 1];

void updateRange(int node, int start, int end, int l, int r)
{
	if(end < l || start > r)
		return;

	if(l<=start && end<=r)
	{
		p = (end - start) + 1;

		
	}
	else
	{
		int mid = (start + end)/2;
		updateRange(2 * node, start, mid, l, r);
		updateRange(2 * node + 1, mid+1, end, l, r);

		tree[node] = tree[2 * node] + tree[2 * node + 1];
		p[node] = p[2 * node] + p[2 * node + 1];
	}
}

void build(int node, int start, int end)
{
	if(start == end)
	{
		
		tree[node] += 1;
		return;
	}

	int mid = (start + end)/2;

	build(2*node, start, mid);
	build(2*node+1, mid+1, end);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}


int query(int node, int start, int end, int l, int r)
{
	if(end < l || start > r || start > end)
	{
		return 0;
	}

	if(l<=start && end <= r)
	{
		return tree[node];
	}

	int mid = (start + end)/2;
	int p1 = query(2*node, start, mid, l, r);
	int p2 = query(2*node+1, mid+1, end, l, r);

	return (p1 + p2);
}


int main()
{
	int n, c, typ, l, r;
	cin >> n >> c;

	build(1, 0, n-1);


	while(c--)
	{
		cin >> typ >> l >> r;

		if(typ==1)
		{
			cout << query(1, 0, n-1, l, r) << "\n";
		}
		else
		{
			updateRange(1, 0, n-1, l, r);
			

		}
	}
}
		


		


