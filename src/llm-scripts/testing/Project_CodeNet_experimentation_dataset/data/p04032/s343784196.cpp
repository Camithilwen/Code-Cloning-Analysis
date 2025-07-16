#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
string s;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>s;
	for(int i=0;i+2<sz(s);i++){
		if(s[i]==s[i+1]||s[i]==s[i+2]||s[i+1]==s[i+2]){
			cout<<i+1<<' '<<i+3;
			re 0;
		}
	}
	if(sz(s)==2&&s[0]==s[1]) cout<<"1 2";
	else cout<<"-1 -1";
	re 0;
}