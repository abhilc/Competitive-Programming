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

vector<pair<int, int>> g[nmax];
LL total;
vector<bool> special;
int k[nmax];
int m;

// Calculating number of special nodes in the subtree and number of times this
// edge should be added to answer (multiplying by its length, of course).
void dfs(int v, int p) {
  k[v] = special[v] ? 1 : 0;
  for (const auto& to : g[v]) {
    if (to.first == p) {
      continue;
    }
    dfs(to.first, v);
    k[v] += k[to.first];
    total += 2*to.second*LL(k[to.first])*(m - k[to.first]);
  }
}

// GCD.
LL gcd(LL a, LL b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

// Solves the test.
void solve() {
  int n;
  cin >> n >> m;
  total = 0;
  REP(i, n) {
    g[i].clear();
  }
  REP(i, n - 1) {
    int v, u, l;
    cin >> v >> u >> l;
    --v, --u;
    g[v].PB(MP(u, l));
    g[u].PB(MP(v, l));
  }

  special.assign(n, false);
  REP(i, m) {
    int v;
    cin >> v;
    special[v - 1] = true;
  }

  total = 0;
  dfs(0, -1);
  LL num = total;
  LL denom = m*LL(m);
  LL g = gcd(num, denom);
  num /= g;
  denom /= g;
  cout << num << " " << denom << endl;
}

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}
