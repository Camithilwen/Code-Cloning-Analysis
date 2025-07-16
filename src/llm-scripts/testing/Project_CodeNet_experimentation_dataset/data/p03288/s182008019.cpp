/*
Author : Devil088
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define sep cout<<"\n";
#define Yes cout<<"Yes\n";
#define No cout<<"No\n";
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

inline string shift(string s){
	int n = s.length();
	string r = "";
	r+=s[n-1];
	for(int i=0;i<n-1;i++)r+=s[i];
	return r;
}

int main(){
	int n;
	cin>>n;
	
	if(n<1200){
		cout<<"ABC\n";
	}else if(n<2800){
		cout<<"ARC\n";
	}else cout<<"AGC\n";
}
/*
uday
adyu
7 46
45 6
*/

