#include<bits/stdc++.h>
using namespace std;
signed main(void){
	string s;
	while(getline(cin,s)){
		while(s.find("this")==s.npos&&s.find("that")==s.npos&&s.find("the")==s.npos)
			for(int i=0;i<(int)s.length();i++){
				if(s[i]>'z'||s[i]<'a')continue;
				if(s[i]!='z')s[i]++;
				else s[i]='a';
			}
		cout<<s<<endl;
	}
}