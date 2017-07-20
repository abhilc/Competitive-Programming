#include<iostream>
using namespace std;


void lps(string pat, int len, int* temp)
{
	int index=0, j=0;
	for(int i=1;i<len;)
	{
		if(pat[index] == pat[i])
		{
			temp[i] = index+1;
			i++;
			j++;
		}
		else
		{
			if(index!=0)
				index = temp[index-1];
			else
			{
				temp[i] = 0;
				i++;
			}
		}
	}
}




int main()
{
	int len;
	int temp[1000001];
	cin >> len;
	string pat, txt;
	cin >> pat >> txt;
	bool flag=0;

	while(len!=0)
	{
		pat = pat.substr(0, len);
		//cout << "Pattern: " << pat;
		//pat = pat[len]; //bug
		lps(pat, len, temp);
		
		int iPtn = 0, i=0;
		while(iPtn < len && i < txt.length())
		{
			if(pat[iPtn]==txt[i])
			{
				iPtn++;
				i++;
			}
			else
			{
				if(iPtn != 0)
					iPtn = temp[iPtn-1];
				else
					i++;
			}
		}
		if(iPtn == len)
		{
			cout << (i - iPtn) << "\n";
			flag = 1;
			break;
		
		}
		len--;
		
	}
}
