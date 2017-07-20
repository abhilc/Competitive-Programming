#include<iostream>
#include<algorithm>
using namespace std;

pair<long long, long long> a[100500];

long long n, avg, rez, r, i, sum;

int main()
{
	cin >> n >> r >> avg;
	for(int i=0;i<n;i++)
	{
		cin >> a[i].second >> a[i].first;
		sum += a[i].second;
	}
	sort(a, a+n);

	while(sum < n*avg)
	{
		long long tmp = min(avg*n-sum, r-a[i].second);
		rez += tmp*a[i].first;
		sum += tmp;
		i++;
	}
	cout << rez << "\n";
}
	
