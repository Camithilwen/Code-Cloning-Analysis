#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll N, S, X[100500], P[100500];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> S;
    for(int i = 1; i <= N; i++) cin >> X[i] >> P[i];
    vector<l_l> before;
    vector<l_l> after;
    for(int i = 1; i <= N; i++) {
        if(X[i] >= S) break;
        before.push_back({X[i], P[i]});
    }
    for(int i = N; i >= 1; i--) {
        if(X[i] <= S) break;
        after.push_back({X[i], P[i]});
    }
    ll sum = 0;
    int cheer = 1;
    vector<l_l> que;
    int after_index = 0;
    int before_index = 0;
    for(int time = 1; time <= N; time++) {
        if(after_index >= after.size()) {
            que.push_back(before[before_index]);
            before_index++;
            continue;
        }
        if(before_index >= before.size()) {
            que.push_back(after[after_index]);
            after_index++;
            continue;
        }
        ll left = before[before_index].second;
        ll right = after[after_index].second;
        if(cheer == 1) {
            left += sum;
        } else {
            right += sum;
        }
        if(right > left) {
            que.push_back(before[before_index]);
            sum += before[before_index].second;
            before_index++;
            cheer = 0;
        } else {
            que.push_back(after[after_index]);
            sum += after[after_index].second;
            after_index++;
            cheer = 1;
        }
    }
    ll ans = 0;
    ll now = S;
    for(int i = que.size() - 1; i >= 0; i--) {
        ans += abs(que[i].first - now);
        now = que[i].first;
    }
    cout << ans << endl;
    return 0;
}
