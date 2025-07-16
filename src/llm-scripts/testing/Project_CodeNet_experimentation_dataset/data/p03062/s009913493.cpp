#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;



int main(){
    int N; cin >> N;
    vi A(N);
    for(auto &x : A)cin >> x;

    vector<vector<ll>> dp(N+1, vector<ll>(2, 0));
    dp[0][1]=-INF;
    for(int i=0; i<N; i++){
        dp[i+1][0]=max(dp[i][0]+A[i], dp[i][1]-A[i]);
        dp[i+1][1]=max(dp[i][0]-A[i], dp[i][1]+A[i]);
    }
    cout << dp[N][0] << endl;
    return 0;
}