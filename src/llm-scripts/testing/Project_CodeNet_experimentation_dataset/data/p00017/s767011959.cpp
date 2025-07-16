#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,t;
	while(getline(cin,s)){t=s;
	for(int i=0;i<26;i++){
		s=t;
		for(int j=0;j<s.size();j++){
			if(s[j]>='a'&&s[j]<='z')for(int k=0;k<i;k++){
				s[j]++;
				if(s[j]>'z')s[j]-=26;
			}
		}
		if((s.find("the")!=s.npos||s.find("this")!=s.npos||s.find("that")!=s.npos))break;
	}
	cout<<s<<endl;}
}