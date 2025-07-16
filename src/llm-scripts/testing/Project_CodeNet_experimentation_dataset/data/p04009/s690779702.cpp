#include <bits/stdc++.h>
using namespace std;

void chmax(int& a, int b){
    a = max(a, b);
}

int main(){
    int H, W;
    cin >> H >> W;
    string S[101];
    S[0] = string('!', W+1);
    int ER, EC;
    for(int i=1; i<=H; i++){
        cin >> S[i];
        S[i].insert(0, "!");
        if(S[i].find('E') != -1){
            ER = i;
            EC = S[i].find('E');
        }
    }

    int RS[101][101] = {0}, CS[101][101] = {0};
    for(int i=1; i<=H; i++) for(int j=1; j<=W; j++){
        RS[i][j] = RS[i][j-1];
        CS[i][j] = CS[i-1][j];
        if(S[i][j] == 'o'){
            RS[i][j]++;
            CS[i][j]++;
        }
    }

    static int dp[101][101][101][101];
    for(int u=0; ER-u>0; u++) for(int d=0; ER+d<=H; d++){
        for(int l=0; EC-l>0; l++) for(int r=0; EC+r<=W; r++){
            int ub = max(ER-u, d+1), db = min(ER+d, H-u);
            int lb = max(EC-l, r+1), rb = min(EC+r, W-l);
            if(ER-u-1 > 0){
                int add = 0;
                if(ER-u-1 >= d+1) chmax(add, RS[ER-u-1][rb] - RS[ER-u-1][lb-1]);
                chmax(dp[u+1][d][l][r], dp[u][d][l][r] + add);
            }
            if(EC-l-1 > 0){
                int add = 0;
                if(EC-l-1 >= r+1) chmax(add, CS[db][EC-l-1] - CS[ub-1][EC-l-1]);
                chmax(dp[u][d][l+1][r], dp[u][d][l][r] + add);
            }
            if(ER+d+1 <= H){
                int add = 0;
                if(ER+d+1 <= H-u) chmax(add, RS[ER+d+1][rb] - RS[ER+d+1][lb-1]);
                chmax(dp[u][d+1][l][r], dp[u][d][l][r] + add);
            }
            if(EC+r+1 <= W){
                int add = 0;
                if(EC+r+1 <= W-l) chmax(add, CS[db][EC+r+1] - CS[ub-1][EC+r+1]);
                chmax(dp[u][d][l][r+1], dp[u][d][l][r] + add);
            }
        }
    }
    cout << dp[ER-1][H-ER][EC-1][W-EC] << endl;
    return 0;
}
