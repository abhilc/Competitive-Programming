#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

ll pwr(ll base, ll p, ll mod = MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}


ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}


const int N = 100005;
int n, e, deg[N];
vector<ii> edgeList;
bool visited[N];
set<int> adj[N];


void check_connectivity(int v){
    visited[v] = true;
    for(auto e : adj[v]){
        int vv = v ^ edgeList[e].ff ^ edgeList[e].ss;
        if(!visited[vv])
            check_connectivity(vv);
    }
}

void euler_dfs(int v){
    while(!adj[v].empty()){

        int e = (*adj[v].begin());
        int vv = v ^ edgeList[e].ff ^ edgeList[e].ss;
        
        if(edgeList[e].ff != v)
            swap(edgeList[e].ff, edgeList[e].ss);
        
        adj[v].erase(adj[v].begin());
        adj[vv].erase(e);

        euler_dfs(vv);
    }
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>e;
    for(int i=0;i<e;i++){
        int a, b;
        cin>>a>>b;
        adj[a].insert(i);
        adj[b].insert(i);
        deg[a]++;   deg[b]++;
        edgeList.pb({a, b});
    }

    check_connectivity(1);
    for(int i=1;i<=n;i++)
        if(!visited[i] || deg[i] % 2 == 1){
            cout<<"NO";
            return 0;
        }

    euler_dfs(1);

    cout<<"YES\n";
    for(int i=0;i<e-1;i++)
        cout<<edgeList[i].ff<<" "<<edgeList[i].ss<<endl;
    cout<<edgeList[e-1].ff<<" "<<edgeList[e-1].ss;
    return 0;
}


