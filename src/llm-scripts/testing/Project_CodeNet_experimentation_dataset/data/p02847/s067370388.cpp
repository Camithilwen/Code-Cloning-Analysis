#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<stack>
#include<iostream>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vec(a) vector<int>a
using namespace std;
//fibonacci
int binet(int n)
{
	return (pow((1+sqrt(5)),n-1)-pow((1-sqrt(5)),n-1))/(pow(2,n-1)*sqrt(5));
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	fastio
	string str;
	cin>>str;
	if(str=="SUN")
		cout<<7<<"\n";
	if(str=="MON")
		cout<<6<<"\n";
	if(str=="TUE")
		cout<<5<<"\n";
	if(str=="WED")
		cout<<4<<"\n";
	if(str=="THU")
		cout<<3<<"\n";
	if(str=="FRI")
		cout<<2<<"\n";
	if(str=="SAT")
		cout<<1<<"\n";
	return 0;
}
	