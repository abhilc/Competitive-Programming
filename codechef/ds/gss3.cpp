#include<cstdio>
#include<algorithm>
using namespace std;

struct SegmentTreeNode
{
	int prefixMaxSum, SuffixMaxSum, maxSum, sum;

	void assignLeaf(int value){
		prefixMaxSum = SuffixMaxSum = maxSum = sum = value;
	}

	void merge(SegmentTreeNode& left, SegmentTreeNode& right)
	{
		sum = left.sum + right.sum;
		prefixMaxSum = max(left.prefixMaxSum, left.sum + right.prefixMaxSum);
		SuffixMaxSum = max(right.SuffixMaxSum, right.sum + left.SuffixMaxSum);
		maxSum = max(prefixMaxSum, max(SuffixMaxSum, max(left.maxSum, max(right.maxSum, left.SuffixMaxSum + right.prefixMaxSum))));
	}

	int getValue()
	{
		return maxSum;
	}
};

template<class T, class V>
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


	V getValue(int lo, int hi)
	{
		SegmentTreeNode result = getValue(1,0,N-1,lo,hi);
		return result.getValue();
	}

	void update(int index, T value)
	{
		update(1, 0, N-1, index, value);
	}

private:
	void buildTree(T arr[], int p, int lo, int hi)
	{
		if(lo==hi)
		{
			nodes[p].assignLeaf(arr[lo]);
			return;
		}

		int left = 2*p, right = left+1, mid = (lo+hi)/2;

		buildTree(arr, left, lo, mid);
		buildTree(arr, right, mid+1, hi);
		nodes[p].merge(nodes[left], nodes[right]);
	}


	SegmentTreeNode getValue(int p, int left, int right, int lo, int hi)
	{
		if(left == lo && right == hi)
			return nodes[p];

		int mid = (left + right)/2;

		if(lo>mid)
			return getValue(2*p+1, mid+1, right, lo, hi);
		if(hi<=mid)
			return getValue(2*p, left, mid, lo, hi);

		SegmentTreeNode leftResult = getValue(2*p, left, mid, lo, mid);
		SegmentTreeNode rightResult = getValue(2*p+1, mid+1, right, mid+1, hi);
		SegmentTreeNode result;

		result.merge(leftResult, rightResult);
		return result;
	}

	int getSegmentTreeSize(int N)
	{
		int size = 1;
		for(; size < N; size <<=1)
			;
			return size << 1;
	}

	void update(int p, int lo, int hi, int index, T value)
	{
		if(lo==hi)
		{
			nodes[p].assignLeaf(value);
			return;
		}

		int left = 2*p, right=left+1, mid = (lo+hi)/2;

		if(index <= mid)
			update(left, lo, mid, index, value);
		else
			update(right, mid+1, hi, index, value);

		nodes[p].merge(nodes[left], nodes[right]);
	}
};

int main()
{
	int N, i, A[50000], M, x, y;

	scanf("%d", &N);
	for(i=0;i<N;++i)
		scanf("%d", &A[i]);

	SegmentTree<int, int> st(A, N);

	scanf("%d", &M);
	int typ;
	for(i=0;i<M;i++)
	{
		scanf("%d %d %d", &typ, &x, &y);
		if(typ==1)
			printf("%d\n", st.getValue(x-1, y-1));
		if(typ==0)
			st.update(x-1, y);
	}

	return 0;
}




