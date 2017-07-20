#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#define maxn 100000
#define MP make_pair
using namespace std;


typedef long long LL;
typedef pair<int, int> pi;
LL males[maxn + 5], females[maxn + 5], line[maxn + 5];
pi all[maxn + 5];

int tree[maxn + 2];

int read(int idx)
{
	int sum = 0;
	while(idx > 0) sum = (sum + tree[idx]),idx -= (idx & -idx);
	return sum;
}

void update(int idx, int val)

{
	while(idx <= maxn) (tree[idx] += val), idx += (idx & -idx);
}



int main()
{
	int n;
	LL ans = 0;
	scanf("%d", &n);
	LL a, b;
	map<int, int> M, F;

	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld", &a, &b);
		males[i] = a;
		females[i] = b;
		all[i] = MP(a, b);
	}
	//assign unique id for males and females
	
	sort(males, males+n);
	sort(females, females+n);

	for(int i=0;i<n;i++)
	{
		M[males[i]] = i + 1;
		F[females[i]] = i + 1;
	}
	for(int i=0;i<n;i++)
	{
		int x = M[all[i].first], y = F[all[i].second];
		line[x] = y;
	}

	for(int i=n;i>=1;i--)
	{
		int x = line[i];
		ans += read(x);
		update(x, +1);
	}
	printf("%lld\n", ans);
}


