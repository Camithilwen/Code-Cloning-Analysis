#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2000000010;
constexpr ll INF= 2000000000000000000;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}

// N^P mod M（ただしM == -1の時はmodを取らない）
template<typename T>
T RS(T N, T P, T M){
    if(P == 0) {
        return 1;
    }
    if(P < 0) {
        return 0;
    }
    if(P % 2 == 0){
        ll t = RS(N, P/2, M);
        if(M == -1) return t * t;
        return t * t % M;
    }
    if(M == -1) {
        return N * RS(N,P - 1,M);
    }
    return N * RS(N, P-1, M) % M;
}

int N;
bool flag[310][310][310];
double dp[310][310][310];

double solve(int a,int b,int c) {
    if(flag[a][b][c]) {
        return dp[a][b][c];
    }
    flag[a][b][c] = true;
    if(a == 0 && b == 0 && c == 0) {
        return dp[a][b][c] = 0;
    }
    double fans = 1 / ( 1 - (double)(N - a - b - c) / N);
    if(a > 0) {
        fans += solve(a - 1,b,c) * a / N / (1 - (double)(N - a - b - c) / N);
    }
    if(b > 0) {
        fans += solve(a + 1,b - 1,c) * b / N / (1 - (double)(N - a - b - c) / N);
    }
    if(c > 0) {
        fans += solve(a,b + 1,c - 1) * c / N / (1 - (double)(N - a - b - c) / N);
    }
    return dp[a][b][c] = fans;
}

int main() {
    cin >> N;
    int one = 0;
    int two = 0;
    int three = 0;
    for(int i = 0;i < N;i++) {
        int A;
        cin >> A;
        if(A == 1) {
            one++;
        }
        else if(A == 2) {
            two++;
        }
        else {
            three++;
        }
    }
    for(int i = 0;i < 310;i++) {
        for(int j = 0;j < 310;j++) {
            for(int k = 0;k < 310;k++) {
                flag[i][j][k] = false;
            }
        }
    }
    cout << fixed;
    cout << setprecision(12) << solve(one,two,three) << endl;
}         