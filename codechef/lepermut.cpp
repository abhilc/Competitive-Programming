#include<iostream>
using namespace std;




int main()
{
	int tests;
	cin >> tests;
	while(tests--)
	{
		int N, li=0, gi=0, a[101];
		cin >> N;
		for(int i=0;i<N;i++)
		{
			cin >> a[i];
		}
		for(int i=0;i<N;i++)
		{
			for(int j=i+1;j<N;j++)
			{
				if(j==(i+1))
				{
					if(a[i]>a[j]){
						li++;
						gi++;
					}
				}
				else{
						if(a[i]>a[j])
							gi++;
				}
			}
		}
		if(li==gi)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}



