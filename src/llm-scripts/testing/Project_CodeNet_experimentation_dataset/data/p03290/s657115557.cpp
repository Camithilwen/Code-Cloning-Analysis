#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18


int main() {
    int D,G; cin >> D >> G;
    vector<pair<ll,ll>> score(D+1);
    REP(i,D){
        int p,c; cin >> p >> c;
        score[i] = {p,c};
    }
    
    int ans = INF;
    REP(bit, 1<<D){
        vector<int> S(D,0);
        int sum = 0;
        int cnt = 0;

        REP(i,D){
            if(bit & (1<<i)){
                S[i] = 1;
                sum += score[i].first*(i+1)*100 + score[i].second;
                cnt += score[i].first;
            }
        }

        if(G<=sum){
            ans = min(ans, cnt);
            continue;
        }

        REPR(i,D-1){
            if(S[i]==1) continue;
            REP(j,score[i].first){
                sum += 100*(i+1);
                cnt++;


                if(G<=sum){
                    ans = min(ans, cnt);
                    continue;
                }
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}