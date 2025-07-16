#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll N, x[100500], M, K, a[100050];
ll dp[100050][70];
ll ans_delta[100050];
int f(int index, ll time) {
    //cout << index << " " << time << endl;
    if(time == 0) {
        return index;
    }
    ll now = 1;
    ll dp_index = 0;
    while(now * 2 <= time) {
        now *= 2;
        dp_index++;
    }
    int NEW = dp[index][dp_index];
    return f(NEW, time - now);
}

int main() {
    cout.precision(10);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> x[i];
    }
    cin >> M >> K;
    //cout << N << " " << M << " " << K << endl;
    for(int i = 1; i <= M; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < N; i++) {
        dp[i][0] = i;
    }
    for(int i = 1; i <= M; i++) {
        swap(dp[a[i] - 1][0], dp[a[i]][0]);
    }
    for(int i = 1; i < N; i++) {
        //cout << i << " " << dp[i][0] << endl;
    }
    for(int i = 1; i < 70; i++) {
        for(int delta = 1; delta < N; delta++) {
            int before = dp[delta][i - 1];
            dp[delta][i] = dp[before][i - 1];
            //cout << i << " " << delta << " " << dp[delta][i] << endl;
        }
    }
    for(int i = 1; i < N; i++) {
        ans_delta[i] = f(i, K);
        //cout << i << " " << ans_delta[i] << endl;
    }
    ll sum = x[1];
    cout << sum << endl;
    for(int i = 1; i < N; i++) {
        ll delta = x[ans_delta[i] + 1] - x[ans_delta[i]];
        sum += delta;
        cout << sum << endl;
    }
    return 0;
}
