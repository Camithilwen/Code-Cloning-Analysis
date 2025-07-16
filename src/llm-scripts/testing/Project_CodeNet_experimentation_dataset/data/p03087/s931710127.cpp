#include<bits/stdc++.h>
using namespace std;
int ac[100005];
char ch[100005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	string s;
	cin>>n>>q>>s;
	for(int i=0; s[i]; i++) ch[i+1] = s[i];
	for(int i=1; i<=n; i++){
		if(ch[i]=='A' && ch[i+1]=='C') ac[i]++;
	}
	for(int i=1; i<=n; i++) ac[i]+=ac[i-1];
	while(q--){
		int a,b;
		cin>>a>>b;
		int ret = ac[b]-ac[a-1];
		if(ch[b]=='A' && ch[b+1]=='C') ret--;
		cout<<ret<<'\n';
	}
}