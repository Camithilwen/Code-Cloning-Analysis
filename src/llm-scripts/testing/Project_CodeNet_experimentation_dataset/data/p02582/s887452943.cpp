#include <bits/stdc++.h>
using namespace std;



int main()
{
    
	ios_base::sync_with_stdio(false); cin.tie(NULL);


	
	int cnt=0;
	string s;
	cin>>s;

	int m =0;

	for(int i =0 ;i<3;i++)
	{
		if(s[i]=='R')m++;
		else
		{
			cnt = max(m,cnt);
			m =0;
		}
	}
	cnt = max(m,cnt);
	
	cout<<cnt;
    return 0;
		
}






