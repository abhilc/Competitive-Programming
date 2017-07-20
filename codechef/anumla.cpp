#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

#define N 16

int b[1<<N], c[1<<N];
int a[N];


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		
		int m = 1<<n;
		for(int i=0;i<m;i++)
		{
			cin >> b[i];
		}

		sort(b, b+m);

		multiset<int> s;
		int ptr = 0, fptr = 0;

		for(int i=1;i<m;i++)
		{
			int expected = -1;
			if(!s.empty())
				expected = *s.begin();

			if(b[i] == expected)
				s.erase(s.begin());
			else
			{
				a[fptr] = b[i];
				int tptr = ptr;
				for(int j=0;j<tptr;j++){
					c[ptr] = c[j] + a[fptr];
					s.insert(c[ptr]);
					ptr++;
				}
				c[ptr++] = a[fptr];
				fptr++;
			}
		}
		for(int i=0;i<fptr;i++) cout << a[i] << " ";
		cout << "\n";
		
	}
}
