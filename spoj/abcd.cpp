#include<iostream>
#include<vector>
using namespace std;

int main()
{

		int N;
		cin >> N;
		string S;
		cin >> S;
		vector<char> ans;

		for(int i=0;i<=S.length()-2;i+=2)
		{
			if((S[i]=='A' && S[i+1]=='B') || (S[i]=='B' && S[i+1]=='A'))
			{
				ans.push_back('C');
				ans.push_back('D');
			}
			if((S[i]=='B' && S[i+1]=='C') || (S[i]=='C' && S[i+1]=='B'))
			{
				ans.push_back('A');
				ans.push_back('D');
			}
			if((S[i]=='A' && S[i+1]=='C') || (S[i]=='C' && S[i+1]=='A'))
			{
				ans.push_back('B');
				ans.push_back('D');
			}
			if((S[i]=='A' && S[i+1]=='D') || (S[i]=='D' && S[i+1]=='A'))
			{
				ans.push_back('B');
				ans.push_back('C');
			}
			if((S[i]=='B' && S[i+1]=='D') || (S[i]=='D' && S[i+1]=='B'))
			{
				ans.push_back('A');
				ans.push_back('C');
			}
			if((S[i]=='C' && S[i+1]=='D') || (S[i]=='D' && S[i+1]=='C'))
			{
				ans.push_back('B');
				ans.push_back('A');
			}

			

		}
		char prev, next;
		for(int i=0;i<ans.size();i++)
		{
			next = ans[i];
			if(prev != next)
			{
				cout << ans[i];
				prev = next;
			}
			else
			{
				swap(ans[i], ans[i+1]);
				cout << ans[i] << ans[i+1];
				i+=1;
			}
		}
			
}
		

