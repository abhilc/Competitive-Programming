#include<cstdio>
#include<algorithm>
using namespace std;

int A[100001];

struct SegmentTreeNode
{
	int sum;
	int start, end;

	void assignLeaf(int val)
	{
		sum = val;
	}

	void merge(SegmentTreeNode& left, SegmentTreeNode& right)
	{
		sum = left.sum + right.sum;
	}

	void applyUpdate(int val)
	{
		sum = sum + val;
	}

	int query()
	{
		return sum;
	}
};


template<class T, class U, class V>
class SegmentTree
{
	SegmentTreeNode* nodes;
	int N;



public:
	SegmentTree(T arr[], int N)
	{
		this->N = N;
		nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
		buildTree(arr, 1, 0, N-1);
	}

	~SegmentTree()
	{
		delete[] nodes;
	}


	V query(int lo, int hi)
	{
		SegmentTreeNode result = query(1,lo,hi);
		return result.query();
	}

	void update(int from, int to, U val)
	{
		update(1, from, to, val);
	}

private:
	void buildTree(T arr[], int p, int L, int R)
	{
		nodes[p].start = L, nodes[p].end = R;
		if(L==R)
		{
			nodes[p].assignLeaf(arr[L]);
			return;
		}

		int left = 2*p, right = left+1, mid = (L+R)/2;

		buildTree(arr, left, L, mid);
		buildTree(arr, right, mid+1, R);
		nodes[p].merge(nodes[left], nodes[right]);
	}


	SegmentTreeNode query(int p, int lo, int hi)
	{
		if(nodes[p].start == lo && nodes[p].end == hi)
			return nodes[p];

		int mid = (nodes[p].start + nodes[p].end)/2,
		    leftChildIndex = p << 1,
		    rightChildIndex = leftChildIndex + 1;
		     
		SegmentTreeNode result;

		if(lo>mid)
			result = query(rightChildIndex, lo, hi);
		if(hi<=mid)
			result = query(leftChildIndex, lo, hi);
		else
		{

		SegmentTreeNode leftResult = query(2*p, lo, hi);
		SegmentTreeNode rightResult = query(2*p+1, lo, hi);
		result.start = leftResult.start;
		result.end = leftResult.end;

		result.merge(leftResult, rightResult);
		}
		
		return result;
	}

	int getSegmentTreeSize(int N)
	{
		int size = 1;
		for(; size < N; size <<=1)
			;
			return size << 1;
	}

	void update(int p, int from, int to, U value)
	{
		if(from==to)
		{
			nodes[p].applyUpdate(value);
			return;
		}

		int left = 2*p, right=left+1, 
		    mid = (nodes[p].start+nodes[p].end)/2;
		if(from > mid)
			update(right, from, to, value);
		else if(to <= mid)
			update(left, from, to, value);
		else{
			update(left, from, mid, value);
			update(right, mid+1, to, value);
		}

		nodes[p].merge(nodes[left], nodes[right]);
	}
};

int main()
{
	int T, typ,C;
	scanf("%d", &T);
	while(T--)
	{
		int N;
		scanf("%d %d", &N, &C);
		for(int i=0;i<N;i++)
			A[i] = 0;
		int val = 0,x,y;
		SegmentTree<int,int,int> st(A, N);
		
		for(int i=0;i<C;i++)
		{
			scanf("%d", &typ);
			if(typ==0)
			{
				scanf("%d %d %d", &x, &y, &val);
				st.update(x, y, val);
			}

			if(typ==1)
			{
				scanf("%d %d", &x, &y);
				printf("%d\n",st.query(x-1, y-1));
			}
		}
	}
}

