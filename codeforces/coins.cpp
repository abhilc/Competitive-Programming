#include<iostream>
#include<cstring>
using namespace std;



int main()
{
	string s1, s2, s3;
	char res1[3], res2[3], res3[3];
	cin >> s1 >> s2 >> s3;

	res1[0] = s1[1]=='>'?s1[2]:s1[0];
	res1[1] = res1[0]==s1[0]?s1[2]:s1[0];

	//cout << res1 << "\n";

	res2[0] = s2[1]=='>'?s2[2]:s2[0];
	res2[1] = res2[0]==s2[0]?s2[2]:s2[0];

	//cout << res2 << "\n";
	
	if(res1[0] == res2[1])
	{
		res3[0] = res1[0];
		res3[1] = res1[1];
		res3[2] = res2[0];
	}
	
	else if(res2[0]==res1[1])
	{
		res3[0]=res1[0];
		res3[1]=res1[1];
		res3[2]=res2[1];
	}
	//cout << res3[0]<<res3[1]<<res3[2];
	//
	else if(res1[0]==res2[0])
	{


	

}

	
	
	
