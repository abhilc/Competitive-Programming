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

