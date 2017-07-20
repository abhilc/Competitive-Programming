#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 10000000010
#define pb push_back
typedef long long ll;
typedef std::pair<ll, ll> ii;
using namespace std;
 
 
vector<ii > gp[200005];
ll dist[200005];

void dijsktra(int s)
{
	priority_queue<ii, vector<ii>, greater<ii> >pq;
	dist[s] = 0;
	pq.push({0, s});

	while(!pq.empty())
	{
		ii front = pq.top();
		pq.pop();

		ll d = front.first, u = front.second;

		for(int j=0;j<(ll)gp[u].size();j++)
		{
			ii v = gp[u][j];

			if(dist[u] + v.second < dist[v.first])
			{
				dist[v.first] = dist[u] + v.second;
				pq.push({dist[v.first], v.first});
			}
		}
	}
}
 
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		ll N, K, X, M, S;
		cin >> N >> K >> X >> M >> S;
		ll a, b, c, i, j;
 
		for(int i=1;i<=N;i++)
		{
			gp[i].clear();
			dist[i] = INF;
		}
 
		for(i=0;i<M;i++)
		{
			cin >> a >> b >> c;
			gp[a].pb({b, c});
			gp[b].pb({a, c});
		}
 
		for(int i=1;i<K;i++)
		{
			for(int j=i+1;j<=K;j++)
			{
				gp[i].pb({j, X});
				gp[j].pb({i, X});
			}
		}

		dijsktra(S);
 
				
		for(int i=1;i<=N;i++)
		{
			cout << dist[i] << " ";
		}
		cout << "\n";
	}
}

