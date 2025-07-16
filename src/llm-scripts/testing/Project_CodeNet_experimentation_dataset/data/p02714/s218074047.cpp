#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <unordered_map>
typedef long long ll;
using namespace std;
const int mod=1e9+7;
const ll inf=(1e14);

ll solve(){
	ll n,ans=0;
	string s;
	cin>>n>>s;
	int r[n],g[n],b[n];
	g[n-1]=r[n-1]=b[n-1]=r[0]=g[0]=b[0]=0;
	unordered_map<char,int*> m;
	m['R']=r,m['G']=g,m['B']=b;
	for(const char c:{'R','G','B'}){
		for(int i=n-2;i>=0;i--) m[c][i]=m[c][i+1]+(s[i+1]==c);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(const char c:{'R','G','B'}){
				if(s[i]!=c && s[j]!=c && s[i]!=s[j]){
					ans+=(m[c][j]);
					if(j+(j-i) < n && s[j+(j-i)] == c) ans--;
				}
			}
		}
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t=1;
    //cin>>t;
    while(t--) cout<<solve()<<'\n';
    //while(t--) solve(),cout<<'\n';
    return 0;
}
