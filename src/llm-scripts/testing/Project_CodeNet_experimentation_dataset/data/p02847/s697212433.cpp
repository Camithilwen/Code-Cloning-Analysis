#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	char s[4]={};
	cin>>s;
	if(s[0]=='S'){
		if(s[1]=='U'){
			cout<<7<<endl;
		}else{
			cout<<1<<endl;
		}
	}else if(s[0]=='M'){
		cout<<6<<endl;
	}else if(s[0]=='W'){
		cout<<4<<endl;
	}else if(s[0]=='F'){
		cout<<2<<endl;
	}else if(s[0]=='T'){
		if(s[1]=='U'){
			cout<<5<<endl;
		}else{
			cout<<3<<endl;
		}
	}
}