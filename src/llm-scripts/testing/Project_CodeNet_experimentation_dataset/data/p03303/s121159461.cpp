#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s; int w; cin>>s>>w;
	int k=s.size();
	rep(i,k){
		if(i%w==0) cout<<s[i];
	}
	cout<<endl;
}