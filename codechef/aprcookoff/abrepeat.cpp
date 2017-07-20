#include<iostream>
using namespace std;



int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		long long n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		long long cmb = 0, cnta = 0, cntb = 0;

		for(int i=s.length()-1;i>=0;i--)
		{
			if(s[i]=='b')
			{
				cntb++;
			}
			else if(s[i]=='a')
			{
				cmb += cntb;
				cnta++;
			}
		}

		long long ptwostrings = (long long) cnta * cntb;
		printf("%lld\n", cmb * k + ptwostrings*k*(k-1)/2);



		
		//cout << (cmb * k) + (cnta * (((k * (k-1))/2) * cntb)) << "\n";
	}
}
