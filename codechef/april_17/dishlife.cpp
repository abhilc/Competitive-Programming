#include<iostream>
#include<set>
using namespace std;



int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int islands, ing, p, iling;
		bool some = false, all = false;
		set<int> s;
		cin >> islands >> ing;
		for(int i=1;i<=islands;i++)
		{
			cin >> p;
			for(int k=0;k<p;k++)
			{
				cin >> iling;
				s.insert(iling);
			}
			if(s.size()==ing)
			{
				if(i<islands)
				{
					some = true;
				}
				else if(i==islands)
				{
					if(!some)
						all = true;
				}
			}
		}
		if(some)
			cout << "some\n";
		else if(all)
			cout << "all\n";
		else
			cout << "sad\n";
	}
}


		
