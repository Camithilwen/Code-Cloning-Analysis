#include <bits/stdc++.h>
using namespace std;
#define int long long int

char arr[405][405];
bool vis[405][405];
int h, w;
int cb;
int cw;

bool f(int i, int j, int l, int m){
	if(l<0 || l>=h || m<0 || m>=w){
		return 0;
	}
	if(vis[l][m]==1){
		return 0;
	}
	if(arr[i][j]==arr[l][m]){
		return 0;
	}
	return 1;
}

void dfs(int i, int j){
	vis[i][j]=1;
	if(arr[i][j]=='#'){
		cb++;
	}
	else{
		cw++;
	}
	if(f(i, j, i+1, j)){
		dfs(i+1, j);
	}
	if(f(i, j, i, j+1)){
		dfs(i, j+1);
	}
	if(f(i, j, i-1, j)){
		dfs(i-1, j);
	}
	if(f(i, j, i, j-1)){
		dfs(i, j-1);
	}
}


main() {
	cin>>h>>w;
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin>>arr[i][j];
		}
	}
	int ans=0;
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(vis[i][j]==0){
				dfs(i, j);
				ans+=(cb*cw);
				cb=0;
				cw=0;
			}
		}
	}
	cout<<ans;
	return 0;
}