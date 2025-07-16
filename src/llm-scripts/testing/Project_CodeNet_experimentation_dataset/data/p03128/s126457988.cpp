#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;
typedef pair<int,int> P;

vector<int> num = {0,2,5,5,4,5,6,3,7,6};

string maxs(string S, string T){
    if(S.length() > T.length()){
        return S;
    } else if (S.length() < T.length()){
        return T;
    } else {
        return (S < T) ? T : S;
    }
}

int main(){
    int N, M; vector<int> A(9);

    cin >> N >> M;
    rep(i,M) cin >> A[i];

    // dp[i]: マッチちょうどi本で作れる最大値
    vector<string> dp(10010, "");
    rep(i,N) rep(j,M){
        if(dp[i] == "" && i != 0) continue;

        char c = A[j] + '0';
        if(i+num[A[j]] <= N){
            string next = dp[i] + c;
            dp[i+num[A[j]]] = maxs(dp[i+num[A[j]]], next);
        }
    }

    cout << dp[N] << endl;
}
