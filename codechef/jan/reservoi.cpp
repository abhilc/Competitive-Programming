#include<iostream>
using namespace std;


int main()
{
	int tests;
	cin >> tests;
	while(tests--)
	{
		int N, M; 
		char res[2001][2001];
		cin >> N >> M;
		bool flag = 1;
		
		for(int i=N;i>=1;i--)
		{
			for(int j=1;j<=M;j++)
			{
				cin >> res[i][j];
			}
		}
		int dy[4] = {0, 0, 1, -1};
		int dx[4] = {1, -1, 0, 0};
		int nr = 0, nc = 0;

		for(int i=N;i>=1;i--)
		{
			for(int j=1;j<=M;j++)
			{
				if(res[i][j] == 'W')
				{
					if(j==1 || j==M || i==1)
					{
						flag=0;
						//cout << "border!!\n";
						break;
					}
					else
					{
						for(int k=1;k<4;k++)
						{
							nr = i + dx[k];
							nc = j + dy[k];
							
							if(res[nr][nc] == 'A' && ((nr>=1 && nr<=N) && (nc<=M && nc>=1) ))
							{
								//cout << "Air under water!!\n";
								flag = 0;
								break;
							}
						}
					
					}
				
				}
				else if(res[i][j] == 'A')
				{

					nr = i + dx[0];
					nc = j + dy[0];
					if((res[nr][nc] == 'B' || res[nr][nc] == 'W') && ((nr<=N && nr>=1) && (nc<=M && nc>=1)))
					{
						//cout << "Brick over air!!\n";
						flag = 0;
						break;
					}
				}
			}
			if(!flag)
			{
				break;
			}

		}
		if(!flag)
			cout << "no\n";
		else
			cout << "yes\n";
	}
}
		
