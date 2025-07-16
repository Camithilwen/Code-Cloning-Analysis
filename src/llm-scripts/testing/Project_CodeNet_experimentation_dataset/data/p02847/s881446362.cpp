//https://atcoder.jp/contests/abc146/tasks/abc146_a
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string x;
	cin>>x;
	if(x=="SUN")
	{
		cout<<"7"<<"\n";
	}
	else if(x=="MON")
	{
		cout<<"6"<<"\n";
	}
	else if(x=="TUE")
	{
		cout<<"5"<<"\n";
	}
	else if(x=="WED")
	{
		cout<<"4"<<"\n";
	}
	else if(x=="THU")
	{
		cout<<"3"<<"\n";
	}
	else if(x=="FRI")
	{
		cout<<"2"<<"\n";
	}
	else if(x=="SAT")
	{
		cout<<"1"<<"\n";
	}
	return 0;
}
