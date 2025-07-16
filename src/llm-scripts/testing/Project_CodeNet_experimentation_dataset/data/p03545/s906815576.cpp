#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

string s;

void dfs(string op,int now,int i)
{
	if(i==4)
	{
		if(now==7)
		{
		for(int i =0 ;i<3;i++)cout<<s[i]<<op[i+1];
		cout<<s.back();
		cout<<"=7"<<endl;
		exit(0);
		}
		return;
	}
	dfs(op+'+',now+s[i]-'0',i+1);
	if(i)dfs(op+'-',now-s[i]+'0',i+1);
}

int main()
{
	cin >> s;
	dfs("",0,0);
}
