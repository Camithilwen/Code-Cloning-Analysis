#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	if(s.length()<26){
		char c='a';
		rep(i,s.length()) if(s[i]==c) c++, i=-1;
		s+=c;
		cout<<s<<'\n';
	}
	else{
		string t=s;
		if(next_permutation(t.begin(),t.end())){
			while(t.substr(0,t.length()-1)>s) t=t.substr(0,t.length()-1);
			cout<<t<<'\n';
		}
		else{
			cout<<"-1\n";
		}
	}
	return 0;
}
