#pragma comment (linker, "/STACK:1073741824")
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <complex>

using namespace std;

#define SZ(x) (int((x).size()))
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i, a, b) for(int (i) = (a); (i) >= (b); --(i))
#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define REPD(i, n) for (int (i) = (n); (i)--; )
#define FE(i, a) for (int (i) = 0; (i) < (int((a).size())); ++(i))
#define MEM(a, val) memset((a), val, sizeof(a))
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define PB push_back
#define PPB pop_back
#define ALL(c) (c).begin(), (c).end()
#define SQR(a) ((a)*(a))
#define MP(a,b) make_pair((a), (b))
#define XX first
#define YY second
#define GET_RUNTIME_ERROR *(int*)(NULL) = 1

typedef vector<int> vint;
typedef vector<long long> vLL;
typedef double dbl;
typedef long double ldbl;
typedef vector<pair<int, int> > vpii;
typedef long long LL;
typedef pair<int, int> pii;

const int nmax = 100100;



template<class T, class V>
class SegmentTree
{
	SegmentTree* nodes;
	int N;



public:
	SegmentTree(T arr[], int N)
	{
		this->N = N;
		nodes = new SegmentTreeNode[getSegmentTreeSize(N)];

		buildTree(arr, 1, 0, N-1);
	}

	~SegmentTree(T arr[], int N)
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
	void buildTree(T arr[], int p, int L, int R)
	{
		if(L==R)
		{
			nodes[p].assignLeaf(arr[lo]);
			return;
		}

		int left = (1<<p), right = left+1, mid = (lo+hi)/2;

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
			return getValue(2*index, left, mid, lo, high);

		SegmentTreeNode leftResult = getValue(2*p, left, mid, lo, high);
		SegmentTreeNode rightResult = getValue(2*p+1, mid+1, right, lo, hi);
		SegmentTreeNode result;

		result.merge(leftResult, rightResult);
		return result;
	}

	int getSegmentTreeSize(int N)
	{
		int size = 1;
		for(; size < N; size <<=1);
			return size << 1;
	}

	void update(int p, int lo, int hi, int index, T value)
	{
		if(lo==hi)
		{
			nodes[p].assignLeaf(value);
			return;
		}

		int left = 2*stIndex, right=left+1, mid = (lo+hi)/2;

		if(index <= mid)
			update(left, lo, mid, index, value);
		else
			update(right, mid+1, hi, index, value);

		nodes[p].merge(nodes[left], nodes[right]);
	}
};



