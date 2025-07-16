#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
int a,b;
string s;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>a>>b>>s;
	if(s[a]!='-'){
		cout<<"No";
		re 0;
	}
	s.erase(s.begin()+a);
	for(int i=0;i<a+b;i++){
		if(!isdigit(s[i])){
			cout<<"No";
			re 0;
		}
	}
	cout<<"Yes";
	re 0;
}