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
	int lps[1001];
	cin >> txt >> ptn;
	int index = 0;
	int M = ptn.length();
	calc_lps(ptn, M, lps);
	int Iptn = 0;
	int i = 0;
	while(Iptn < ptn.length() && i < txt.length())
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
		
	}
	if(Iptn == ptn.length())
	{
		cout << "Yes\n";
		cout << i - Iptn;
	}
	else
		cout << "No!!\n";
}
	
