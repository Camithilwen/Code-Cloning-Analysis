#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
bool ch[82][82][13000];
int main() {
	ll h,w;
	cin>>h>>w;
	ll a[82][82],b[82][82];
	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			cin>>a[i][j];
		}
	}
	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			cin>>b[i][j];
		}
	}
	ll c[82][82];
	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			c[i][j]=abs(a[i][j]-b[i][j]);
	//		cout << c[i][j];
		}
//		cout <<endl;
	}
	ch[0][0][c[0][0]]=true;
	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			for(ll k=0;k<13000;k++){
				if(i!=0&&ch[i-1][j][k]==true){
					ll now=c[i][j];
					ch[i][j][k+now]=true;
					ch[i][j][abs(k-now)]=true;
				}
				if(j!=0&&ch[i][j-1][k]==true){
					ll now=c[i][j];
					ch[i][j][k+now]=true;
					ch[i][j][abs(k-now)]=true;
				}				
			}
		}
	}
	for(ll i=0;i<13000;i++){
		if(ch[h-1][w-1][i]){
			cout <<i<<endl;
			return 0;
		}
	}
	// your code goes here
	return 0;
}