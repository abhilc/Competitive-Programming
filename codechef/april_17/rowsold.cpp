#include<iostream>
using namespace std;


int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string bin;
		cin >> bin;
		long long n = bin.length(), czero=0, init_ans=0;
		
		for(int i=n-1;i>=0;i--)
		{
			if(bin[i]=='0')
			{
				czero++;
			}
			else if(bin[i]=='1')
			{
				init_ans += czero; //Only Movement. Picking time not considered
			}
		}
		long long prev = -1, ans=0, cz=0;
		for(int i=n-1;i>=0;i--)
		{
			if(bin[i]=='0')
			{
				if(prev != 0)
				{
					cz++;
					prev = 0;
				}
			}
			else if(bin[i]=='1')
			{
				ans+=cz;          //Picking time. 
				prev = 1;
			}
		}
		cout << init_ans + ans << "\n"; //Picking time + movement time


	}
}

