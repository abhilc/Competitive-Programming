#include<iostream>
#include<deque>
using namespace std;


int main()
{

		int n;
		cin >> n;
		int arr[1000001];
		for(int i=0;i<n;i++)
			cin >> arr[i];

		int k;
		cin >> k;

		deque<int> Qi(k);
		int i;

		for(i=0;i<k;++i)
		{
			while(!Qi.empty() && arr[i] >= arr[Qi.back()])
				Qi.pop_back();

			Qi.push_back(i);
		}

		for(;i<=n;++i)
		{
			cout << arr[Qi.front()] << " ";

			while(!Qi.empty() && Qi.front() <= i - k)
				Qi.pop_front();

			while(!Qi.empty() && arr[i] >= arr[Qi.back()])
				Qi.pop_back();

			Qi.push_back(i);
		}
}


		


