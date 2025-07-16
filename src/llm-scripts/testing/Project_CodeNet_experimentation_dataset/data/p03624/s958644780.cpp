//#include "stdafx.h"
#include<bits/stdc++.h> 
#include<iostream>
#include<queue>
#include<string>
using namespace std;
string s;
int  ans[26],f;
int main()
{
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		ans[s[i]-'a']++;
	}
		
	for(int i=0;i<26;i++){
		if(ans[i]==0){
			cout<<char('a'+i)<<"\n";
			f=1;
			break;
		}
	}
	if(f==0)
		cout<<"None\n";

	
	
	

	return 0;
}

