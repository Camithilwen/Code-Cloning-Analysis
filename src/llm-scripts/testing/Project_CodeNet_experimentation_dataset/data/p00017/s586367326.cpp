#include <bits/stdc++.h>
#define rep(i,l,n) for(int i=l;i<n;i++)
#define rer(i,l,n) for(int i=l;i<=n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

string change(string s,int n){
	string ret(s);
	rep(i,0,ret.size()){
		if(ret[i]>='a' && ret[i]<='z'){
			if(ret[i]+n>'z') ret[i]+=n-26;
			else ret[i]+=n;
		}
	}
	return ret;
}

int main(){
	string s;
	string str[3]={"this","that","the"};
	string stu[2]={" ","."};
	while(getline(cin,s)){
		bool f=0;
		rep(i,0,26){
			string t;
			t=change(s,i);
			rep(j,0,3){
				rep(k,0,2){
					if(t.find(str[j]+stu[k])!=string::npos){
						o(t); f=1; break;
					}
				}
				if(f) break;
			}if(f) break;
		}
	}
}