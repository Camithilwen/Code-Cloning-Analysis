#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n);++i)
using namespace std;
const long long inf = 1ll << 60;
const long long mod = 1000000007;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int dz[4] = {1,-1,-1,1};
int dw[4] = {1,1,-1,-1};
int main() {
    int n;cin >> n;
    vector<pair<int,int> > x(n);
    rep(i,n) cin >> x[i].first >> x[i].second;
    vector<int> a(8);
    rep(i,8) a[i]=i;
    do{
	bool board[8][8] = {false};
	for(int i=0;i<8;i++){
	    board[i][a[i]] = true;    	    
	}
	bool ok = true;
	rep(i,n){ 
	   if(board[x[i].first][x[i].second] == false) ok = false;
	}
	if(ok == false) continue;
	for(int i=0;i<8;i++){
	    for(int j=0;j<4;j++){
		int t = 1;
		while(1){
		    int s = i+dz[j]*t;
		    int r = a[i]+dw[j]*t;
		    if(s < 0 || 8 <= s || r < 0 || 8 <= r)break; 
		    if(board[s][r]==true) ok = false;
		    t++;
		}
	    }
	}
	if(ok){
	    rep(i,8){
		rep(j,8){
		    if(board[i][j]) cout <<"Q";
		    else cout <<".";
		}
		cout << endl;
	    }
	    break;
	}
    }while(next_permutation(a.begin(),a.end()));
    return 0;
}

