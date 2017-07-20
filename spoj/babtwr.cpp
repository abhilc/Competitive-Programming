#include<iostream>
#include<algorithm>
#include<vector>
typedef std::pair<int, int> ii;
typedef std::pair<ii, int> pii;
using namespace std;

int box[33][3];
vector<pii> stack;


int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<3;j++)
		cin >> box[i][j];
	}

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<3;j++)
		{
			//cout << box[i][j] << " " << box[i][(j+1)%3] << " " << box[i][(j+2)%3];
			int a = box[i][j];
			int b = box[i][(j+1)%3];
			int c = box[i][(j+2)%3];
			if(b < c) swap(b, c);
			stack.push_back({{b, c}, a});
		}
	}
	sort(stack.rbegin(), stack.rend());
	int T[3 * N];

	for(int i=0;i<stack.size();i++)
	{
		pii bx = stack[i];
		T[i] = bx.second;
		//cout << T[i] << "\n";
	}

	for(int i=1;i<3*N;i++)
	{
		//cout << T[i] << " ";
		
		for(int j=0;j<i;j++)
		{
			//cout << T[j] << " ";
			pii box_top = stack[i], box_bottom = stack[j];		//Can the box at i go on top of box at j? If yes, height at box i = height of j + height of i
			if(box_top.first.first < box_bottom.first.first && box_top.first.second < box_bottom.first.second) //Baselines of top box < baselines of bottom 
			{
				T[i] = T[j] + T[i];
				//cout << T[i] << " ";
				//cout << " " <<  T[i] << " ";
			}
		}
	}
	int area[3*N];
	for(int i=0;i<stack.size();i++)
	{
		pii item = stack[i];
		cout << item.first.first << " " << item.first.second << "\n";
		area[i] = item.first.first * item.first.second;
	}

	for(int i = 0;i<3*N;i++)
		cout << area[i] << " ";
	
	/*int max = -1;
	for(int i=0;i<3*N;i++)
	{
		if(max < T[i])
			max = T[i];
	}
	//cout << max << "\n";*/
}

		



	
