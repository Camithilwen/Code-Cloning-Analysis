#include "bits/stdc++.h"

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

#define dump(x)  cerr << #x << " = " << (x) << endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back

char sub(char ch){
	if(ch=='a')return 'z';
	else return ch-1;
}


bool solve(string s){
	string tmp="";
	rep(i,s.size()){
		if(isalpha(s[i])){
			tmp+=s[i];
		}
		else{

			if( tmp=="the" || tmp=="this" || tmp=="that" )return true;

			tmp="";
		}
	}
	return false;
}

int main(){
	string s;
	while(getline(cin,s)){
		while(1){
			rep(i,s.size()){
				if(isalpha(s[i]))s[i]=sub(s[i]);
			}
			if(solve(s))break;
		}
		cout<<s<<endl;
	}
}