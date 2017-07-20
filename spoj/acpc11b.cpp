#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;



int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int a[1001], b[1001], N, M;
		cin >> N;
		for(int i=0;i<N;i++)
		{
			cin >> a[i];
		}
		cin >> M;
		for(int i=0;i<M;i++)
		{
			cin >> b[i];
		}
		sort(a, a+N);
		sort(b, b+M);
		int it = std::min(M, N);
		//cout << "IT: " << it;
		int minDiff = abs(a[0]-b[0]);
		for(int i = 1;i<it;i++)
		{
			minDiff = std::min(minDiff, abs(a[i]-b[i]));
		}
		int rem = M>N?M:N;

		for(int i=it;it<rem;it++)
		{
			if(rem==M)
				minDiff = std::min(minDiff, abs(a[N]-b[it]));
			else
				minDiff = std::min(minDiff, abs(a[it] - b[M]));
		}
			

		cout << minDiff << "\n";
	}
}
		

