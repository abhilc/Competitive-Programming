#include <iostream>
#include <vector>
#include <cstdio>
 
using namespace std;
int ans, n, K;
bool a[10001];
 
int getMax(bool b[])
{
	int s = 0, Os = 0, zeros = -9999, ones = -9999;
	for(int i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			if(zeros < Os)
			{
				zeros = Os;
				Os = 0;
			}
			s++;
		}
		else if(a[i]==0)
		{
			if(ones < s)
			{
				ones = s;
				s = 0;
			}
			Os++;
		}
	}
	return std::max(s, Os);
}
 
int rec(bool list[], int K, int idx)
{
	cout << idx;
	if(K==0 || idx==n)
		cout << getMax(list);
	
	else
	{
		cout << "flipping: " << idx << "\n";
		list[idx] = ~list[idx];
		
		int p = rec(list, --K, ++idx);
		cout << "flipping: " << idx << "\n";
		list[idx] = ~list[idx];
		int q = rec(list, K, ++idx);
		ans = std::min(p, q);
		
	}
	return 1;
	
	
}
int main() {
	int t;
	//scanf("%d", &t);
	
	scanf("%d %d", &n, &K);
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}

	//printf("%d\n", rec(a, K, 0));
	rec(a, K, 0);


	/*while(t--)
	{
		scanf("%d %d", &n, &K);
		for(int i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
		}
		printf("%d\n", rec(a, K, 0));
	}*/
	
	
	// your code goes here
	return 0;
}  
