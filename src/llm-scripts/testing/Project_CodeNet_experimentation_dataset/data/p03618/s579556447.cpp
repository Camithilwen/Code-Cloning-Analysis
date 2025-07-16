#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	string s; cin>>s;
	int n=s.length();

	lint hist[128]={};
	rep(i,n) hist[s[i]]++;

	lint ans=1;
	for(int c='a';c<='z';c++) for(int d=c+1;d<='z';d++) {
		ans+=hist[c]*hist[d];
	}
	cout<<ans<<'\n';

	return 0;
}
