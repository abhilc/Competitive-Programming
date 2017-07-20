#include<iostream>
typedef long long LL;
#include<algorithm>
using namespace std;


int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int N, Q;
		int L[100001];
		int K;

		cin >> N >> Q;

		for(int i=0;i<N;i++)
		{
			cin >> L[i];
		}
		LL prefSum[100001];
		sort(L, L + N);

		prefSum[0] = L[0];
		
		for(int i=1;i<N;i++)
		{
			prefSum[i] = L[i] + prefSum[i-1];
		}



		int idx, val1, idx2;

		while(Q--)
		{
			scanf("%d", &K);
			int pos = std::lower_bound(L, L+N, K) - L;
			
			int l = 1, r = pos;
			while(l < r)
			{
				int mid = (l + r)/2;
				LL req = 1LL * K * (pos-mid) - (prefSum[pos-1]-prefSum[mid-1]);
				if(req<=mid)
					r = mid;
				else
					l = mid+1;

			}
			cout << N - r << "\n";

		}
	}
}
