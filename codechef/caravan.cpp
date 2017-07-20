#include<iostream>
using namespace std;



int main()
{
	int tests;
	scanf("%d", &tests);
	while(tests--)
	{
		int cars, speed;
		scanf("%d", &cars);
		int ans = 1, front_speed;
		scanf("%d", &front_speed);
		for(int i=1;i<cars;i++)
		{
			scanf("%d", &speed);
			if(speed < front_speed)
			{
				ans++;
				front_speed = speed;
			}
		}
		printf("%d\n", ans);
	}
}
