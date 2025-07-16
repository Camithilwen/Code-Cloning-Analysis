#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = b - 1; i >= a; i--)

int main(){
    int H, W; cin >> H >> W;
    vector<vector<int> > A(H+1, vector<int>(W+1));
    rep(i , 1, H+1) rep(j, 1, W+1) cin >> A[i][j];
    rep(i , 1, H+1) rep(j, 1, W+1) {int t;cin >> t; A[i][j] = abs(A[i][j] - t);}

    bitset<12801> dp[81] = {};
    dp[0][6400] = 1;
    rep(i, 1, H+1){
        rep(j,1,W+1){
            int a = A[i][j];
            dp[j] = ((dp[j-1] | dp[j]) << a) | ((dp[j-1] | dp[j]) >> a);
        }
        dp[0][6400]=0;
    }

    rep(j , 0, 81){
        //cerr << dp[W][6400 + j] << endl;
        if(dp[W][6400 + j]){cout << j << endl; return 0;}
    }
}
