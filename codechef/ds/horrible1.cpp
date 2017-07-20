#include <cstdio>
#include <cmath>
#include<cstring>
#include<iostream>
using namespace std;

struct SegmentTreeNode {    
    int start, end; // this node is responsible for the segment [start...end]    
    int total;
    
    void assignLeaf(double value) {
        total = value;
    }
    
    void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
        total = left.total + right.total;
    }
    
    double query() {
        return total;
    }
    
    // the value of the update is dummy in this case
    void applyUpdate(int value) {
        total += value;
    }
};

template<class InputType, class UpdateType, class OutputType>
class SegmentTree {
    SegmentTreeNode* nodes;
    int N;
    
public:
    SegmentTree(InputType arr[], int N) {
        this->N = N;
        nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
        buildTree(arr, 1, 0, N-1);
    }
    
    ~SegmentTree() {
        delete[] nodes;
    }
    
    // get the value associated with the segment [start...end]
    OutputType query(int start, int end) {
	cout << "In query!!\n";
        SegmentTreeNode result = query(1, start, end);
        return result.query();
    }

    
    // range update: update the range [start...end] by value
    // Exactly what is meant by an update is determined by the
    // problem statement and that logic is captured in segment tree node
    void update(int start, int end, UpdateType value) {
        update(1, start, end, value);
    }
    
private:
    void buildTree(InputType arr[], int stIndex, int start, int end) {
        // nodes[stIndex] is responsible for the segment [start...end]
        nodes[stIndex].start = start, nodes[stIndex].end = end;
        
        if (start == end) {
            // a leaf node is responsible for a segment containing only 1 element
            nodes[stIndex].assignLeaf(arr[start]);
            return;
        }
        
        int mid = (start + end) / 2,
            leftChildIndex = 2 * stIndex,
            rightChildIndex = leftChildIndex + 1;
            
        buildTree(arr, leftChildIndex, start, mid);
        buildTree(arr, rightChildIndex, mid + 1, end);
        nodes[stIndex].merge(nodes[leftChildIndex], nodes[rightChildIndex]);
    }
    
    int getSegmentTreeSize(int N) {
        int size = 1;
        for (; size < N; size <<= 1);
        return size << 1;
    }
    
    SegmentTreeNode query(int stIndex, int start, int end) {
        if (nodes[stIndex].start == start && nodes[stIndex].end == end)
	{
            return nodes[stIndex];
	}
        
        int mid = (nodes[stIndex].start + nodes[stIndex].end) >> 1,
            leftChildIndex = stIndex << 1,
            rightChildIndex = leftChildIndex + 1;            
            SegmentTreeNode result;
        
        if (start > mid)
            result = query(rightChildIndex, start, end);
        else if (end <= mid)
            result = query(leftChildIndex, start, end);
        else {
            SegmentTreeNode leftResult = query(leftChildIndex, start, mid),
                            rightResult = query(rightChildIndex, mid+1, end);
            result.start = leftResult.start;
            result.end = rightResult.end;
            result.merge(leftResult, rightResult);
        }
        
        return result;
    }
    
    void update(int stIndex, int start, int end, UpdateType value) {
        if (start == end) {
            // we are only applying updates on leaf nodes
            nodes[stIndex].applyUpdate(value);
            return;
        }
        
        int mid = (nodes[stIndex].start + nodes[stIndex].end) / 2,
            leftChildIndex = 2 * stIndex,
            rightChildIndex = leftChildIndex + 1;
            
        if (start > mid)
            update(rightChildIndex, start, end, value);
        else if (end <= mid)
            update(leftChildIndex, start, end, value);
        else {
            update(leftChildIndex, start, mid, value);
            update(rightChildIndex, mid+1, end, value);
        }
        nodes[stIndex].merge(nodes[leftChildIndex], nodes[rightChildIndex]);
    }
};

int A[100];


int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int typ, x, y, val, N, C;
		cin >> N >> C;
		memset(A, 0, sizeof(A));
		SegmentTree<int,int,int> st(A,N);
		for(int i=0;i<C;i++)
		{
		scanf("%d", &typ);
		if(typ==0)
		{
			scanf("%d %d %d", &x, &y, &val);
			st.update(x-1,y-1,val);
		}
		else
		{
			scanf("%d %d", &x, &y);
			printf("%d\n", st.query(x-1,y-1));
		}
		}
	}
}
