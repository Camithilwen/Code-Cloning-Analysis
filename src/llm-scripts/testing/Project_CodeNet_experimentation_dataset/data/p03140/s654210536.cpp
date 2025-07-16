#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	string s[3];
	for(int i  =0;i<3;i++)cin >> s[i];
	int ans = 0;
	for(int i = 0;i<n;i++)
	{
		int cnt = 0;
		for(int j = 0;j<3;j++)
		{
			if(s[j%3][i]!=s[(j+1)%3][i])cnt++;
		}
		if(cnt==2)ans+=1;
		if(cnt==3)ans +=2;
	}
	cout<<ans<<endl;
	return 0;
}
