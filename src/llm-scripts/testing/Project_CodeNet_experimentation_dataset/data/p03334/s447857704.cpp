#include<bits/stdc++.h>
using namespace std;
 
int n,D_1,D_2,cnt;
 
bool chk(int i,int j,int d){
	int u=__builtin_ctz(d);
	if(u&1)return!(i>>(u/2)&1);
	else return!((i^j)>>(u/2)&1);
}
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>D_1>>D_2;
	for(int i=0;i<2*n;++i)
		for(int j=0;j<2*n;++j)
			if(chk(i,j,D_1)&&chk(i,j,D_2)){
				cout<<i<<' '<<j<<'\n';
				if(++cnt>=n*n)return 0;
			}
	return 0;
}