#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	if(s[0]=='S'){
		if(s[1]=='U') cout<<7;
		else cout<<1;
	}
	else if(s[0]=='M') cout<<6;
	else if(s[0]=='T'){
		if(s[1]=='U') cout<<5;
		else cout<<3;
	}
	else if(s[0]=='W') cout<<4;
	else if(s[0]=='F') cout<<2;
}