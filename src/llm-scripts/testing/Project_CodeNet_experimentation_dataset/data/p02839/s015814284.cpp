#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int H,W;cin>>H>>W;
	int A[H][W] = {}; int a;
	rep(i,0,H)rep(j,0,W){ cin>>a; A[i][j] += a; }
	rep(i,0,H)rep(j,0,W){ cin>>a; A[i][j] -= a; }
	bool dp[H+1][W+1][12801] = {}; dp[0][1][0] = 1;
	rep(i,1,H+1)rep(j,1,W+1){
        int t = abs(A[i-1][j-1]);
		rep(k,0,12801){
			if(k + t <= 12800) dp[i][j][k+t] |= dp[i-1][j][k] | dp[i][j-1][k];
            dp[i][j][abs(k - t)] |= dp[i-1][j][k] | dp[i][j-1][k];
		}
	}
	rep(i,0,12801){
		if(dp[H][W][i]){
            cout<<i<<endl;
            break;
        }
	}
}