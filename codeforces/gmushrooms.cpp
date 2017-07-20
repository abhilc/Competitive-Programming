#include<iostream>
#include<algorithm>
using namespace std;



struct Contestant
{
	int id;
	double value;

	bool operator<(const Contestant &other) const{
		if(value != other.value)
			return value > other.value;

		return id < other.id;
	}
};


Contestant C[1001];



int main()
{
	int n, t1, t2, k, a, b;
	cin >> n >> t1 >> t2 >> k;

	for(int i=0;i<n;i++)
	{
		cin >> a >> b;
		if(a > b)
			swap(a, b);

		C[i].id = i+1;
		C[i].value = (a * t1 * (k/100.0)) + (b * t2);
	}

	sort(C, C+n);

	for(int i=0;i<n;i++)
		printf("%d %.2f\n", C[i].id, C[i].value);
}

