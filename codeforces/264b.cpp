#include<iostream>
#include<algorithm>
using namespace std;



int main()
{
	int h[100001];
	int n;
	scanf("%d", &n);
	h[0] = 0;

	for(int i=1;i<=n;i++)
		scanf("%d", &h[i]);

	cout << *std::max_element(h, h+n+1);
	

}
