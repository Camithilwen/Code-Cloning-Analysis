#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, S;
vector<pii> P, Q;
vector<int> sol;

int main() {
    scanf("%d %d", &N, &S);

    for(int i = 0; i < N; i++) {
        int x, p; scanf("%d %d", &x, &p);
        if(x < S) P.push_back({x, p});
        else Q.push_back({x, p});
    }
    reverse(Q.begin(), Q.end());

    if(P.size() == 0) {
        printf("%d", Q[0].first - S);
        return 0;
    }
    if(Q.size() == 0) {
        printf("%d", S - P[0].first);
        return 0;
    }

    int pos1 = 1, pos2 = 1, dir = (P[0].second < Q[0].second);
    ll sum = 0;
    sol.push_back(P[0].first);
    sol.push_back(Q[0].first);
    sum += P[0].second + Q[0].second;
    if(P[0].second >= Q[0].second) swap(sol[0], sol[1]);
    while(1) {
        if(dir) {
            while(pos1 < P.size() && sum > P[pos1].second) {
                sum += P[pos1++].second;
            }
            if(pos1 < P.size() && sum <= P[pos1].second) {
                sol.push_back(P[pos1].first);
                sum += P[pos1].second;
                pos1++;
                dir ^= 1;
            }
            else break;
        }
        else {
            while(pos2 < Q.size() && sum >= Q[pos2].second) {
                sum += Q[pos2++].second;
            }
            if(pos2 < Q.size() && sum < Q[pos2].second) {
                sol.push_back(Q[pos2].first);
                sum += Q[pos2].second;
                pos2++;
                dir ^= 1;
            }
            else break;
        }
    }
    sol.push_back(S);

    ll ans = 0;
    for(int i = 0; i < (int)sol.size() - 1; i++) {
        ans += abs(sol[i] - sol[i + 1]);
    }
    printf("%lld", ans);
}
