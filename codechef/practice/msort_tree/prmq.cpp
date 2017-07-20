#include<iostream>
#include<algorithm>
#include<cstring>
typedef long long LL;
#include<vector>
#define lima 100005
#define limb 1000006
using namespace std;

int spf[limb];
bool isPrime[limb];
vector<int> tree[4 * lima];
vector<int> allfactors[limb];

/*void sieve()
{
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for(int i=2;i<limb;i++)
	{
		if(isPrime[i])
		{
			spf[i] = i;
			for(int j=i*2;j<limb;j+=i)
			{
				spf[j] = i;
				isPrime[j] = false;
			}
		}
	}
}*/

void sieve()
{
	for(int i=2;i<limb;i++)
	{
		isPrime[i]=1;
	}
	for(int i=2;i<limb;i++)
	{
		if(isPrime[i])
		{
			spf[i]=i;
			for(int j=i*2;j<limb;j+=i)
			{
				isPrime[j]=0;
				spf[j]=i;
			}
		}
	}
}

void build(int node, int start, int end)
{
	if(start == end)
	{
		for(int i=0;i<allfactors[start].size();i++)
			tree[node].push_back(allfactors[start][i]);
	}
	else
	{
		int mid = (start + end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		
		//Merging 
		
		int s1 = tree[2*node].size();
		int s2 = tree[2*node+1].size();

		/*vector<int> lchild = tree[2*node];
		vector<int> rchild = tree[2*node+1];*/

		int i = 0, j = 0;
		
		while(i<s1 && j<s2)
		{
			if(tree[2*node][i] < tree[2*node+1][j])
			{
				tree[node].push_back(tree[2*node][i]);
				i++;
			}
			else
			{
				tree[node].push_back(tree[2*node+1][j]);
				j++;
			}
		}
		while(i < s1)
		{
			tree[node].push_back(tree[2*node][i]);
			i++;
		}

		while(j < s2)
		{
			tree[node].push_back(tree[2*node+1][j]);
			j++;
		}
	}
}

/*void build(int start,int end,int node)
{
	if(start==end)//push all the primes of child
	{
		int s=allfactors[start].size();
		for(int i=0;i<s;i++)
		{
			tree[node].push_back(allfactors[start][i]);
		}
	}
	else
	{
		int mid= (start+end)/2;
		build(start,mid,node*2);
		build(mid+1,end,node+node+1);
		int i=0,j=0;
		int s1=tree[node*2].size();
		int s2=tree[node+node+1].size();
		//merge logic
		while(i<s1 && j<s2)
		{
			if(tree[node*2][i]<tree[node+node+1][j])
			{
				tree[node].push_back(tree[node*2][i]);
				i++;
			}
			else
			{
				tree[node].push_back(tree[node+node+1][j]);
				j++;
			}
		}
		//Bacha kucha maal 
		while(i<s1)
		{
			tree[node].push_back(tree[node*2][i]);
			i++;
		}
		while(j<s2)
		{
			tree[node].push_back(tree[node+node+1][j]);
			j++;
		}
	}
}*/

LL query(int node, int start, int end, int L, int R, int X, int Y)
{
	if(start > end || end < L || start > R)
		return 0;

	if(L<=start && end <= R)
	{
		return (upper_bound(tree[node].begin(), tree[node].end(), Y) - lower_bound(tree[node].begin(), tree[node].end(), X));
	}

	int mid = (start + end)/2;
	int a = query(2*node, start, mid, L, R, X, Y);
	int b = query(2*node+1, mid+1, end, L, R, X, Y);
	return (a+b);
}




int main()
{
	int N, L, R, X, Y, Q;
	sieve();
	scanf("%d", &N);
	int a[N + 1];

	for(int i=1;i<=N;i++)
	{
		scanf("%d", &a[i]);
	}

	for(int i=1;i<=N;i++)
	{
		int num = a[i];
		while(num > 1)
		{
			int j = spf[num];
			while(num%j == 0)
			{
				allfactors[i].push_back(j);
				num/=j;
			}
		}
	}
	for(int i=1;i<=N;i++)
		sort(allfactors[i].begin(), allfactors[i].end());

	build(1, 1, N);

	scanf("%d", &Q);
	while(Q--)
	{
		scanf("%d%d%d%d", &L, &R, &X, &Y);
		printf("%lld\n", query(1, 1, N, L, R,  X, Y));
		//printf("%lld\n", query(1,N,L,R,1,X,Y));
	}
}

