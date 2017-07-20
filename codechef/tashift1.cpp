#include<iostream>
using namespace std;




int main()
{
	int N;
	int lps[1000001];
	cin >> N;
	string A, B;
	cin >> A >> B;
	int n = 2 * N, m = N;
	B = B + B;
	int index = 0;
	for(int i=1;i<N;)
	{
		if(A[index] == B[i])
		{
			lps[i] = index+1;
			i++;
			index++;
		}
		else
		{
			if(index!=0)
				index = lps[index-1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	int i=0, j=0, best=0, ans=0, res;
	while(i<n)
	{
		if(A[j] == B[i])
		{
			i++;
			j++;
			best++;
		}
		if(res < best)
		{
			res = best;
			ans = i-j;
		}
		if(A[j]!=B[i]){
			best = 0;
			if(j!=0)
				j = lps[j-1];
			else
				i++;
		}
	}
	cout << ans << "\n";
}


