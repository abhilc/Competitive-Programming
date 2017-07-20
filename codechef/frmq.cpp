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

const int nmax = 10100001;

vLL s(nmax), A(nmax);
long long N,M;

int left(int p){return p<<1;}
int right(int p){return (p<<1)+1;}

struct 
{
	int sum = 0;
	int max = 0;
} s[nmax];

void build(LL p, LL L, LL R)
{
	if(L==R)
	{
		s[p].sum = A[L];
		s[p].max = A[L];
	}
	else
	{
		build(left(p), L, (L+R)/2);
		build(right(p), ((L+R)/2)+1, R);

		int p1sum = s[left(p)].sum, p1max = s[left(p)].max, p2sum = s[right(p)].sum, p2max = s[right(p)].max;
		
		s[p].sum = p1sum + p2sum;
		s[p].max = std::max(p1sum, p1max) + std::max(p2sum, p2max);
		
		//int p1 = s[left(p)], p2 = s[right(p)];
		//s[p] = A[p1]>A[p2]?p1:p2;
	}
}

int rmq(LL p, LL L, LL R, LL i, LL j)
{
	if(L>=i && R<=j) return std::max(s[p].sum, s[p].max);
	if(i>R || j<L) return -1;
        int p1 = rmq(left(p), L, (L+R)/2, i, j);
	int p2 = rmq(right(p), (L+R)/2+1, R, i, j);
  	if(p1==-1)return p2;
	if(p2==-1)return p1;
	return (s[p1]>s[p2])?s[p1]:s[p2];
}	

int main()
{
	cin >> N;
	s.assign(nmax,0);
	A.assign(nmax,0);
	long long x1,y1,sum=0;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
	}
	cin >> M >> x1 >> y1;
	//x1 = min(x1, y1);
	//y1 = max(x1, y1);
	build(1, 0, N-1);
	sum = 0;
	LL l,r;
	for(LL i=1;i<=M;i++)
	{
		l = min(x1,y1);
		r = max(x1,y1);
		sum+=A[rmq(1,0,N-1,l,r)];
		x1+=7;
		y1+=11;
		while(x1>=N-1)
			x1-=(N-1);
		while(y1>=N)
			y1-=N;
	}
	cout << sum << "\n";

}


