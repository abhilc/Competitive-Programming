#include<iostream>
using namespace std;


long long a, b, c, s_a=0, s_b=0, steps=0, l=0;

long long gcd(long long a, long long b)
{
     return b ? gcd(b, a % b) : a;    
}


int solve(int a, int b)
{
		s_a = 0, s_b = 0, steps = 0;

		if(c%gcd(a, b)!=0 || c > std::max(a, b))
		{
			return -1;
		}



		while(s_b != c && s_a!=c)
		{
			if(a <= b)
			{
			if(s_a == 0)
			{
				s_a = a;
				steps++;
			}
			if(s_b == b)
			{
				s_b = 0;
				steps++;
			}
			else
			{
				if(b-s_b >= s_a)
				{
					s_b = s_b + s_a;
					s_a = 0;
					steps++;
				}
				else
				{
					s_a = s_a - (b-s_b);
					s_b = b;
					steps++;
				}

			}
			}

			else if(a > b)
			{
				if(s_a == 0)
				{
					s_a = a;
					steps++;
				}
				if(s_b == b)
				{
					s_b = 0;
					steps++;
				}
				else
				{
					if(b-s_b <= s_a)
					{
						s_a = s_a - (b-s_b);
						s_b = b;
						steps++;
					}
					else
					{
						s_b = s_b + s_a;
						s_a = 0;
						steps++;
					}
				}
			}


		}
		return steps;
}



int main()
{
	long long t;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		if(a==c || b==c)
			printf("%d\n", 1);
		else

		printf("%d\n", std::min(solve(a, b), solve(b, a)));

	}
}
