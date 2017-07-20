#include<iostream>
using namespace std;
 
 
int main()
{
	int T;
	cin >> T;
	while(T--){
		int N, zeroes=0, p=0, done = 0, done2 = 0, a[100001], q = 0;
		cin >> N;
		for(int i=0;i<N;i++)
		{
			cin >> a[i];
			if(a[i]==0)
			{
				done = 1;
				if(done2)
				{
					p++;
					done2 = 0;
				}
			}
			if(a[i]==1)
			{
				//cout << " done: " << done;
				done2 = 1;
				if(done)
				{
					p++;
					done = 0;
				}
			}
		}

		if(a[0]==0 && a[N-1]==1)
			q = 1;
		bool done3 = 0, done4 = 0;
		for(int i=0;i<N;i++)
		{
			if(a[i]==0)
				done3 = 1;
			if(a[i]==1)
				if(done3)
					done4 = 1;
		}

		if(done4)

		cout << N-(((p)/2 + 1) + q) << "\n";

		else cout << 0 << "\n";
	}
}
