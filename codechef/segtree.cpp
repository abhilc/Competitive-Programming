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
#define MAX(a, b, c) (a>b?(a>c?a:c):(b>c?b:c))
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

const LL nmax  = 15010000;

LL A[nmax];

LL left(int p){return 1<<p;}
LL right(int p){return (1<<p)+1;}

struct 
{
	int totsum;
	int maxPrefixSum;
	int maxSuffixSum;
	int maxSubarraySum:
} s[nmax];

void build(LL p, LL L, LL R)
{
	if(L==R)
	{
		s[p].totsum = A[L];
		s[p].maxPrefixSum = A[L];
		s[p].maxSuffixSum = A[L];
		s[p].maxSubArraySum = A[L];
	}
	else
	{
		build(left(p), L, (L+R)/2);
		build(right(p), ((L+R)/2)+1, R);
		LL p1sum = s[left(p)], p2sum = s[right(p)];
		LL val = p2sum + p1sum;
		s[p].totsum = val;
		s[p].maxPrefixSum = std::max(s[left(p)].maxPrefixSum, s[left(p)].totsum + s[right(p)].maxPrefixSum)
	}
}



LL rmq(LL p, LL L, LL R, LL i, LL j)
{
	
	if(L>=i && R<=j)
		return s[p];

	if(i>R || j<L)
	{	
		return -(LLINF);
	}

	LL p1 = rmq(left(p), L, (L+R)/2, i, j);
	LL p2 = rmq(right(p), ((L+R)/2)+1, R,  i, j);
	if(p1==-(LLINF))return p2;
	if(p2==-(LLINF))return p1;
	return std::max(p1, p2);
}



int main()
{
	LL N;
	cin >> N;
	LL x1, y1, Q;
	for(int i=0;i<N;i++)
		cin >> A[i];

	build(1, 0, N-1);
	cin >> Q;

	for(int i=0;i<Q;i++)
		cin >> x1 >> y1;

	cout << rmq(1, 0, N-1, x1-1, y1-1) << "\n";

}




