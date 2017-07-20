#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


int matrix[6101][6101];
char s[6101], r[6101];
int sLength, rLength;


int lcs()
{
	for(int i=0;i<=sLength;i++)
		matrix[i][0] = 0;
	for(int j=0;j<=rLength;j++)
		matrix[0][j] = 0;
	//printf("%s %s", s, r);

	for(int i=1;i<=sLength;i++)
	{
		for(int j=1;j<=rLength;j++)
		{
			if(s[i-1]==r[j-1])
			{
				matrix[i][j] = matrix[i-1][j-1] + 1;
			}
			else
			{
				matrix[i][j] = std::max(matrix[i][j-1], matrix[i-1][j]);
			}
		}
	}
	return matrix[sLength][rLength];
}


int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%s", s);
		sLength = strlen(s);
		rLength = sLength;
		int k = sLength;
		//k-=1;
		int idx = 0;
		while(k--)
		{
			r[idx] = s[k];
			idx++;

		}
		int L = lcs();
		printf("%d\n", sLength - L);


	}
}

