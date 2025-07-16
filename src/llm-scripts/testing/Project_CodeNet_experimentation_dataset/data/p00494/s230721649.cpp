#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
 
using namespace std;
 
#define rep(i,n) for(int i=0; i<(n); i++)
#define repc(i,s,e) for(int i=(s); i<(e); i++)
#define pb(n) push_back((n))
#define mp(n,m) make_pair((n),(m))
#define all(r) r.begin(),r.end()
#define fi first
#define se second
 
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int INF=1e9;

void print(vi v){
	for(int i = 0; i < v.size(); i++){
		cout<<" "<<v[i];
	}
	cout<<endl;
}

int main(){
	string s;

	cin>>s;

	vi v(s.size(), 1);
	
	for(int i = 1; i < s.size(); i++){
		if(s[i]==s[i-1]){
			v[i]=v[i-1]+1;
		}
		else{
			reverse(v.begin()+(i-v[i-1]),v.begin()+i);
		}
	}
	reverse(v.begin()+(v.size()-1-v[v.size()-2]),v.begin()+(v.size()));
	//print(v);
	//print(v);
	int ans = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i]=='J'){
			if(i+v[i]<s.size() && s[i+v[i]]=='O' && v[i+v[i]]==v[i]){
				if(i+v[i]*2<s.size() && s[i+v[i]*2]=='I' && v[i+v[i]*2]>=v[i+v[i]]){
					ans=max(ans,v[i]);
				}
			}
		}
	}
	cout<<ans<<endl;
}