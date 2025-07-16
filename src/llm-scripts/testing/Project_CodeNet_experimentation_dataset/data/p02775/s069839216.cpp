#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int (i)=0; (i)<(n); (i)++)
#define REP2(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1000000007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

int dp[1111111][2];

int main(){
    string S;
    cin >> S;
    int N = S.size();
    S += '0';

    for(int i=0; i<1111111; i++)
        dp[i][0] = dp[i][1] = 1<<30;
    dp[0][0] = 0;

    for(int i=0; i<N; i++){
        int d = S[N-1-i] - '0';
        dp[i+1][0] = min(dp[i+1][0], dp[i][0] + d);
        dp[i+1][1] = min(dp[i+1][1], dp[i][0] + (10 - d));
        dp[i+1][0] = min(dp[i+1][0], dp[i][1] + (d + 1));
        dp[i+1][1] = min(dp[i+1][1], dp[i][1] + (10 - (d + 1)));
    }
    int ans = min(dp[N][0], dp[N][1] + 1);
    cout << ans << endl;
    return 0;
}