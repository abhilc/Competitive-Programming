#include<iostream>
using namespace std;


int main()
{
	string a;
	int k;

	cin >> a >> k;

	for(int i=0;i+1<a.size();i++)
	{
		int t = i;
		for(int j=i+1;j<a.size()&&j-i<=k;j++)
		{
			if(a[j] > a[t])
				t = j;
		}
		k-=t-i;
		while(t!=i)
		{
			swap(a[t],a[t-1]);
			t--;
		}
	}
	cout << a << "\n";
}
