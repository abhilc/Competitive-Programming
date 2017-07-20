#include<iostream>
using namespace std;


void calc_lps(string ptn, int len, int *lps){
	int index = 0;
	for(int i=1;i<len;){
		if(ptn[index]==ptn[i])
		{
			lps[i] = index + 1;
			index++;
			i++;
		}
		else
		{
			if(index!=0){
				index = lps[index-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}



int main()
{
	string txt, ptn;
	int tests;
	cin >> tests;
	while(tests--)
	{
	cin >> txt >> ptn;
	int lps[300001];
	int index = 0, tests;
	int M = ptn.length();
	calc_lps(ptn, M, lps);
	int Iptn = 0;
	int i = 0, c=0;
	int ptnlen = ptn.length();
	while(i < txt.length())
	{
		if(txt[i]==ptn[Iptn])
		{
			i++;
			Iptn++;
		}
		else
		{
			if(Iptn!=0)
			Iptn = lps[Iptn-1];
			else
				i++;
		}
		if(Iptn == ptn.length())
		{
			c++;
			Iptn = 0;
			i--;
		}
		
	}
	cout << c + (c-1) << "\n";
	}
}
	
