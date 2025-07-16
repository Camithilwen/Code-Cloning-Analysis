#include<bits/stdc++.h>
using namespace std;
int psum[505][505];
int main(){
	int n,m,q;
	cin>>n>>m>>q;
	while(m--){
		int l,r;
		cin>>l>>r;
		psum[r][l]++;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++) psum[i][j]+=psum[i][j-1];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++) psum[i][j]+=psum[i-1][j];
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<psum[r][n]-psum[r][l-1]<<'\n';
	}
}